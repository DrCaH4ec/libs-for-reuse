#include "eeprom.h"

void eeprom_write_1_byte(uint8_t uiAddress, uint8_t ucData)
{
        /* Wait for completion of previous write */
        while(EECR & (1<<EEPE));
        /* Set up address and Data Registers */
        EEAR = uiAddress;
        EEDR = ucData;
        /* Write logical one to EEMPE */
        EECR |= (1<<EEMPE);
        /* Start eeprom write by setting EEPE */
        EECR |= (1<<EEPE);
}

//-----------------------------------------------------------------------------

uint8_t eeprom_read_1_byte(uint8_t uiAddress)
{
        /* Wait for completion of previous write */
        while(EECR & (1<<EEPE));
        /* Set up address register */
        EEAR = uiAddress;
        /* Start eeprom read by writing EERE */
        EECR |= (1<<EERE);
        /* Return data from Data Register */
        return EEDR;
}

//-----------------------------------------------------------------------------

uint16_t inline eeprom_read_2_bytes(uint8_t uiAddress)
{
        return eeprom_read_byte(uiAddress) | eeprom_read_byte(uiAddress + 1);
}

//-----------------------------------------------------------------------------

uint32_t inline eeprom_read_4_bytes(uint8_t uiAddress)
{
        return eeprom_read_2_bytes(uiAddress) | eeprom_read_2_bytes(uiAddress + 2);
}

//-----------------------------------------------------------------------------

uint64_t inline eeprom_read_8_bytes(uint8_t uiAddress)
{
        return eeprom_read_4_bytes(uiAddress) | eeprom_read_4_bytes(uiAddress + 4);
}

//-----------------------------------------------------------------------------

void inline eeprom_write_2_bytes(uint8_t uiAddress, uint16_t ucData)
{
        eeprom_write_byte(uiAddress, (uint8_t)ucData) | 
        eeprom_write_byte(uiAddress + 1, (uint8_t)(ucData>>8));
}

//-----------------------------------------------------------------------------

void inline eeprom_write_4_bytes(uint8_t uiAddress, uint32_t ucData)
{
        eeprom_write_2_bytes(uiAddress, (uint16_t)ucData) | 
        eeprom_write_2_bytes(uiAddress + 2, (uint16_t)(ucData>>16));
}

//-----------------------------------------------------------------------------

void inline eeprom_write_8_bytes(uint8_t uiAddress, uint64_t ucData)
{
        eeprom_write_4_bytes(uiAddress, (uint32_t)ucData) | 
        eeprom_write_4_bytes(uiAddress + 4, (uint32_t)(ucData>>32));
}
