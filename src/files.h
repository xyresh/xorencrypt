#ifndef H_FILES
#define H_FILES
void write_file(const char *filename, char *data, int len);
char* read_file(const char *filename, int *len);
void write_key(const char *filename, char *key, int len);
char* read_key(const char *filename, int len) ;
#endif
