/*
 * communication.h
 *
 *  Created on: 07/nov/2015
 *      Author: erika
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include "Arduino.h"
#include "crypto.h"
//#include "FreeMemory.h"
#include "Time.h"
//#include "eeconfig.h"
#include "domuino.h"

#define TERM_CMD '#'
#define TERM_TOKEN "|"
#define ENDLINE '\n'
#define MAXTOKENS 3
#define SIZETOKENS 12
#define BUFFERSIZE 80
//#define SERIAL_RX_BUFFER_SIZE 100
//#define SERIAL_TX_BUFFER_SIZE 220
#define CRC_16_MODBUS 0xffff
#define MSGLEN 5*BLOCK_SIZE+1		// BLOCKSIZE is necessary for AES128 encryption

class Communication {
public:
	char tokens[MAXTOKENS][SIZETOKENS];
	char* password;

	Communication(char *);
	virtual ~Communication();

	char read();
	void send(const char*);
};

#endif /* COMMUNICATION_H_ */
