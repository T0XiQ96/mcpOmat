// ESP32_PitterOmat_RS485.ino
// ESP32-S3 Touch LCD 4 (480x480) + LVGL + EEZ Flow + RS485 Master
// Backlight: Board-Hardware (keine explizite TCA9554-Steuerung).
// LVGL: Single-Buffer, damit keine "LVGL buffer alloc failed" Fehler auftreten.

#include <lvgl.h>
#include "Arduino_GFX_Library.h"
#include "TouchDrvGT911.hpp"
#include <Wire.h>
#include "esp_timer.h"

#define USBSerial Serial

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
constexpr int RS485_DE_PIN = 4;

static inline void rs485SendRaw(const uint8_t *data, size_t len) {
  digitalWrite(RS485_DE_PIN, HIGH);
  delayMicroseconds(10);
  RS485.write(data, len);
  RS485.flush();
  delayMicroseconds(20);
  digitalWrite(RS485_DE_PIN, LOW);
}
void rs485SendLine(const char *line) {
  rs485SendRaw((const uint8_t*)line, strlen(line));
}

// === RS485 RX Parser =========================================================
String rsInLine;
static void handleRs485Line(const String &line);

static void rs485Poll() {
  while (RS485.available()) {
    char c = (char)RS485.read();
    if (c == '\n') {
      if (rsInLine.length() > 0) {
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

// === Helper für EEZ Globals ==================================================
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

// === Native Actions (RS485-Befehle) ==========================================
extern "C" void action_cmd_led_ring_test(lv_event_t *e) {
  (void)e;
  rs485SendLine("LED_TEST\n");
}

extern "C" void action_cmd_send_spin_start_to_arduino(lv_event_t *e) {
  (void)e;
  rs485SendLine("SPIN_START\n");
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
  // Korrigiert: verwende INDEX-Variablen für Modus und Farbe
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
  // Korrigiert: verwende INDEX-Variablen für Grenzmodus und -farbe
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

  // Single Buffer: ca. 1/10 Frame
  size_t px_cnt = (screenWidth * screenHeight) / 10;
  buf1 = (lv_color_t *)heap_caps_malloc(px_cnt * sizeof(lv_color_t), MALLOC_CAP_DMA);
  if (!buf1) {
    while (true) {
      USBSerial.println("LVGL buffer alloc failed");
      delay(1000);
    }
  }
  lv_disp_draw_buf_init(&draw_buf, buf1, NULL, px_cnt);

  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res   = screenWidth;
  disp_drv.ver_res   = screenHeight;
  disp_drv.flush_cb  = my_disp_flush;
  disp_drv.draw_buf  = &draw_buf;
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
  USBSerial.print("RS485 RX: ");
  USBSerial.println(line);

  // HIT n -> hitGroup setzen + hitTrigger++ für EEZ-Flow
  if (line.startsWith("HIT ")) {
    int grp = atoi(line.c_str() + 4);
    if (grp < 1) grp = 1;
    if (grp > 36) grp = 36;

    // hitGroup setzen
    eez::flow::setGlobalVariable(
        FLOW_GLOBAL_VARIABLE_HIT_GROUP,
        eez::IntegerValue(grp)
    );

    // hitTrigger inkrementieren (für Poll-Flow in EEZ)
    int err = 0;
    int32_t oldTrig = eez::flow::getGlobalVariable(FLOW_GLOBAL_VARIABLE_HIT_TRIGGER).toInt32(&err);
    if (err != 0) oldTrig = 0;
    eez::flow::setGlobalVariable(
        FLOW_GLOBAL_VARIABLE_HIT_TRIGGER,
        eez::IntegerValue(oldTrig + 1)
    );

    USBSerial.printf("HIT-Gruppe gesetzt: %d\n", grp);
    return;
  }

  // weitere Rückmeldungen kannst du hier später auswerten
}

// === setup / loop ============================================================
void setup() {
  USBSerial.begin(115200);
  delay(50);
  USBSerial.println("PitterOmat ESP32-S3 + EEZ + RS485 (single buffer, no TCA BL) boot");

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
  pinMode(RS485_DE_PIN, OUTPUT);
  digitalWrite(RS485_DE_PIN, LOW);
  RS485.begin(RS485_BAUD, SERIAL_8N1, RS485_RX_PIN, RS485_TX_PIN);
}

void loop() {
  lv_timer_handler();
  eez_flow_tick();
  ui_tick();
  rs485Poll();
  delay(5);
}
