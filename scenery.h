/*
 * scenery.h
 *
 *  Created on: Mar 13, 2016
 *      Author: sebastiano
 */

/*!
 * Scenery create a relation between input and animation
 *
 * If the Inputs matrix is recognized will be started a series of animations
 * Each animation control one output pin
 *
 * INPUT --> Scenery --> Animation --> OUTPUT
 */

#ifndef SCENERY_H_
#define SCENERY_H_

#include "animation.h"

#define MAXSCENERIES 6

class Scenery {

public:
	Animation* animation[MAXANIMATIONS];
//	char matrix[PINS];

	Scenery();
	virtual ~Scenery();

//	char* refresh();
	void start();
	void stop();
};

#endif /* SCENERY_H_ */
