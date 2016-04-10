/*
 * communication.cpp
 *
 *  Created on: 07/nov/2015
 *      Author: Seabstiano Bonisolo
 */

#include "communication.h"

//const char msgfmt[] = "{\"T\":%lu,\"C\":\"%s\",\"S\":\"%s\",\"D\":%s}";
const char msgfmt[] = "%lu|%s|"; //| Time | Data
const char null[] = "null\0";

Communication::Communication(char *password) {
	Communication::password = password;
}

Communication::~Communication() {
	// TODO Auto-generated destructor stub
}

char Communication::read() {
	char data[BUFFERSIZE];
	char noerr;

	noerr = 0;
	data[0] = '\0';
	memset(tokens, 0, sizeof(tokens));
	if (Serial.available() > 0) {
		int data_size = Serial.readBytesUntil(TERM_CMD, data, sizeof(data) - 1);
		data[data_size] = '\0';
		char *end_crc = strchr(data, '|');
		if (end_crc != NULL) {
			char *command = end_crc + 1;
			long crc_value = crc(command, strlen(command));
			*(end_crc) = 0;
			if ((unsigned short)atol(data) == crc_value) {
				int tokenId = 0;
				for(char *token = strtok(command, TERM_TOKEN); token != NULL; token = strtok(NULL, TERM_TOKEN)) {
					strcpy(tokens[tokenId], token);
					tokenId++;
				}
				noerr = 1;
			}
		}
	}

	return noerr;
}

void Communication::send(const char *data) {
	char msg[MSGLEN];
	char *d;
	char crc_str[7];

	if (strcmp(data, "") == 0)
		d = (char *)null;
	else
		d = (char *)data;
	sprintf(msg, msgfmt, (unsigned long)now(), d);
	ltoa(crc(msg, strlen(msg) - 1), crc_str, 10); // format char | excluded
	strcat(msg, crc_str);
	Serial.println(msg);
}
