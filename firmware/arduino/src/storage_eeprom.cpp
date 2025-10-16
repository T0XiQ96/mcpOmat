#include "storage_eeprom.h"

#include <EEPROM.h>

void storage_eeprom_begin()
{
    EEPROM.begin();
}

void storage_eeprom_write(uint16_t address, const uint8_t *data, size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        EEPROM.write(address + i, data[i]);
    }
    EEPROM.commit();
}

void storage_eeprom_read(uint16_t address, uint8_t *data, size_t length)
{
    for (size_t i = 0; i < length; ++i) {
        data[i] = EEPROM.read(address + i);
    }
}
