#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#include "aes.h"

static void print_hex(uint8_t *str);
static int test_encrypt_ecb(void);
static int test_decrypt_ecb(void);
static void test_encrypt_ecb_verbose(void);

int main(void)
{
    // int exit;

    // exit = test_decrypt_ecb() + test_encrypt_ecb();
    test_encrypt_ecb_verbose();

    return 0;
}

// prints string as hex
static void print_hex(uint8_t *str)
{
    uint8_t len = 16;

    unsigned char i;
    for (i = 0; i < len; ++i)
    {
        printf("%.2x", str[i]);
    }
    printf("\n");
}

static void test_encrypt_ecb_verbose(void)
{
    // Example of more verbose verification
    uint8_t i;

    // 128bit key
    uint8_t key[16] = {(uint8_t)0xff, (uint8_t)0x7e, (uint8_t)0x15, (uint8_t)0x16, (uint8_t)0x28, (uint8_t)0xae, (uint8_t)0xd2, (uint8_t)0xa6, (uint8_t)0xab, (uint8_t)0xf7, (uint8_t)0x15, (uint8_t)0x88, (uint8_t)0x09, (uint8_t)0xcf, (uint8_t)0x4f, (uint8_t)0x3c};

    uint8_t RoundKey[AES_KEYEXPSIZE];
    uint8_t text[AES_TEXTLEN];
    uint8_t textBlocks[AES_TEXTLEN / (4 * 4)][4][4]; // number of blocks, number of characters
    uint8_t blockNumber;

    // Zeroing textblocks for convinence
    for (uint8_t i = 0; i < 16; i++)
    {
        for (uint8_t j = 0; j < 4; j++)
        {
            for (uint8_t k = 0; k < 4; k++)
            {
                textBlocks[i][j][k] = 0;
            }
        }
    }

    // Get Text Input
    printf("\nEnter text: \n");
    fgets(text, AES_TEXTLEN, stdin);
    printf("\n");

    // Find number of blocks by dividing text length 16
    blockNumber = strlen(text) / 16;

    // Initialize text block by 4x4 array and text block number
    for (uint8_t i = 0; i < blockNumber + 1; i++)
    {
        for (uint8_t j = 0; j < 4; j++)
        {
            for (uint8_t k = 0; k < 4; k++)
            {
                if ((4 * j) + k < strlen(text))
                {
                    textBlocks[i][j][k] = *(text + (16 * i) + (4 * j) + k);
                }
                else
                {
                    goto finishInit;
                }
            }
        }
    }

finishInit:

    printf("\nKey:\n");
    print_hex(key);
    printf("\n");

    AES_ECB_init(key, RoundKey);

    printf("Cipher text:\n");
    for (i = 0; i < blockNumber + 1; ++i)
    {
        AES_ECB_encrypt(textBlocks[i], RoundKey);
    }
    printf("\n");

    printf("Plain text:\n");
    for (i = 0; i < blockNumber + 1; ++i)
    {
        AES_ECB_decrypt(textBlocks[i], RoundKey);
    }
    printf("\n");
}

static int test_encrypt_ecb(void)
{
    uint8_t key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    uint8_t out[4][4] = {{0x3a, 0xd7, 0x7b, 0xb4}, {0x0d, 0x7a, 0x36, 0x60}, {0xa8, 0x9e, 0xca, 0xf3}, {0x24, 0x66, 0xef, 0x97}};

    uint8_t in[4][4] = {{0x6b, 0xc1, 0xbe, 0xe2}, {0x2e, 0x40, 0x9f, 0x96}, {0xe9, 0x3d, 0x7e, 0x11}, {0x73, 0x93, 0x17, 0x2a}};

    uint8_t RoundKey[AES_KEYEXPSIZE];

    AES_ECB_init(key, RoundKey);
    AES_ECB_encrypt(in, RoundKey);

    printf("ECB encrypt: ");

    if (0 == memcmp((char *)out, (char *)in, 16))
    {
        printf("SUCCESS!\n");
        return (0);
    }
    else
    {
        printf("FAILURE!\n");
        return (1);
    }
}

static int test_decrypt_ecb(void)
{
    uint8_t key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};

    uint8_t out[4][4] = {{0x6b, 0xc1, 0xbe, 0xe2}, {0x2e, 0x40, 0x9f, 0x96}, {0xe9, 0x3d, 0x7e, 0x11}, {0x73, 0x93, 0x17, 0x2a}};
    uint8_t in[4][4] = {{0x3a, 0xd7, 0x7b, 0xb4}, {0x0d, 0x7a, 0x36, 0x60}, {0xa8, 0x9e, 0xca, 0xf3}, {0x24, 0x66, 0xef, 0x97}};

    uint8_t RoundKey[AES_KEYEXPSIZE];

    AES_ECB_init(key, RoundKey);
    AES_ECB_decrypt(in, RoundKey);

    printf("ECB decrypt: ");

    if (0 == memcmp((char *)out, (char *)in, 16))
    {
        printf("SUCCESS!\n");
        return (0);
    }
    else
    {
        printf("FAILURE!\n");
        return (1);
    }
}
