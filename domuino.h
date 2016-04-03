// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef _domuino_H_
#define _domuino_H_
#include "Arduino.h"
//add your includes for the project domino here

#include "input.h"
#include "output.h"
#include "scenery.h"
#include "communication.h"
#include "EmonLib.h"
#include "errno.h"
#include "TimerOne.h"
#include "FreeMemory.h"
#include "eeconfig.h"

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

#define EMONS 2

//add your function definitions for the project domino here
extern EnergyMonitor emon[];
extern Scenery scenery[MAXSCENERIES];
extern Output output[];
extern Input input[PINS];
extern char inputsbuffer[PINS];

extern char password[];
extern char domuino_id;

//void config();
//void start();
void timer_clk();
void dimmer_test();
void zero_cross();
void blink_13();
void pstate();
void automatic_on();

/*!
 * Command:
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

//Do not add code below this line
#endif /* _domino_H_ */
