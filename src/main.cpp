// ESP32_PitterOmat_RS485.ino
// ESP32-S3 Touch LCD 4 (480x480) + LVGL + EEZ Flow + RS485 Master
// Backlight: Board-Hardware (keine explizite TCA9554-Steuerung).
// LVGL: Single-Buffer, damit keine "LVGL buffer alloc failed" Fehler auftreten.

#include <lvgl.h>
#include "Arduino_GFX_Library.h"
#include "TouchDrvGT911.hpp"
#include <Wire.h>
#include <math.h>
#include "esp_timer.h"
#include "settings_store.h"
#include <ctype.h>

#if defined(ARDUINO_USB_MODE) && (ARDUINO_USB_MODE == 1)
#include "HWCDC.h"
#define USBSerial HWCDCSerial
#define USE_NATIVE_USB 1
#elif defined(ARDUINO_USB_MODE) && (ARDUINO_USB_MODE == 0)
#include "USB.h"
#define USE_NATIVE_USB 1
#else
#define USBSerial Serial
#define USE_NATIVE_USB 0
#endif

#if LV_USE_LOG
static void lvlog_cb(const char *s) { USBSerial.printf("%s", s); USBSerial.flush(); }
#endif

// --- EEZ / UI ---
#include "ui.h"
#include "vars.h"
#include "eez-flow.h"
#include "actions.h"

extern "C" __attribute__((weak)) void eez_flow_tick(void) {}
extern "C" __attribute__((weak)) void ui_tick(void) {}

#define LVGL_TICK_PERIOD_MS 2

#ifndef DISPLAY_ID
  #define DISPLAY_ID 1
#endif

// --- Arduino_GFX: Bus + RGB Panel + Display ---
Arduino_DataBus *bus = new Arduino_SWSPI(
  GFX_NOT_DEFINED /* DC */, 42 /* CS */,
  2 /* SCK */, 1 /* MOSI */, GFX_NOT_DEFINED /* MISO */);

Arduino_ESP32RGBPanel *rgbpanel = new Arduino_ESP32RGBPanel(
  40 /* DE */, 39 /* VSYNC */, 38 /* HSYNC */, 41 /* PCLK */,
  46 /* R0 */, 3 /* R1 */, 8 /* R2 */, 18 /* R3 */, 17 /* R4 */,
  14 /* G0 */, 13 /* G1 */, 12 /* G2 */, 11 /* G3 */, 10 /* G4 */, 9 /* G5 */,
  5 /* B0 */, 45 /* B1 */, 48 /* B2 */, 47 /* B3 */, 21 /* B4 */,
  1 /* hsync_polarity */, 10 /* hsync_front_porch */, 8 /* hsync_pulse_width */, 50 /* hsync_back_porch */,
  1 /* vsync_polarity */, 10 /* vsync_front_porch */, 8 /* vsync_pulse_width */, 20 /* vsync_back_porch */);

Arduino_RGB_Display *gfx = new Arduino_RGB_Display(
  480, 480, rgbpanel,
  2, false,  // auto_flush AUS
  bus, GFX_NOT_DEFINED,
  st7701_type1_init_operations, sizeof(st7701_type1_init_operations));

// --- Touch GT911 ---
TouchDrvGT911 GT911;
int16_t txs[5], tys[5];

// --- LVGL Draw Buffers (Single Buffer) ---
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *buf1 = nullptr;
static uint32_t screenWidth  = 0;
static uint32_t screenHeight = 0;

static String usbIn;

static void usbPoll() {
  while (USBSerial.available()) {
    char c = (char)USBSerial.read();
    if (c == '\r' || c == '\n') {
      if (usbIn.length()) {
        if (usbIn.equalsIgnoreCase("ping")) {
          USBSerial.println("pong");
        } else if (usbIn.equalsIgnoreCase("heap")) {
          USBSerial.printf("heap=%u psram=%u\n",
              heap_caps_get_free_size(MALLOC_CAP_INTERNAL),
              heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
        } else if (usbIn.equalsIgnoreCase("info")) {
          USBSerial.printf("IDF=%s, core freq=%uMHz\n", IDF_VER, F_CPU/1000000);
        }
      }
      usbIn = "";
    } else {
      if (usbIn.length() < 80) usbIn += c;
    }
  }
}

// --- LVGL flush ---
static void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  uint32_t w = area->x2 - area->x1 + 1;
  uint32_t h = area->y2 - area->y1 + 1;
#if (LV_COLOR_16_SWAP != 0)
  gfx->draw16bitBeRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#else
  gfx->draw16bitRGBBitmap(area->x1, area->y1, (uint16_t *)&color_p->full, w, h);
#endif
  lv_disp_flush_ready(disp);
}

// --- LVGL tick ISR ---
static void lvgl_tick_cb(void *arg) {
  (void)arg;
  lv_tick_inc(LVGL_TICK_PERIOD_MS);
}

// --- Touch -> LVGL ---
static void my_touchpad_read(lv_indev_drv_t *indev, lv_indev_data_t *data) {
  (void)indev;
  uint8_t n = GT911.getPoint(txs, tys, GT911.getSupportTouchPoint());
  if (n > 0) {
    int16_t x = txs[0], y = tys[0];
    switch (gfx->getRotation()) {
      case 0: break;
      case 1: {
        int16_t _x = y;
        int16_t _y = gfx->height() - x;
        x = _x; y = _y;
        break;
      }
      case 2:
        x = gfx->width()  - x;
        y = gfx->height() - y;
        break;
      case 3: {
        int16_t _x = gfx->width() - y;
        int16_t _y = x;
        x = _x; y = _y;
        break;
      }
    }
    data->state   = LV_INDEV_STATE_PRESSED;
    data->point.x = x;
    data->point.y = y;
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

// === RS485 Master (MAX485) ===================================================
constexpr uint32_t RS485_BAUD = 115200;
HardwareSerial &RS485 = Serial2;
constexpr int RS485_RX_PIN = 43;
constexpr int RS485_TX_PIN = 44;

static inline void rs485SendRaw(const uint8_t *data, size_t len) {
  RS485.write(data, len);
  RS485.flush();
}

static void logRs485Line(const char *prefix, const char *line, size_t len = 0) {
  if (!line) {
    return;
  }
  if (len == 0) {
    len = strlen(line);
  }
  while (len && (line[len - 1] == '\r' || line[len - 1] == '\n')) {
    --len;
  }
  USBSerial.print(prefix);
  if (len) {
    USBSerial.write(reinterpret_cast<const uint8_t *>(line), len);
  }
  USBSerial.println();
}
static void logRs485Line(const char *prefix, const String &line) {
  logRs485Line(prefix, line.c_str(), line.length());
}

void rs485SendLine(const char *line) {
  if (!line) {
    return;
  }
  logRs485Line("[RS485-TX] ", line);
  rs485SendRaw((const uint8_t*)line, strlen(line));
}

// === RS485 RX Parser =========================================================
String rsInLine;
static void handleRs485Line(const String &line);

static void rs485Poll() {
  while (RS485.available()) {
    int b = RS485.read();
    char c = (char)b;

    // Roh-Log zum Debuggen
    USBSerial.printf("[RS485-BYTE] 0x%02X '%c'\n",
                     b,
                     isprint(c) ? c : '.');

    if (c == '\n') {
      if (rsInLine.length() > 0) {
        logRs485Line("[RS485-RX] ", rsInLine);
        handleRs485Line(rsInLine);
      }
      rsInLine = "";
    } else if (c != '\r') {
      rsInLine += c;
      if (rsInLine.length() > 80) {
        rsInLine = "";
      }
    }
  }
}

// === Helper fÃ¼r EEZ Globals ==================================================
static inline int32_t gv_i(unsigned idx) {
  int err = 0;
  eez::Value v = eez::flow::getGlobalVariable(idx);
  return v.toInt32(&err);
}
static inline bool gv_b(unsigned idx) {
  int err = 0;
  eez::Value v = eez::flow::getGlobalVariable(idx);
  return v.toBool(&err);
}

// === LichtLoser Spin-Engine (ESP-seitig) =====================================

struct LichtLoserSpinState {
  bool active;
  bool hitPublished;
  uint32_t spinEndMs;
  uint32_t buttonEnableMs;
  uint8_t currentGroup; // 1..36
};

static LichtLoserSpinState g_llSpinState = { false, false, 0, 0, 1 };
static bool g_llScoreLogInit = false;
static int32_t g_llLastScores[6] = {0, 0, 0, 0, 0, 0};

static uint32_t llClampToRange(uint32_t value, uint32_t minVal, uint32_t maxVal) {
  if (value < minVal) {
    return minVal;
  }
  if (value > maxVal) {
    return maxVal;
  }
  return value;
}

static void lichtLoserPublishHit(uint8_t hitGroup) {
  if (hitGroup < 1) {
    hitGroup = 1;
  } else if (hitGroup > 36) {
    hitGroup = 36;
  }

  eez::flow::setGlobalVariable(
    FLOW_GLOBAL_VARIABLE_HIT_GROUP,
    eez::IntegerValue(static_cast<int32_t>(hitGroup))
  );

  int err = 0;
  int32_t oldTrig = eez::flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_HIT_TRIGGER).toInt32(&err);
  if (err != 0) {
    oldTrig = 0;
  }
  eez::flow::setGlobalVariable(
    FLOW_GLOBAL_VARIABLE_HIT_TRIGGER,
    eez::IntegerValue(oldTrig + 1)
  );
}

static void lichtLoserResetSpinState() {
  g_llSpinState.active = false;
  g_llSpinState.hitPublished = false;
  g_llSpinState.spinEndMs = 0;
  g_llSpinState.buttonEnableMs = 0;
  if (g_llSpinState.currentGroup < 1 || g_llSpinState.currentGroup > 36) {
    g_llSpinState.currentGroup = 1;
  }
}

static void lichtLoserInit() {
  lichtLoserResetSpinState();
  eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SPIN_IN_PROGRESS, eez::IntegerValue(0));
  eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_CAN_START_SPIN, eez::IntegerValue(1));
  g_llScoreLogInit = false;
}

static bool lichtLoserPlanSpin(uint8_t startGroup,
                               char *cmdBuf,
                               size_t cmdBufSize,
                               uint32_t &totalDurationMs,
                               uint8_t &finalGroupOut) {
  if (!cmdBuf || cmdBufSize == 0) {
    return false;
  }

  int aMin = gv_i(FLOW_GLOBAL_VARIABLE_LL_ACCEL_TURNS_MIN10);
  int aMax = gv_i(FLOW_GLOBAL_VARIABLE_LL_ACCEL_TURNS_MAX10);
  int mMin = gv_i(FLOW_GLOBAL_VARIABLE_LL_MAX_SPEED_TURNS_MIN10);
  int mMax = gv_i(FLOW_GLOBAL_VARIABLE_LL_MAX_SPEED_TURNS_MAX10);
  int dMin = gv_i(FLOW_GLOBAL_VARIABLE_LL_DECEL_TURNS_MIN10);
  int dMax = gv_i(FLOW_GLOBAL_VARIABLE_LL_DECEL_TURNS_MAX10);
  int stepMs = gv_i(FLOW_GLOBAL_VARIABLE_LL_STEP_MS);

  if (stepMs <= 0) {
    stepMs = 20;
  }

  if (aMax < aMin) aMax = aMin;
  if (mMax < mMin) mMax = mMin;
  if (dMax < dMin) dMax = dMin;

  auto randTurns = [](int min10, int max10) -> float {
    if (max10 < min10) {
      max10 = min10;
    }
    long r = random(min10, max10 + 1);
    return r / 10.0f;
  };

  float accelTurns = randTurns(aMin, aMax);
  float maxTurns   = randTurns(mMin, mMax);
  float decelTurns = randTurns(dMin, dMax);

  if (accelTurns < 0.1f) accelTurns = 0.1f;
  if (maxTurns   < 0.1f) maxTurns   = 0.1f;
  if (decelTurns < 0.1f) decelTurns = 0.1f;

  uint16_t accelSteps = static_cast<uint16_t>(accelTurns * 36.0f);
  uint16_t maxSteps   = static_cast<uint16_t>(maxTurns   * 36.0f);
  uint16_t decelSteps = static_cast<uint16_t>(decelTurns * 36.0f);

  uint32_t totalSteps = static_cast<uint32_t>(accelSteps) + maxSteps + decelSteps;
  if (totalSteps == 0) {
    totalSteps = 36;
  }

  int dir = random(0, 2) ? 1 : -1;

  if (startGroup < 1 || startGroup > 36) {
    startGroup = 1;
  }
  uint8_t startIndex = static_cast<uint8_t>(startGroup - 1); // 0..35

  int32_t signedOffset = dir * static_cast<int32_t>(totalSteps % 36);
  int32_t idx = static_cast<int32_t>(startIndex) + signedOffset;
  while (idx < 0) {
    idx += 36;
  }
  while (idx >= 36) {
    idx -= 36;
  }
  uint8_t finalGroup = static_cast<uint8_t>(idx + 1); // 1..36

  totalDurationMs = 0;
  const float kExpo = 3.0f;
  const float expoNorm = 1.0f - expf(-kExpo);
  for (uint32_t step = 0; step < totalSteps; ++step) {
    float fDelay = 1.0f;
    if (step < accelSteps && accelSteps > 0) {
      float k = static_cast<float>(step) / static_cast<float>(accelSteps);
      float decay = expf(-kExpo * k);
      fDelay = 0.5f + decay;
    } else if (step < static_cast<uint32_t>(accelSteps) + maxSteps) {
      fDelay = 0.5f;
    } else if (decelSteps > 0) {
      uint32_t decelIndex = step - accelSteps - maxSteps;
      float k = static_cast<float>(decelIndex) / static_cast<float>(decelSteps);
      float rise = (1.0f - expf(-kExpo * k)) / (expoNorm > 0.0f ? expoNorm : 1.0f);
      fDelay = 0.5f + rise * 1.5f;
    }
    uint32_t stepDelay = static_cast<uint32_t>(stepMs * fDelay);
    stepDelay = llClampToRange(stepDelay, 1, 2000);
    totalDurationMs += stepDelay;
  }

  uint16_t blinkMs = static_cast<uint16_t>(stepMs * 2);
  blinkMs = static_cast<uint16_t>(llClampToRange(blinkMs, 80, 500));

  int written = snprintf(cmdBuf, cmdBufSize,
                         "LL_SPIN %u %u %u %u %d %u %u\n",
                         static_cast<unsigned>(startGroup),
                         static_cast<unsigned>(accelSteps),
                         static_cast<unsigned>(maxSteps),
                         static_cast<unsigned>(decelSteps),
                         dir,
                         static_cast<unsigned>(stepMs),
                         static_cast<unsigned>(blinkMs));
  if (written <= 0 || static_cast<size_t>(written) >= cmdBufSize) {
    return false;
  }

  finalGroupOut = finalGroup;
  return true;
}

static void lichtLoserUpdate() {
  if (!g_llSpinState.active && g_llSpinState.buttonEnableMs == 0) {
    return;
  }

  uint32_t now = millis();

  if (g_llSpinState.active && now >= g_llSpinState.spinEndMs) {
    g_llSpinState.active = false;
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SPIN_IN_PROGRESS, eez::IntegerValue(0));
    if (!g_llSpinState.hitPublished) {
      g_llSpinState.hitPublished = true;
      lichtLoserPublishHit(g_llSpinState.currentGroup);
    }
  }

  if (!g_llSpinState.active && g_llSpinState.buttonEnableMs != 0 && now >= g_llSpinState.buttonEnableMs) {
    eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_CAN_START_SPIN, eez::IntegerValue(1));
    g_llSpinState.buttonEnableMs = 0;
  }
}

static void lichtLoserScoreLogUpdate() {
  static const unsigned kScoreGlobals[6] = {
      FLOW_GLOBAL_VARIABLE_SCORE_P1,
      FLOW_GLOBAL_VARIABLE_SCORE_P2,
      FLOW_GLOBAL_VARIABLE_SCORE_P3,
      FLOW_GLOBAL_VARIABLE_SCORE_P4,
      FLOW_GLOBAL_VARIABLE_SCORE_P5,
      FLOW_GLOBAL_VARIABLE_SCORE_P6};

  int32_t scores[6];
  bool resetDetected = false;
  for (int i = 0; i < 6; ++i) {
    scores[i] = gv_i(kScoreGlobals[i]);
    if (g_llScoreLogInit && scores[i] > g_llLastScores[i]) {
      resetDetected = true;
    }
  }

  if (!g_llScoreLogInit || resetDetected) {
    for (int i = 0; i < 6; ++i) {
      g_llLastScores[i] = scores[i];
    }
    g_llScoreLogInit = true;
    return;
  }

  int modeWinLose    = gv_i(FLOW_GLOBAL_VARIABLE_MODE_WIN_LOSE);
  int resultIndex    = gv_i(FLOW_GLOBAL_VARIABLE_RESULT_INDEX);
  int mySeatIndex    = gv_i(FLOW_GLOBAL_VARIABLE_MY_SEAT_INDEX);
  int isResultPlayer = gv_i(FLOW_GLOBAL_VARIABLE_IS_RESULT_PLAYER);

  for (int i = 0; i < 6; ++i) {
    if (g_llLastScores[i] > 0 && scores[i] <= 0) {
      USBSerial.printf("[LL] Player %d score %ld -> %ld (mode=%d result=%d seat=%d isResult=%d)\n",
                       i + 1,
                       static_cast<long>(g_llLastScores[i]),
                       static_cast<long>(scores[i]),
                       modeWinLose,
                       resultIndex,
                       mySeatIndex,
                       isResultPlayer);
    }
    g_llLastScores[i] = scores[i];
  }
}
// === Native Actions (RS485-Befehle) ==========================================
extern "C" void action_cmd_led_ring_test(lv_event_t *e) {
  (void)e;
  rs485SendLine("LED_TEST\n");
}

extern "C" void action_cmd_send_spin_start_to_arduino(lv_event_t *e) {
  (void)e;
  if (g_llSpinState.active) {
    return;
  }
  uint32_t now = millis();
  if (g_llSpinState.buttonEnableMs != 0 && now < g_llSpinState.buttonEnableMs) {
    return;
  }

  char buf[96];
  uint32_t totalMs = 0;
  uint8_t finalGroup = g_llSpinState.currentGroup;
  if (!lichtLoserPlanSpin(g_llSpinState.currentGroup, buf, sizeof(buf), totalMs, finalGroup)) {
    return;
  }

  // Stop UI hit blink when starting a new spin
  eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_HIT_BLINK_ACTIVE, eez::BooleanValue(false));
  eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_HIT_BLINK_PHASE, eez::BooleanValue(false));

  rs485SendLine(buf);

  g_llSpinState.active = true;
  g_llSpinState.hitPublished = false;
  g_llSpinState.spinEndMs = now + totalMs;
  g_llSpinState.buttonEnableMs = g_llSpinState.spinEndMs + 2000;
  g_llSpinState.currentGroup = finalGroup;

  eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_SPIN_IN_PROGRESS, eez::IntegerValue(1));
  eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_CAN_START_SPIN, eez::IntegerValue(0));
}

extern "C" void action_cmd_send_joker_start_to_arduino(lv_event_t *e) {
  (void)e;
  rs485SendLine("JOKER:PREVIEW:START\n");
}

extern "C" void action_cmd_send_joker_stop_to_arduino(lv_event_t *e) {
  (void)e;
  rs485SendLine("JOKER:PREVIEW:STOP\n");
}

extern "C" void action_cmd_send_joker_preview(lv_event_t *e) {
  (void)e;
  // Korrigiert: nutze jokerColorIndex statt jokerColorModeId
  int mode     = gv_i(FLOW_GLOBAL_VARIABLE_JOKER_COLOR_INDEX);
  int colorIdx = gv_i(FLOW_GLOBAL_VARIABLE_JOKER_COLOR_INDEX);
  char buf[64];
  snprintf(buf, sizeof(buf), "JOKER_PREVIEW %d %d\n", mode, colorIdx);
  rs485SendLine(buf);
}

extern "C" void action_cmd_send_player_colors_preview(lv_event_t *e) {
  (void)e;
  // Korrigiert: verwende INDEX-Variablen fÃ¼r Modus und Farbe
  int mode        = gv_i(FLOW_GLOBAL_VARIABLE_PLAYER_COLOR_MODE_INDEX);
  int singleIndex = gv_i(FLOW_GLOBAL_VARIABLE_PLAYER_SINGLE_COLOR_INDEX);
  int ownRandom   = gv_i(FLOW_GLOBAL_VARIABLE_PLAYER_OWN_COLOR_FLAG);
  int inactiveIdx = gv_i(FLOW_GLOBAL_VARIABLE_INACTIVE_EFFECT_INDEX);
  char buf[96];
  snprintf(buf, sizeof(buf), "PLAYER_PREVIEW %d %d %d %d\n",
           mode, singleIndex, ownRandom, inactiveIdx);
  rs485SendLine(buf);
}

extern "C" void action_cmd_send_border_colors_preview(lv_event_t *e) {
  (void)e;
  // Korrigiert: verwende INDEX-Variablen fÃ¼r Grenzmodus und -farbe
  int mode        = gv_i(FLOW_GLOBAL_VARIABLE_BORDER_COLOR_MODE_INDEX);
  int singleIndex = gv_i(FLOW_GLOBAL_VARIABLE_BORDER_SINGLE_COLOR_INDEX);
  char buf[64];
  snprintf(buf, sizeof(buf), "BORDER_PREVIEW %d %d\n", mode, singleIndex);
  rs485SendLine(buf);
}

extern "C" void action_cmd_send_borders_state_to_arduino(lv_event_t *e) {
  (void)e;
  bool on = gv_b(FLOW_GLOBAL_VARIABLE_LL_SHOW_BORDERS);
  int  pc = gv_i(FLOW_GLOBAL_VARIABLE_PLAYER_COUNT);
  char buf[48];
  snprintf(buf, sizeof(buf), "BORDERS_STATE %d %d\n", on ? 1 : 0, pc);
  rs485SendLine(buf);
}

extern "C" void action_cmd_send_led_game_brightness(lv_event_t *e) {
  (void)e;
  int v = gv_i(FLOW_GLOBAL_VARIABLE_LED_GAME_BRIGHTNESS);
  if (v < 1) v = 1;
  if (v > 255) v = 255;
  char buf[40];
  snprintf(buf, sizeof(buf), "SET_BRIGHTNESS G %d\n", v);
  rs485SendLine(buf);
}

extern "C" void action_cmd_send_led_border_brightness(lv_event_t *e) {
  (void)e;
  int v = gv_i(FLOW_GLOBAL_VARIABLE_LED_BORDER_BRIGHTNESS);
  if (v < 1) v = 1;
  if (v > 255) v = 255;
  char buf[40];
  snprintf(buf, sizeof(buf), "SET_BRIGHTNESS B %d\n", v);
  rs485SendLine(buf);
}

// Display-Brightness-Slider: NO-OP (nicht verwendet)
extern "C" void action_cmd_set_display_brightness(lv_event_t *e) {
  (void)e;
}

// Spielende / Preview-Clear
extern "C" void action_cmd_send_game_end(lv_event_t *e) {
  (void)e;
  rs485SendLine("GAME_END\n");
}

extern "C" void action_cmd_send_preview_clear(lv_event_t *e) {
  (void)e;
  rs485SendLine("PREVIEW_CLEAR\n");
}

// Spin-Parameter senden
extern "C" void action_cmd_send_spin_params_to_arduino(lv_event_t *e) {
  (void)e;
  int aMin = gv_i(FLOW_GLOBAL_VARIABLE_LL_ACCEL_TURNS_MIN10);
  int aMax = gv_i(FLOW_GLOBAL_VARIABLE_LL_ACCEL_TURNS_MAX10);
  int mMin = gv_i(FLOW_GLOBAL_VARIABLE_LL_MAX_SPEED_TURNS_MIN10);
  int mMax = gv_i(FLOW_GLOBAL_VARIABLE_LL_MAX_SPEED_TURNS_MAX10);
  int dMin = gv_i(FLOW_GLOBAL_VARIABLE_LL_DECEL_TURNS_MIN10);
  int dMax = gv_i(FLOW_GLOBAL_VARIABLE_LL_DECEL_TURNS_MAX10);
  int ms   = gv_i(FLOW_GLOBAL_VARIABLE_LL_STEP_MS);

  char buf[80];
  snprintf(buf, sizeof(buf),
           "SPIN_PARAMS %d %d %d %d %d %d %d\n",
           aMin, aMax, mMin, mMax, dMin, dMax, ms);
  rs485SendLine(buf);
}

// === LVGL / Display Init =====================================================
static void init_lvgl() {
  lv_init();
#if LV_USE_LOG
  lv_log_register_print_cb(lvlog_cb);
#endif

screenWidth  = gfx->width();
screenHeight = gfx->height();

/* statt 1/10 Frame: ~80 Zeilen */
size_t px_cnt = screenWidth * 80;  // 480 * 80 = 38.4k Pixel -> 76.8 kB
  buf1 = (lv_color_t *)heap_caps_malloc(px_cnt * sizeof(lv_color_t), MALLOC_CAP_DMA);
  if (!buf1) {
    USBSerial.println("LVGL DMA buffer alloc failed, fallback to smaller");
    px_cnt = screenWidth * 40;
    buf1 = (lv_color_t *)heap_caps_malloc(px_cnt * sizeof(lv_color_t), MALLOC_CAP_DMA);
  }
  if (!buf1) {
    while (true) { USBSerial.println("LVGL buffer alloc failed"); delay(1000); }
  }
  
lv_disp_draw_buf_init(&draw_buf, buf1, NULL, px_cnt);

static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res   = screenWidth;
  disp_drv.ver_res   = screenHeight;
  disp_drv.flush_cb  = my_disp_flush;
  disp_drv.draw_buf  = &draw_buf;
  disp_drv.full_refresh = 1;   // kompletter Frame â†’ weniger sichtbare Tearing/Jitter
  disp_drv.sw_rotate = 1;
  lv_disp_drv_register(&disp_drv);
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type    = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  const esp_timer_create_args_t tick_args = {
    .callback = &lvgl_tick_cb,
    .arg = nullptr,
    .dispatch_method = ESP_TIMER_TASK,
    .name = "lvgl_tick"
  };
  esp_timer_handle_t tick = nullptr;
  esp_timer_create(&tick_args, &tick);
  esp_timer_start_periodic(tick, LVGL_TICK_PERIOD_MS * 1000);
}

// === RS485 RX Line Handler ===================================================
static void handleRs485Line(const String &line) {
  (void)line;
  // Mega liefert aktuell keine Rckmeldungen; Platzhalter fr sptere Protokoll-Erweiterungen.
}

// === setup / loop ============================================================
void setup() {
  USBSerial.begin(115200);
  uint32_t waitStart = millis();
#if USE_NATIVE_USB
  while (!USBSerial && millis() - waitStart < 2000) {
    delay(10);
  }
#endif
  delay(300);
  USBSerial.println("PitterOmat ESP32-S3 + EEZ + RS485 (single buffer, no TCA BL) boot");

  randomSeed((uint32_t)esp_timer_get_time());

  // Touch I2C0 (GT911)
  Wire.begin(15, 7);
  GT911.setPins(-1, 16);
  if (!GT911.begin(Wire, GT911_SLAVE_ADDRESS_L, 15, 7)) {
    USBSerial.println("GT911 not found");
  } else {
    GT911.setMaxTouchPoint(1);
  }

  // Display
  gfx->begin();
  init_lvgl();

  // EEZ / UI
  ui_init();
  eez::flow::setGlobalVariable(FLOW_GLOBAL_VARIABLE_DISPLAY_ID, eez::IntegerValue(DISPLAY_ID));

  // RS485
  RS485.begin(RS485_BAUD, SERIAL_8N1, RS485_RX_PIN, RS485_TX_PIN);

  lichtLoserInit();
}

void loop() {
  lv_timer_handler();
  eez_flow_tick();
  ui_tick();
  rs485Poll();
  usbPoll();
  lichtLoserUpdate();
  lichtLoserScoreLogUpdate();
  delay(5);
}
