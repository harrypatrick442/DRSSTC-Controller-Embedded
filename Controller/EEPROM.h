/*
 * EEPROM.h
 *
 * Created: 20/11/2017 21:00:58
 *  Author: SoftwareEngineer
 */
 #include <stdio.h>
 void eeprom_write_byte1(uint16_t addr, uint8_t data);

uint8_t eeprom_read_byte1(uint16_t addr);

/*assumes s is a proper null terminated string*/

void eeprom_write_string(uint16_t addr, char *s);

/* read a string of len characters maximum starting at addr. 
 * modify according to your need!
 */
void eeprom_read_string(uint16_t addr, char *s, int len);