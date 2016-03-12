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

struct Pin {
	unsigned char mode;
	unsigned char state;
	unsigned char value;
};

struct Config {
	long eeprom_write_counter;
	char domuino_id;
	char password[BLOCK_SIZE+1];
	Pin inputs[PINS];
	Pin outputs[PINS];
	int io_relation[PINS];
	double emon_calib[EMONS];
};

extern Config eeconfig;

char first_run();
void store_config();
void firmware_config();
char get_config();

#endif /* EECONFIG_H_ */
