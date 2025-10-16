#pragma once

#include <Arduino.h>

void storage_eeprom_begin();
void storage_eeprom_write(uint16_t address, const uint8_t *data, size_t length);
void storage_eeprom_read(uint16_t address, uint8_t *data, size_t length);
