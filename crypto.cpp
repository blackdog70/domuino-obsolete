/*
 * crypto.cpp
 *
 *  Created on: Feb 27, 2016
 *      Author: sebastiano
 */

#include "crypto.h"

AES aes;

int to_alloc(char *text) {
	return strlen(text) + (BLOCK_SIZE - (strlen(text) % BLOCK_SIZE));
}

byte encrypt(char *key, char *text, char *crypto, char *iv) {
	text[to_alloc(text)] = '\0';
	memset((char *)(text+strlen(text)), ' ', BLOCK_SIZE - (strlen(text) % BLOCK_SIZE));

	int blocks = strlen(text) / BLOCK_SIZE;

	byte succ = aes.set_key((unsigned char *)key, 128) ;

	succ = aes.cbc_encrypt((byte *)text, (byte *)crypto, blocks, (byte *)iv);

	return succ;
}

byte decrypt(char *key, char *crypto, char *text, char *iv, int buffer_size) {
	int blocks = buffer_size / BLOCK_SIZE;

	byte succ = aes.set_key((unsigned char *)key, 128);

	succ = aes.cbc_decrypt((byte *)crypto, (byte *)text, blocks, (byte *)iv);

	text[buffer_size] = '\0';

	return succ;
}

unsigned short crc(const char *data, size_t size) {
	unsigned short crc_modbus = 0xffff;
	const char *d = data;

	for (unsigned int i=0; i<size; i++) {
//	while(*d) {
		crc_modbus = update_crc_16(crc_modbus, *d);
		d++;
	}
	return crc_modbus;
}
