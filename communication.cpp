/*
 * communication.cpp
 *
 *  Created on: 07/nov/2015
 *      Author: Seabstiano Bonisolo
 */

#include "communication.h"

const char msgfmt[] = "{\"T\":%lu,\"C\":\"%s\",\"S\":\"%s\",\"D\":%s}";
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
		if (int len = Serial.readBytesUntil(ENDLINE, data, BUFFERSIZE)) {					//Read buffer size
			data[len] = '\0';
			buffer_size = atoi(data);
			if (Serial.readBytes(data, buffer_size) == buffer_size) {						//Read buffer
				crc_value = crc(data, buffer_size);
				if (Serial.readBytesUntil(ENDLINE, iv, sizeof(iv)) == BLOCK_SIZE) {			//Read IV
					char dec[buffer_size];
					iv[sizeof(iv) - 1] = '\0';

					if (decrypt((char *)password, (char *)data, (char *)dec, (char *)iv, buffer_size) == 0) {
						dec[strchr(dec, '.') - dec] = '\0';
						if (int len = Serial.readBytesUntil(ENDLINE, data, BLOCK_SIZE)) {   //Read CRC
							data[len] = '\0';

							if ((unsigned short)atol(data) == crc_value) {
								int tokenId = 0;
								for(char* token = strtok(dec, TERM_TOKEN); token != NULL; token = strtok(NULL, TERM_TOKEN)) {
									strcpy(tokens[tokenId], token);
									tokenId++;
								}
								noerr = 1;
							}
						}
					}
				}
			}
		}
	}

	return noerr;
}

void Communication::send(const char *command, const char *status, const char *data) {
	char iv[17];
	char msg[MSGLEN];
	char *d;

	if (strcmp(data, "") == 0)
		d = (char *)null;
	else
		d = (char *)data;
	sprintf(msg, msgfmt, (unsigned long)now(), command, status, d);

	char enc[to_alloc((char *)msg)];

	randomSeed(analogRead(0));
	for(unsigned int i=0; i<sizeof(iv); i++) {
		iv[i] = 'a' + random(0, sizeof(iv) - 1);
	}
	iv[sizeof(iv) - 1] = '\0';

	Serial.println(iv);
	Serial.println(sizeof(enc));

	encrypt((char *)password, (char *)msg, (char *)enc, (char *)iv);

	Serial.println(crc(enc, sizeof(enc)));

	for(unsigned int i=0; i<sizeof(enc); i++) {
		Serial.write(enc[i]);
	}

	Serial.flush();
}
