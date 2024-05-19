/*
*
*   xor.c
*
*   encryption is done here
*
*   along with the key generator
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// XOR encryption/decryption function
void xor_encrypt_decrypt(char *input, char *output, char *key, int len) {
    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ key[i];
    }
    output[len] = '\0'; // Null-terminate the output string
}

// Function to generate a random key
void generate_random_key(char *key, int len) {
    for (int i = 0; i < len; i++) {
        key[i] = rand() % 256; // Generate a random byte
    }
    key[len] = '\0'; // Null-terminate the key
}