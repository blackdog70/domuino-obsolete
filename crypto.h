/*
 * crypto.h
 *
 *  Created on: Feb 27, 2016
 *      Author: sebastiano
 */

#ifndef CRYPTO_H_
#define CRYPTO_H_
#include "Arduino.h"
#include "AES.h"

#define BLOCK_SIZE 16

int to_alloc(char *text);
byte encrypt(char *key, char *text, char *crypto, char *iv);
byte decrypt(char *key, char *crypto, char *text, char *iv, int len);

#endif /* CRYPTO_H_ */
