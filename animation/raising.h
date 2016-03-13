/*
 * raising.h
 *
 *  Created on: 05/nov/2015
 *      Author: erika
 */

#ifndef RAISING_H_
#define RAISING_H_

#include "Arduino.h"
#include "../animation.h"

class Raising: public Animation {
public:
	Raising(Output *out, byte state, byte value, unsigned long time);
	virtual ~Raising();

	void config(Output *out, byte state, byte value, unsigned long time);
	virtual void start();
	virtual void stop();
	virtual void refresh();

private:
	unsigned long start_timer;
	unsigned long duration;
};

#endif /* RAISING_H_ */
