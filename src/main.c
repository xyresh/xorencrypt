/*
*
*   XOR encryption implementation
*
*   Written by mrayo
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "xor.h"
#include "files.h"


int main(int argc, char **argv) {
    //check for correct arguments
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <e/d> <input file> <output file> <key file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    //encrypt or decrypt mode, file names etc.
    char *mode = argv[1];
    char *input_filename = argv[2];
    char *output_filename = argv[3];
    char *key_filename = argv[4];

    // Initialize random number generator
    srand(time(NULL));

    int len;
    char *input = read_file(input_filename, &len);
    char *output = (char *)malloc(len);
    if (!output) {
        perror("Error allocating memory for output");
        exit(EXIT_FAILURE);
    }
    //encrypt file
    if (strcmp(mode, "e") == 0) {
        char *key = (char *)malloc(len);
        if (!key) {
            perror("Error allocating memory for key");
            exit(EXIT_FAILURE);
        }
        generate_random_key(key, len);
        xor_encrypt_decrypt(input, output, key, len);

        write_file(output_filename, output, len);
        write_key(key_filename, key, len);

        free(key);
    } else if (strcmp(mode, "d") == 0) { //decrypt
        char *key = read_key(key_filename, len);
        xor_encrypt_decrypt(input, output, key, len);

        write_file(output_filename, output, len);

        free(key);
    } else {
        fprintf(stderr, "Invalid mode. Use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    free(input);
    free(output);

    return EXIT_SUCCESS;
}