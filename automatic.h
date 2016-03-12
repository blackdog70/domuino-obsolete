/*
 * automatic.h
 *
 *  Created on: 07/nov/2015
 *      Author: erika
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

	Automatic();
	virtual ~Automatic();

	void on();
	void refresh();
//	void get_config();
//	void store_config();
//	void firmware_config();

private:
//	char first_run();
	void onCommand();
	void offCommand();
	void setCommand();
	void unrecognized();
	void execCommand();
	void send(const char*, const char*, const char*);

	Communication* communication;
};

#endif /* AUTOMATIC_H_ */
