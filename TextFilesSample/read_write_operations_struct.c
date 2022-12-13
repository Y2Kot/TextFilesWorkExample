#include "read_write_operations_struct.h"

/*
* Функция для выделения указателей на структуры студентов
*/
Book* allocate_book() {
    return (Book*) malloc(sizeof(Book));
}

Book** allocate_books(int n) {
    Book** all = (Book**) malloc(n * sizeof(Book*));
    // ATTENTION: на самом деле необходимо проверять указатель на NULL,
    // т.к. могут быть утечки памяти
    for (int i = 0; i < n; i++) {
        all[i] = allocate_book();
    }
    return all;
}

// Считываем строку
int read_line(FILE* stream, char* str)
{
    int is_success = 0;
    is_success += fgets(str, BUFFER_SIZE, stream) == NULL ? 1 : 0;
    int len = strlen(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
    return is_success;
}

// Считываем и преобразовываем строку в число
int read_int(FILE* stream, int* value)
{
    char buf[100] = { 0 };
    int is_success = 0;
    is_success += fgets(buf, BUFFER_SIZE, stream) == NULL ? 1 : 0;
    int len = strlen(buf);
    if (buf[len - 1] == '\n')
        buf[len - 1] = '\0';
    is_success += sscanf(buf, "%d", value) == 1 ? 0 : 1;
    return is_success;
}

void show_book(const Book* book)
{
    printf("name: %s\npages: %d\nyear: %d\n", book->name, book->pages, book->year);
}

void show_books(Book** books, int size)
{
    for(int i = 0; i < size; i++)
        show_book(books[i]);
}

int write_book(const Book* book, const char* filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
        return -1;

    int is_success_write = (fprintf(file, "%s %d %d\n", book->name, book->pages, book->year) >= 0);

    fclose(file);
    return is_success_write ? 0 : 1;
}

int read_book(Book* book, const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
        return -1;

    // !!! В примере делаем допущение, что в файле строка с именем книги будет всегда по длине не более
    // MAX_NAME_SIZE - 1, иначе произойдет переполнение буфера
    int is_success_read = (fscanf(file, "%s %d %d", book->name, &(book->pages), &(book->year)) == 3);

    fclose(file);
    return is_success_read ? 0 : 1;
}

int write_book_multiline(const Book* book, FILE* stream)
{
    int is_success_write = 0;
    is_success_write += fprintf(stream, "%s", book->name) >= 0 ? 0 : 1;
    is_success_write += fprintf(stream, "\n%d", book->pages) >= 0 ? 0 : 1;
    is_success_write += fprintf(stream, "\n%d", book->year) >= 0 ? 0 : 1;

    return is_success_write == 0 ? 0 : -1;
}

int read_book_multiline(Book* book, FILE* stream)
{
    int is_success_read = 0;

    is_success_read += read_line(stream, book->name);
    is_success_read += read_int(stream, &(book->pages));
    is_success_read += read_int(stream, &(book->year));

    return is_success_read == 0 ? 0 : -1;
}

int write_books_multiline(Book** books, int size, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
        return -1;

    int is_success_write = 0;
    for (int i = 0; i < size && is_success_write == 0; i++)
    {
        is_success_write += write_book_multiline(books[i], file);
        fprintf(file, "\n");
    }

    fclose(file);
    return is_success_write == 0 ? 0 : -1;
}

int read_books_multiline(Book** books, int size, const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
        return -1;

    int is_success_read = 0;
    for(int i = 0; i < size && is_success_read == 0; i++)
        is_success_read += read_book_multiline(books[i], file);

    fclose(file);
    return is_success_read == 0 ? 0 : -1;
}
