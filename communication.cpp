/*
 * communication.cpp
 *
 *  Created on: 07/nov/2015
 *      Author: Seabstiano Bonisolo
 */

#include "communication.h"

//const char key[] = "pippero         ";


Communication::Communication() {
}

Communication::~Communication() {
	// TODO Auto-generated destructor stub
}

byte Communication::read() {
	char data[BUFFERSIZE];
	char iv[BLOCK_SIZE + 1];
	unsigned int buffer_size;
	int noerr;
	long crc_value;

	noerr = 0;
	data[0] = '\0';
	buffer_size = 0;
	iv[sizeof(iv) - 1] = 0;
	memset(tokens, 0, sizeof(tokens));
	if (Serial.available() > 0) {
		if (int len = Serial.readBytesUntil(ENDLINE, data, BUFFERSIZE)) {
			data[len] = '\0';
			buffer_size = atoi(data);
			if (Serial.readBytes(data, buffer_size) == buffer_size) {
				crc_value = crc(data, buffer_size);
				if (Serial.readBytesUntil(ENDLINE, iv, sizeof(iv)) == BLOCK_SIZE) {
					char dec[buffer_size];

					if (decrypt((char *)eeconfig.password, (char *)data, (char *)dec, (char *)iv, buffer_size) == 0) {
						dec[strchr(dec, '.') - dec] = '\0';
						if (int len = Serial.readBytesUntil(ENDLINE, data, BUFFERSIZE)) {
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

//TODO: Change crypto key
void Communication::write(const char *data) {
	char enc[to_alloc((char *)data)];
	char iv[17];

	randomSeed(analogRead(0));
	for(unsigned int i=0; i<sizeof(iv); i++) {
		iv[i] = 'a' + random(0, sizeof(iv) - 1);
	}
	iv[sizeof(iv) - 1] = '\0';

	Serial.println(iv);
	Serial.println(sizeof(enc));

	encrypt((char *)eeconfig.password, (char *)data, (char *)enc, (char *)iv);

	Serial.println(crc(enc, sizeof(enc)));

	for(unsigned int i=0; i<sizeof(enc); i++) {
		Serial.write(enc[i]);
	}

	Serial.flush();
}
