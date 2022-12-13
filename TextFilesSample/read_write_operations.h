#ifndef READ_WRITE_OPERATIONS_H
#define READ_WRITE_OPERATIONS_H


#include "base_operations.h"

int file_write_text_fputs(const char* data, const char* filename);
int file_write_text_fread(const char* data, const char* filename);
int write_ratings(const unsigned* ratings, unsigned size, const char *filename);
int read_ratings(unsigned* ratings, unsigned max_size, const char *filename);
int count_lines(const char* filename);

#endif // READ_WRITE_OPERATIONS_H
