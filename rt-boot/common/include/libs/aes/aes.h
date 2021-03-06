/* aes.h
 * Jason E. Holt
 * released into the public domain
 */

#ifndef AES_H
#define AES_H

#include <stdint.h>

enum AES_KEYSIZE {
    AES_KEYSIZE_128 = 0,
    AES_KEYSIZE_192,
    AES_KEYSIZE_256
};

struct aes_key_struct_sw {
    unsigned long rd_key[60];
    int rounds;
};

typedef struct aes_key_struct_sw AES_KEY;

#define AES_BLOCK_SIZE 16

int AES_set_encrypt_key(const unsigned char *userKey, const int bits,
                        AES_KEY *key);

int AES_set_decrypt_key(const unsigned char *userKey, const int bits,
                        AES_KEY *key);

void AES_decrypt(const unsigned char *in, unsigned char *out,
                 const AES_KEY *key);

void AES_encrypt(const unsigned char *in, unsigned char *out,
                 const AES_KEY *key);


#endif
