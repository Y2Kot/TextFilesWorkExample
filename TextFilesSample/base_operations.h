#ifndef BASE_OPERATIONS_H
#define BASE_OPERATIONS_H

#include <stdio.h>
#include <string.h> // Для функции strerror
#include <errno.h> // Для макроса errno

int is_file_exist(const char* filename);
void show_file_existence_status(const char* filename);
void concrete_error();

#endif // BASE_OPERATIONS_H
