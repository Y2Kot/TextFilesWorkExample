#include "read_write_operations.h"

// Функция записи массива символов в файл при помощи функции fputs
// Возвращает:
//  0 в случае успешной записи в файл
//  -1 в случае ошибки при создании файла
//  1 в случае ошибки записи в  файл
int file_write_text_fputs(const char* data, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
        return -1;
    // !!! Запись всей строки WRITE_TEXT_DATA (до терминального символа) в файл
    // fputs возвращет неотрицательное число в случае успешной записи или EOF в случае ошибки.
    // !!! Стоит попробовать заменить в коде в функции fopen строку "w" на "r" и посмотреть вывод программы в этом случае.
    int is_success = (fputs(data, file) == EOF) ? 1 : 0;
    fclose(file);
    return is_success;
}

// Функция записи массива символов в файл при помощи функции fprintf
// Возвращает:
//  0 в случае успешной записи в файл
//  -1 в случае ошибки при создании файла
//  1 в случае ошибки записи в  файл
int file_write_text_fread(const char* data, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
        return -1;
    // Форматный вывод в файл - аналог printf, но с записью в файл,
    // !!! В случае успеха - возвращает число записанных в файл символом, а в случае неудачи - отрицательное число.
    int write_char_count = 0;
    int is_success = ((write_char_count = fprintf(file, "%s", data)) >= 0) ? 0 : 1;
    printf("%d symbols was written\n", write_char_count);
    fclose(file);
    return is_success;
}

// Функция записи массива оценок ratings размера size в файл filename через разделитель ';'
// Возвращает:
//  0 в случае успешной записи в файл
//  -1 в случае ошибки при создании файла
//  1 в случае ошибки записи в  файл
int write_ratings(const unsigned* ratings, unsigned size, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
        return -1;

    int is_success_write = 1;
    for (unsigned i = 0; i != size && is_success_write; i++)
        is_success_write = (fprintf(file, "%d;", ratings[i]) >= 0);

    fclose(file);
    return is_success_write ? 0 : 1;
}

// Функция читает не более чем max_size элементов в массив ratings из файла filename.
// Возвращает: количество удачно считанных элементов или -1 если произошла ошибка при открытии файла
int read_ratings(unsigned* ratings, unsigned max_size, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return -1;

    unsigned read_count = 0;
    while(read_count != max_size)
    {
        // fscanf может вернуть тут: EOF - достигнут конец файла, 0 - ошибка чтения, 1 - успешное чтение
        // Поэтому в случае != 1 досрочно завершаем цикл.
        if (fscanf(file, "%u;", ratings + read_count) != 1)
            break;

        read_count += 1;
    }

    fclose(file);
    return read_count;
}

// функция подсчёта количества строк в файле
// Возвращает -1 если не удалось открыть файл на чтение
// Схожим образом может быть найдена самая длинная строка в файле
int count_lines(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
        return -1;

    int line_count = 0;
    char c;

    do
    {
        c = getc(file);
        if (c == '\n')
            line_count++;
    }
    while(c != EOF);

    // Нам нужно проверить наличие первого символа чтобы убедиться что в файле есть как минимум одна строка,
    // даже если она не заканчивается \n
    rewind(file);
    c = getc(file);
    if (c != EOF && line_count == 0)
        line_count++;

    fclose(file);
    return line_count;
}
