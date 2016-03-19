/*
 * eeconfig.cpp
 *
 *  Created on: Mar 7, 2016
 *      Author: sebastiano
 */

#include "eeconfig.h"

const char password[] = "GloriaErikaSeba ";
const char start[] = "Start";
unsigned short eeprom_crc;

char get_config(Config &eeconfig) {
	char err = 0;

	if (first_run(&eeconfig)) {
		firmware_config(&eeconfig);
		store_config(eeconfig);
		err = 1;
	} else {
		EEPROM.get(6, eeprom_crc);
		EEPROM.get(6 + sizeof(unsigned short), eeconfig);

		if (eeprom_crc != crc((const char*)&eeconfig, sizeof(eeconfig))) {
			firmware_config(&eeconfig);
			store_config(eeconfig);
			err = 2;
		}
	}
	return err;
}

void firmware_config(Config* eeconfig) {
	eeconfig->domuino_id = 0;
	strcpy(eeconfig->password, password);
	for (int i=0; i<PINS; i++) {
		eeconfig->outputs[i].mode = DIGITAL;
		eeconfig->outputs[i].state = LOW;
		eeconfig->outputs[i].value = 0;

		eeconfig->inputs[i].mode = DIGITAL;
		eeconfig->inputs[i].state = LOW;
		eeconfig->inputs[i].value = 0;
	}
	for (int i=0; i<MAXSCENERIES; i++) {
		//TODO: Implement for MAXANIMATIONS not only for position 0
		eeconfig->scenery[i].animations[0].output = i;
		eeconfig->scenery[i].animations[0].state = HIGH;
		eeconfig->scenery[i].animations[0].value = 255;
	}
	for (int i=0; i<EMONS; i++) {
		eeconfig->emon_calib[i] = 20.73;
	}
}

char first_run(Config* eeconfig) {
	char id[6];
	char is_first;

	is_first = 1;
	EEPROM.get(0, id);
	id[5] = 0;
	if (strcmp(id, start) == 0) {
		is_first = 0;
	} else {
		eeconfig->eeprom_write_counter = 0;
		EEPROM.put(0, start);
	}
	return is_first;
}

void store_config(Config &eeconfig) {
	eeconfig.eeprom_write_counter++;
	eeprom_crc = crc((const char*)&eeconfig, sizeof(eeconfig));
	EEPROM.put(6, eeprom_crc);
	EEPROM.put(6 + sizeof(unsigned short), eeconfig);
}
