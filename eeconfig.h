/*
 * eeconfig.h
 *
 *  Created on: Mar 7, 2016
 *      Author: sebastiano
 */

#ifndef EECONFIG_H_
#define EECONFIG_H_

#include "input.h"
#include "crypto.h"
#include "EEPROM.h"

//TODO: Put here all the constants
#define PINS 6
#define EMONS 2
#define MAXSCENERIES PINS
#define MAXANIMATIONS PINS


struct Anim {
	unsigned char output;
	unsigned char state;
	unsigned char value;
};

struct Scen {
	Anim animations[MAXANIMATIONS];
};

struct Pin {
	unsigned char mode;
	unsigned char state;
	unsigned char value;
};

//TODO: Save scenery to eeprom
struct Config {
	long eeprom_write_counter;
	char domuino_id;
	char password[BLOCK_SIZE+1];
	Pin inputs[PINS];
	Pin outputs[PINS];
	Scen scenery[MAXSCENERIES];
	double emon_calib[EMONS];
};

extern Config eeconfig;

char first_run(Config*);
void store_config(Config&);
void firmware_config(Config*);
char get_config(Config&);

#endif /* EECONFIG_H_ */
