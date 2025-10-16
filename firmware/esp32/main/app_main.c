#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "pitter_o_mat";

void app_main(void)
{
    ESP_LOGI(TAG, "ESP32 main firmware scaffold running.");

    while (true) {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
