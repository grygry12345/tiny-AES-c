![CI](https://github.com/kokke/tiny-AES-c/workflows/CI/badge.svg)

### Tiny AES in C

This is a small and portable implementation of the AES [ECB](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Electronic_Codebook_.28ECB.29) encryption algorithms written in C.

The API is very simple and looks like this (I am using C99 `<stdint.h>`-style annotated types):

```C
/* Initialize context */
void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);

/* Then start encrypting and decrypting with the functions below: */
void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf);
void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf);

```

Important notes:

- ECB mode is considered unsafe for most uses and is not implemented in streaming mode. If you need this mode, call the function for every block of 16 bytes you need encrypted. See [wikipedia's article on ECB](<https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Electronic_Codebook_(ECB)>) for more details.

CBC and CTR modes have been removed only ECB mode available in [`aes.h`](https://github.com/kokke/tiny-AES-c/blob/master/aes.h) (read the comments for clarification).

C++ support removed since no need for `#include` [aes.hpp](https://github.com/kokke/tiny-AES-c/blob/master/aes.hpp) header [aes.h](https://github.com/kokke/tiny-AES-c/blob/master/aes.h) only used.

There is no built-in error checking or protection from out-of-bounds memory access errors as a result of malicious input.

The module uses less than 200 bytes of RAM and 1-2K ROM when compiled for ARM, but YMMV depending on which modes are enabled.

This implementation is verified against the data in:

[National Institute of Standards and Technology Special Publication 800-38A 2001 ED](http://nvlpubs.nist.gov/nistpubs/Legacy/SP/nistspecialpublication800-38a.pdf) Appendix F: Example Vectors for Modes of Operation of the AES.

The other appendices in the document are valuable for implementation details on e.g. padding, generation of IVs and nonces in CTR-mode etc.

This project forked from [tiny-AES-c](https://github.com/kokke/tiny-AES-c) thanks for thei countributers.

All material in this repository is in the public domain.
