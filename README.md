
# Tiny AES 128 bit ECB mode in C

This project is a small and portable implementation of the AES [ECB](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Electronic_Codebook_.28ECB.29) encryption algorithms written in C.

```C
/* Initialize context */
void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);

/* Then start encrypting and decrypting with the functions below: */
void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf);
void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf);

```

## How to test and execute the script

Test executable script is linked ```.../tiny-aes-c/build/aes-test/test```. It could executed by ```$ ./tiny-aes-c/build/aes-test/test``` command. Program is not installable yet.

Scripts could be tested in ```int main(void)``` function.

## Important notes

ECB mode is considered unsafe for most uses. If you need this mode, call the function for every block of 16 bytes you need encrypted. See [wikipedia's article on ECB](<https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Electronic_Codebook_(ECB)>) for more details.

CBC and CTR modes have been removed after fork only ECB mode available in [`aes.h`](https://github.com/kokke/tiny-AES-c/blob/master/aes.h) (read the comments for clarification).

C++ support removed since no need for ~~`#include` [aes.hpp](https://github.com/kokke/tiny-AES-c/blob/master/aes.hpp)~~ **header [aes.h](https://github.com/kokke/tiny-AES-c/blob/master/aes.h) only used**.

The module uses less than 200 bytes of RAM and 1-2K ROM when compiled for ARM, but YMMV depending on which modes are enabled.

This implementation is verified against the data in:

[National Institute of Standards and Technology Special Publication 800-38A 2001 ED](http://nvlpubs.nist.gov/nistpubs/Legacy/SP/nistspecialpublication800-38a.pdf) Appendix F: Example Vectors for Modes of Operation of the AES.

The other appendices in the document are valuable for implementation details, e.g., padding, generation of IVs and nonces in CTR-mode, etc.

This project was forked from [tiny-AES-c](https://github.com/kokke/tiny-AES-c).

All material in this repository is in the public domain.

## Plain Text Functionailty

Also, we added plain text input in this function.

```C
// Test plain text input
static void test_encrypt_ecb_verbose(void);
```
