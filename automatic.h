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

#define EMONS 2

class Automatic {
public:
	Output* outputs[OUTPUTS];
	Input* inputs[INPUTS];
	EnergyMonitor* emon[EMONS];       // Create an instance

	Automatic();
	virtual ~Automatic();

	void config();
	void on();
	void show();
	void refresh();

private:
	void onCommand();
	void offCommand();
	void setCommand();
	void unrecognized();
	void execCommand();
	void send(const char*, const char*, const char*);

	Communication* communication;
};

#endif /* AUTOMATIC_H_ */
