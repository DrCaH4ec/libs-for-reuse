#ifndef _EEPROM_H_
#define _EEPROM_H_


#include <avr/io.h>
#include <avr/eeprom.h>
#include <stdint.h>


void eeprom_write_1_byte(uint8_t uiAddress, uint8_t ucData);

uint8_t eeprom_read_1_byte(uint8_t uiAddress);

uint16_t inline eeprom_read_2_bytes(uint8_t uiAddress);

uint32_t inline eeprom_read_4_bytes(uint8_t uiAddress);

uint64_t inline eeprom_read_8_bytes(uint8_t uiAddress);

void inline eeprom_write_2_bytes(uint8_t uiAddress, uint16_t ucData);

void inline eeprom_write_4_bytes(uint8_t uiAddress, uint32_t ucData);

void inline eeprom_write_8_bytes(uint8_t uiAddress, uint64_t ucData);

/*_EEPROM_H_*/
#endif
