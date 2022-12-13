#ifndef READ_WRITE_OPERATIONS_STRUCT_H
#define READ_WRITE_OPERATIONS_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include "base_operations.h"

#define MAX_NAME_SIZE 256
#define BOOK_COUNT 2
#define BUFFER_SIZE 100

typedef struct
{
    int pages;
    int year;
    char name[MAX_NAME_SIZE];
} Book;

Book* allocate_book();
Book** allocate_books(int n);

int read_line(FILE* stream, char* str);
int read_int(FILE* stream, int* value);

void show_book(const Book* book);
void show_books(Book** books, int size);

int write_book(const Book* book, const char* filename);
int read_book(Book* book, const char* filename);

int write_book_multiline(const Book* book, FILE* stream);
int read_book_multiline(Book* book, FILE* stream);

int write_books_multiline(Book** books, int size, const char *filename);
int read_books_multiline(Book** books, int size, const char* filename);

#endif // READ_WRITE_OPERATIONS_STRUCT_H
