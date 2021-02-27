#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>
#include <stddef.h>

// #define the macros below to 1/0 to enable/disable the mode of operation.
//
// ECB enables the basic ECB 16-byte block algorithm. All can be enabled simultaneously.
/*****************************************************************************/
/* Defines:                                                                  */
/*****************************************************************************/
// The number of columns comprising a state in AES. This is a constant in AES. Value=4
#define Nb 4
#define Nk 4  // The number of 32 bit words in a key.
#define Nr 10 // The number of rounds in AES Cipher.

#define AES_BLOCKLEN 16 // Block length in bytes - AES is 128b block only
#define AES_KEYLEN 16 // Key length in bytes
#define AES_KEYEXPSIZE 176
#define AES_TEXTLEN 256

// state - array holding the intermediate results during decryption.

void AES_ECB_init(const uint8_t *Key, uint8_t *roundKey);
void AES_ECB_encrypt(uint8_t state[4][4], const uint8_t *roundKey);
void AES_ECB_decrypt(uint8_t state[4][4], const uint8_t *roundKey);
void AES_ECB_encrypt_text(uint8_t *state, const uint8_t *roundKey);

#endif // _AES_H_
