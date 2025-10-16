// === PitterOmat LVGL 8 + Waveshare ESP32-S3-Touch-LCD-4 (480x480) ===
// Display: Arduino_GFX (RGB Panel + ST7701), Touch: GT911 (I2C), GUI: LVGL 8 + EEZ Flow
// Lege deinen kompletten EEZ-Export als Ordner "ui/" NEBEN diese .ino
// (oder als Arduino-Library "ui"). WICHTIG: keine ui.ino mitkompilieren!

#include <lvgl.h>
#include "Arduino_GFX_Library.h"
#include "TouchDrvGT911.hpp"
#include <Wire.h>
#include "esp_timer.h"

#include "HWCDC.h"
HWCDC USBSerial;

#if LV_USE_LOG
static void lvlog_cb(const char *s) { Serial.printf("%s", s); Serial.flush(); }
#endif

// --- EEZ / UI (bei EEZ Flow KEIN extern "C"!) ---
#include "ui.h"         // kommt aus deinem Export
#include "eez-flow.h"   // liefert u.a. eez_flow_tick()

// Fallback-Stubs (werden überschrieben, falls echte Funktionen vorhanden sind)
extern "C" __attribute__((weak)) void eez_flow_tick(void) {}
extern "C" __attribute__((weak)) void ui_tick(void) {}

#define LVGL_TICK_PERIOD_MS 2

// --- Arduino_GFX: Bus + RGB Panel + Display (Pins/Timings wie in deiner funktionierenden INO) ---
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
  480 /* width */, 480 /* height */, rgbpanel,
  2 /* rotation */, true /* auto_flush */,
  bus, GFX_NOT_DEFINED /* RST */,
  st7701_type1_init_operations, sizeof(st7701_type1_init_operations));

// --- Touch GT911 ---
TouchDrvGT911 GT911;
int16_t txs[5], tys[5];

// --- LVGL Draw Buffers ---
static lv_disp_draw_buf_t draw_buf;
static lv_color_t *buf1 = nullptr;
static lv_color_t *buf2 = nullptr;

static uint32_t screenWidth = 0, screenHeight = 0;

// --- LVGL flush: LVGL -> Panel ---
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
static void lvgl_tick_cb(void *arg) { lv_tick_inc(LVGL_TICK_PERIOD_MS); }

// --- Touch -> LVGL ---
static void my_touchpad_read(lv_indev_drv_t *indev, lv_indev_data_t *data) {
  uint8_t n = GT911.getPoint(txs, tys, GT911.getSupportTouchPoint());
  if (n > 0) {
    int16_t x = txs[0], y = tys[0];
    switch (gfx->getRotation()) {
      case 0: break;
      case 1: { int16_t _x = y;                int16_t _y = gfx->height() - x; x = _x; y = _y; } break;
      case 2: x = gfx->width()  - x;           y = gfx->height() - y; break;
      case 3: { int16_t _x = gfx->width() - y; int16_t _y = x;         x = _x; y = _y; } break;
    }
    data->state   = LV_INDEV_STATE_PRESSED;
    data->point.x = x;
    data->point.y = y;
  } else {
    data->state = LV_INDEV_STATE_RELEASED;
  }
}

void setup() {
  USBSerial.begin(115200);
  delay(50);
  USBSerial.println("PitterOmat (EEZ Flow) boot...");

  // I2C: Waveshare ESP32-S3 Touch-LCD-4 (SDA=15, SCL=7)
  Wire.begin(15, 7);
  GT911.setPins(-1, 16); // (RST=-1 nicht genutzt, INT=16)
  if (!GT911.begin(Wire, GT911_SLAVE_ADDRESS_L, 15, 7)) {
    while (true) { USBSerial.println("GT911 not found!"); delay(1000); }
  }
  GT911.setMaxTouchPoint(1);

  // Display
  gfx->begin();
  screenWidth  = gfx->width();
  screenHeight = gfx->height();

  // LVGL
  lv_init();
#if LV_USE_LOG
  lv_log_register_print_cb(lvlog_cb);
#endif

  // Draw-Buffers (¼ Screen), Fallback 1/8
  size_t px_cnt = (screenWidth * screenHeight) / 4;
  buf1 = (lv_color_t *)heap_caps_malloc(px_cnt * sizeof(lv_color_t), MALLOC_CAP_DMA);
  buf2 = (lv_color_t *)heap_caps_malloc(px_cnt * sizeof(lv_color_t), MALLOC_CAP_DMA);
  if (!buf1 || !buf2) {
    if (buf1) heap_caps_free(buf1);
    if (buf2) heap_caps_free(buf2);
    px_cnt = (screenWidth * screenHeight) / 8;
    buf1 = (lv_color_t *)heap_caps_malloc(px_cnt * sizeof(lv_color_t), MALLOC_CAP_DMA);
    buf2 = (lv_color_t *)heap_caps_malloc(px_cnt * sizeof(lv_color_t), MALLOC_CAP_DMA);
    if (!buf1 || !buf2) { while (true) { USBSerial.println("LVGL buffers alloc failed"); delay(1000); } }
  }
  lv_disp_draw_buf_init(&draw_buf, buf1, buf2, px_cnt);

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

  // LVGL Tick Timer (2 ms)
  const esp_timer_create_args_t tick_args = {
    .callback = &lvgl_tick_cb,
    .arg = nullptr,
    .dispatch_method = ESP_TIMER_TASK,
    .name = "lvgl_tick"
  };
  esp_timer_handle_t tick = nullptr;
  esp_timer_create(&tick_args, &tick);
  esp_timer_start_periodic(tick, LVGL_TICK_PERIOD_MS * 1000);

  // --- EEZ / UI Start ---
  ui_init();      // <- genügt; ruft bei den meisten EEZ-Exports intern eez_flow_init(...) mit den richtigen Parametern

  USBSerial.printf("Ready: %lux%lu rot=%d\n",
                   (unsigned long)screenWidth, (unsigned long)screenHeight, (int)gfx->getRotation());

  USBSerial.printf("Free heap: %u, DMA largest: %u, PSRAM: %u\n",
                  ESP.getFreeHeap(),
                  heap_caps_get_largest_free_block(MALLOC_CAP_INTERNAL|MALLOC_CAP_DMA),
                  ESP.getFreePsram());
}

void loop() {
  lv_timer_handler();  // LVGL engine
  // Mindestens eine der beiden Zeilen wird von deinem Export bereitgestellt:
  eez_flow_tick();     // EEZ Flow Takt (wenn vorhanden)
  ui_tick();           // EEZ UI/Flow Takt (wenn dein Export diese Funktion nutzt)
  delay(5);
}
