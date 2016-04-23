/*
 * exec.h
 *
 *  Created on: Apr 9, 2016
 *      Author: sebastiano
 */

#ifndef EXEC_H_
#define EXEC_H_

#include "output.h"
#include "scenery.h"
#include "communication.h"
#include "eeconfig.h"

extern EnergyMonitor emon[];
extern Scenery scenery[MAXSCENERIES];
extern Output output[];
extern Input input[PINS];
extern char inputsbuffer[PINS];

extern char password[];
extern char domuino_id;

void execCommand();
void exec_init();

void exec_set(char *type, char *param1, char *param2);
void exec_toggle(char *param1);
void exec_emon(char *param1, char *param2);
void exec_get(char *param1);
void exec_scenery(char *type, char *param1);
void exec_time(char *param1);
void exec_power();

#endif /* EXEC_H_ */
