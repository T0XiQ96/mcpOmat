#pragma once

#include "esp_err.h"

esp_err_t storage_config_mount(void);
void storage_config_unmount(void);
const char *storage_config_root(void);
