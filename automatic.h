/*
 * automatic.h
 *
 *  Created on: 07/nov/2015
 *      Author: erika
 */

/*
 *
 */


#ifndef AUTOMATIC_H_
#define AUTOMATIC_H_

#include "Arduino.h"
#include "Time.h"
#include "input.h"
#include "output.h"
#include "animation.h"
#include "communication.h"
#include "EmonLib.h"                   // Include Emon Library
#include "errno.h"
#include "eeconfig.h"
#include "avr/pgmspace.h"

class Automatic {
public:
	Output* outputs[PINS];
	Input* inputs[PINS];
	EnergyMonitor* emon[EMONS];       // Create an instance
	char password[BLOCK_SIZE+1];
	char domuino_id;

	Automatic();
	virtual ~Automatic();

	void on();
	void refresh();

private:
	void load_config();
	void save_config();

	/* Command:
	 * [SETP or SETV]|[Pin number]|[Value].
	 *
	 * SETP accept values between 0 and 1, it is used to reset or set the output pin
	 * SETV accept valued between 0 and 255, it is used to set value for lamps dimming
	 *
	 * Command:
	 * [GETP or SETV]|[Pin number]|[Value].
	 *
	 * Command:
	 * SAVE.
	 *
	 * Save configuration on eeprom
	 *
	 * Command:
	 * TIME|[Value].
	 *
	 * Set the time using value in timestamp format
	 *
	 * Command:
	 * POWER.
	 *
	 * Return the W consumption
	 *
	 * Command:
	 * FREEMEM.
	 *
	 * Return then free SRAM on arduino
	 */
	void execCommand();
	void send(const char*, const char*, const char*);

	Communication* communication;
};

#endif /* AUTOMATIC_H_ */
