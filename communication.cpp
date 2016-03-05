/*
 * communication.cpp
 *
 *  Created on: 07/nov/2015
 *      Author: Seabstiano Bonisolo
 */

#include "communication.h"

Communication::Communication() {
	tokenId = 0;
	cleanTokens();
}

Communication::~Communication() {
	// TODO Auto-generated destructor stub
}

void Communication::cleanTokens() {
	for(int i=0; i<MAXTOKENS; i++) {
		strcpy(tokens[i], "");
	}
}

unsigned short Communication::crc(const char *data) {
	unsigned short crc_modbus = 0xffff;
	const char *d = data;

	while(*d) {
		crc_modbus = update_crc_16(crc_modbus, *d);
		d++;
	}
	return crc_modbus;
}

//TODO: gestire crc in lettura
byte Communication::read() {
	const char key[] = "pippero         ";
	char data[BUFFERSIZE];
	char iv[BLOCK_SIZE + 1];
	unsigned int buffer_size;
	int noerr;

	noerr = 0;
	data[0] = '\0';
	buffer_size = 0;
	iv[sizeof(iv) - 1] = 0;
	if (Serial.available() > 0) {
		if (int len = Serial.readBytesUntil(ENDLINE, data, BUFFERSIZE)) {
			data[len] = 0;
			buffer_size = atoi(data);
			if (Serial.readBytes(data, buffer_size) == buffer_size) {
				if (Serial.readBytesUntil(ENDLINE, iv, sizeof(iv)) == BLOCK_SIZE) {
					char dec[buffer_size];

					if (decrypt((char *)key, (char *)data, (char *)dec, (char *)iv, buffer_size) == 0) {
						dec[strchr(dec, '.') - dec] = 0;
						if (int len = Serial.readBytesUntil(ENDLINE, data, BUFFERSIZE)) {
							data[len] = 0;
							Serial.print("data="); Serial.println((unsigned short)atol(data));
							Serial.print("crc="); Serial.println(crc(data));
							if ((unsigned short)atol(data) == crc(dec)) {
								cleanTokens();
								tokenId = 0;
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

void Communication::write(const char *data) {
	const char key[] = "pippero         ";
	char enc[to_alloc((char *)data)];
	char iv[17];

	randomSeed(analogRead(0));
	for(unsigned int i=0; i<sizeof(iv); i++) {
		iv[i] = 'a' + random(0, sizeof(iv) - 1);
	}
	iv[sizeof(iv) - 1] = '\0';

	Serial.println(iv);
	Serial.println(sizeof(enc));
	Serial.println(crc(data));

	encrypt((char *)key, (char *)data, (char *)enc, (char *)iv);

	for(unsigned int i=0; i<sizeof(enc); i++) {
		Serial.write(enc[i]);
	}
	Serial.flush();
}
