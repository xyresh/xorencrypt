/*
*   files.c
*
*   all file operations are handled here
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* read_file(const char *filename, int *len) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    *len = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *)malloc(*len);
    if (!buffer) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    fread(buffer, 1, *len, file);
    fclose(file);

    return buffer;
}

void write_file(const char *filename, char *data, int len) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    fwrite(data, 1, len, file);
    fclose(file);
}

// Function to write key to a file
void write_key(const char *filename, char *key, int len) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening key file for writing");
        exit(EXIT_FAILURE);
    }
    fwrite(key, 1, len, file);
    fclose(file);
}

// Function to read key from a file
char* read_key(const char *filename, int len) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening key file");
        exit(EXIT_FAILURE);
    }
    char *key = (char *)malloc(len);
    if (!key) {
        perror("Error allocating memory for key");
        exit(EXIT_FAILURE);
    }
    fread(key, 1, len, file);
    fclose(file);

    return key;
}

