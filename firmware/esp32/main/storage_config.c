#include "storage_config.h"

#include "esp_log.h"
#include "esp_vfs_fat.h"
#include "wear_levelling.h"

#define STORAGE_MOUNT_POINT "/sdcard"

static const char *TAG = "storage_config";
static wl_handle_t s_wl_handle = WL_INVALID_HANDLE;

esp_err_t storage_config_mount(void)
{
    sdmmc_host_t host = SDMMC_HOST_DEFAULT();
    sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();
    esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = false,
        .max_files = 5,
        .allocation_unit_size = 16 * 1024,
    };
    sdmmc_card_t *card;
    esp_err_t ret = esp_vfs_fat_sdmmc_mount(STORAGE_MOUNT_POINT, &host, &slot_config, &mount_config, &card);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to mount SD card: %s", esp_err_to_name(ret));
        return ret;
    }
    ESP_LOGI(TAG, "SD card mounted");
    return ESP_OK;
}

void storage_config_unmount(void)
{
    esp_vfs_fat_sdcard_unmount(STORAGE_MOUNT_POINT, s_wl_handle);
    ESP_LOGI(TAG, "SD card unmounted");
}

const char *storage_config_root(void)
{
    return STORAGE_MOUNT_POINT;
}
