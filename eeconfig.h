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
#define EMONS 2

struct Pin {
	char mode;
	char state;
	char value;
};

struct Config {
	long eeprom_write_counter;
	char domuino_id;
	char password[BLOCK_SIZE+1];
	Pin inputs[INPUTS];
	Pin outputs[OUTPUTS];
	int io_relation[INPUTS];
	double emon_calib[EMONS];
};

extern Config eeconfig;

char first_run();
void store_config();
void firmware_config();
char get_config();

#endif /* EECONFIG_H_ */
