/*
 * scenery.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: sebastiano
 */

#include "scenery.h"

Scenery::Scenery() {
	for(unsigned int i=0; i<MAXANIMATIONS; i++) {
		animation[i] = NULL;
	}
}

Scenery::~Scenery() {

}

void Scenery::start() {
	for(unsigned int i=0; i<MAXANIMATIONS; i++) {
		if(animation[i] != NULL) {
			animation[i]->start();
		}
	}
}

void Scenery::stop() {
	for(unsigned int i=0; i<MAXANIMATIONS; i++) {
		if(animation[i] != NULL) {
			animation[i]->stop();
		}
	}
}
