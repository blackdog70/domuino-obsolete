/*
 * eeconfig.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: sebastiano
 */

#include "eeconfig.h"

const char PASSWORD[] = "GloriaErikaSeba ";
const char start[] = "start\0";
int eeprom_write_counter;

char load_config() {
	char err = 0;

	if (first_run()) {
		firmware_config();
		save_config();
		err = 1;
	} else {
		unsigned long check_crc;
		unsigned long eeprom_crc;

		EEPROM.get(6, eeprom_crc);

		check_crc = crc((const char*)&input, sizeof(input));
		check_crc += crc((const char*)&output, sizeof(output));

		EEPROM.get(6 + sizeof(unsigned long), input);
		EEPROM.get(6 + sizeof(unsigned long) + sizeof(input), output);


		if (eeprom_crc != check_crc) {
			firmware_config();
			save_config();
			err = 2;
		}
	}
	return err;
}

void firmware_config() {
	domuino_id = 0;
	strcpy(password, PASSWORD);
	for (int i=0; i<PINS; i++) {
		output[i].config(i, DIGITAL, 255);
		input[i].config(i, DIGITAL);
	}
	for (int i=0; i<EMONS; i++) {
		emon[i].current((unsigned int) A6+i, 20.73);
	}
}

void save_config() {
	unsigned long eeprom_crc;

	eeprom_write_counter++;
	eeprom_crc = crc((const char*)&input, sizeof(input));
	eeprom_crc += crc((const char*)&output, sizeof(output));
	EEPROM.put(6, eeprom_crc);
	EEPROM.put(6 + sizeof(unsigned long), input);
	EEPROM.put(6 + sizeof(unsigned long) + sizeof(input), output);
}

char first_run() {
	char id[6];
	char is_first;

	is_first = 1;
	EEPROM.get(0, id);
	id[5] = 0;
	if (strcmp(id, start) == 0) {
		is_first = 0;
	} else {
		eeprom_write_counter = 0;
		EEPROM.put(0, start);
	}
	return is_first;
}
