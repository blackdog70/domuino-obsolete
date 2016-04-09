/*
 * communication.cpp
 *
 *  Created on: 07/nov/2015
 *      Author: Seabstiano Bonisolo
 */

#include "communication.h"

//const char msgfmt[] = "{\"T\":%lu,\"C\":\"%s\",\"S\":\"%s\",\"D\":%s}";
const char msgfmt[] = "%s@%lu";
const char null[] = "null\0";

Communication::Communication(char *password) {
	Communication::password = password;
}

Communication::~Communication() {
	// TODO Auto-generated destructor stub
}

char Communication::read() {
	char data[BUFFERSIZE];
	char iv[BLOCK_SIZE + 1];
	unsigned int buffer_size;
	char noerr;
	long crc_value;

	noerr = 0;
	data[0] = '\0';
	buffer_size = 0;
	iv[sizeof(iv) - 1] = 0;
	memset(tokens, 0, sizeof(tokens));
	if (Serial.available() > 0) {
		int data_size = Serial.readBytesUntil(TERM_CMD, data, sizeof(data) - 1);
		data[data_size] = '\0';
		crc_value = crc(data, data_size);
		data_size = Serial.readBytesUntil(ENDLINE, iv, sizeof(iv) -1);
		iv[data_size] = '\0';
 		if ((unsigned short)atol(iv) == crc_value) {
			int tokenId = 0;
			for(char* token = strtok(data, TERM_TOKEN); token != NULL; token = strtok(NULL, TERM_TOKEN)) {
				strcpy(tokens[tokenId], token);
				tokenId++;
			}
			noerr = 1;
		}
	}

	return noerr;
}

void Communication::send(const char *data) {
	char iv[17];
	char msg[MSGLEN];
	char *d;

	if (strcmp(data, "") == 0)
		d = (char *)null;
	else
		d = (char *)data;
//	sprintf(msg, msgfmt, (unsigned long)now(), command, status, d);
	sprintf(msg, msgfmt, d, (unsigned long)now());

	Serial.println(msg);
	Serial.println(crc(msg, strlen(msg)));

	Serial.flush();
}
