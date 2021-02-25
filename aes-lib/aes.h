#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>
#include <stddef.h>

// #define the macros below to 1/0 to enable/disable the mode of operation.
//
// CBC enables AES encryption in CBC-mode of operation.
// CTR enables encryption in counter-mode.
// ECB enables the basic ECB 16-byte block algorithm. All can be enabled simultaneously.

#define AES_BLOCKLEN 16 // Block length in bytes - AES is 128b block only

#define AES_KEYLEN 16 // Key length in bytes
#define AES_keyExpSize 176

struct AES_ctx
{
  uint8_t RoundKey[AES_keyExpSize];
};

void AES_init_ctx(struct AES_ctx *ctx, const uint8_t *key);

void AES_ECB_encrypt(const struct AES_ctx *ctx, uint8_t *buf);
void AES_ECB_decrypt(const struct AES_ctx *ctx, uint8_t *buf);

#endif // _AES_H_
