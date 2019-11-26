#ifndef EXT_EEPROM_H
#define EXT_EEPROM_H

extern stdReturnType_t EXT_EEPROM_Write_Byte(u16 address,u8 data);
extern stdReturnType_t EXT_EEPROM_Read_Byte(u16 address,u8 * data);


#endif