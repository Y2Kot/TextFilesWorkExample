#include "base_operations.h"

// Будем допускать, что файл существует, если он может быть открыт для чтения
int is_file_exist(const char* filename)
{
    FILE *file = fopen(filename, "r");

    // Запоминаем факт успешности открытия файла с именем filename на чтение
    int is_open = (file != NULL);

    // Не забываем закрыть файл
    if (is_open)
        fclose(file);

    return is_open;
}

// Функция выводит информацию о наличии файла (*filename* status: X)
// если файл существует - X == Exist, иначе x == текстовое представление кода ошибки
void show_file_existence_status(const char* filename)
{
    int is_exist = is_file_exist(filename);

    // Пример использования тернарного оператора для выбора нужной строки для вывода
    char* creation_status = is_exist ? "Exist" : strerror(errno);
    printf("%s status: %s\n", filename, creation_status);
}

// Проверяет значение флага errno и возвращает информацию об ошибке
void concrete_error()
{
    printf("File error: %s\n", strerror(errno));
}
