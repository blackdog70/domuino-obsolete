/*!
 * eeconfig.h
 *
 *  Created on: Mar 7, 2016
 *      Author: sebastiano
 */

#ifndef EECONFIG_H_
#define EECONFIG_H_

#include "domuino.h"
#include "crypto.h"
#include "onoff.h"
#include "EEPROM.h"

//TODO: Put here all the constants
#define EMONS 2

extern int eeprom_write_counter;

/*!
 * Check if it is the first time that domuino is started
 */
char first_run();

/*!
 * Save domuino configuration on eeprom
 */
void save_config();

/*!
 * Init domuino configuration
 */
void firmware_config();

/*!
 * Get domuino configuration from eeprom
 */
char load_config();

#endif /* EECONFIG_H_ */
