#include "examples.h"

void show_header(const char* text)
{
    printf("\n%s\n", text);
}
void show_existance_samples()
{
    show_header("show_existance_samples");
    // Пример относительного пути - файл ищется в текущей РАБОЧЕЙ директории (директории с исполняемым файлом)
    show_file_existence_status("example_2.txt");

    // Пример относительного пути - двоеточие является переходом в родительскую директорию относительно текущей рабочей директории,
    // затем переходит в директорию example_1__create_file, где т проверяем существования файла с именем example_1.txt
    // !!! Будет выводить +, если был предварительно запущен без изменения в Qt Сreator пример example_1__create_file с успешным созданием файла
    show_file_existence_status("../example_1__create_file/example_1.txt");

    // Пример абсолютного пути - стоит обратить внимание на двойные обратные косые черты
    show_file_existence_status("C:\\Windows\\system.ini");

    // Пример абсолютного пути через одинарные прямые черты
    show_file_existence_status("C:/Windows/system.ini");

    // Стоит попробовать свои имена файлов
    //show_file_existence_status("");
}

void show_write_examples()
{
    show_header("show_write_examples");
    int status1 = file_write_text_fputs(WRITE_TEXT_DATA, "file_fputs.txt");
    if (status1)
        concrete_error();
    int status2 = file_write_text_fread(TEXT_DATA, "file_fread.txt");
    if (status2)
        concrete_error();
}

void show_write_read_example()
{
    show_header("show_write_read_example");
    /* ЗАПИСЬ */
    unsigned ratings[] = {9, 5, 8, 7, 4, 3};
    unsigned ratings_size = sizeof(ratings) / sizeof(ratings[0]);

    int write_status = write_ratings(ratings, ratings_size, "example_4.txt");
    if (write_status != 0)
        concrete_error();

    /* ЧТЕНИЕ */
    unsigned read_data[READ_DATA_MAX_SIZE];
    unsigned read_ratings_size = read_ratings(read_data, READ_DATA_MAX_SIZE, "example_4.txt");

    printf("Read count: %u\n", read_ratings_size);
    for (unsigned i = 0; i != read_ratings_size; i++)
        printf("%u ", read_data[i]);
    printf("\n");
}

void count_lines_example()
{
    show_header("count_lines_example");

    int lines = count_lines("example_4.txt");
    if (lines == -1)
        concrete_error();
    else
        printf("file contains %d line(s)\n", lines);
    lines = count_lines("file_fputs.txt");
    if (lines == -1)
        concrete_error();
    else
        printf("file contains %d line(s)\n", lines);

}

void read_and_write_structure_example()
{
    show_header("read_and_write_structure_example");

    /* ЗАПИСЬ */
    // !!! Обратите внимание, что в названии книги отсутствуют пробельные символы, так как
    // fscanf в чтении для %s будет считывать до ПЕРВОГО пробельного символа (аналогично функции scanf).
    // !!! Вторая книга book_2 перезапишет в файле первую book_1, так как стоит режим "w".
    // !!! Для записи нескольких данных файл нужно ИЛИ поменять режим открытия - что будет плохо из-за
    // постоянного открытия файла, ИЛИ записать все данные всего за одно открытие (делать НУЖНО именно так),
    // для этого нужно пересмотреть декомпозацию для такой многоразовой записи.
    Book book_1 = { 120, 2022, "Test_book" };
    if (write_book(&book_1, "example_5.txt") != 0)
        concrete_error();

    Book book_2 = { 288, 2020, "The_C_Programming_Language_(Second_Edition)" };
    if (write_book(&book_2, "example_5.txt") != 0)
        concrete_error();

    /* ЧТЕНИЕ */
    Book reading_book;
    if (read_book(&reading_book, "example_5.txt") != 0)
        concrete_error();
    else
        show_book(&reading_book);
}

void read_and_write_structure_multiline_example_with_allocation()
{
    show_header("read_and_write_structure_multiline_example_with_allocation");

    Book book_1 = { 120, 2022, "Test book" };
    Book book_2 = { 288, 2020, "The C Programming Language (Second Edition)" };
    Book** books = allocate_books(BOOK_COUNT);
    books[0] = &book_1;
    books[1] = &book_2;

    if (write_books_multiline(books, BOOK_COUNT, "example_6_m.txt") != 0)
        concrete_error();

    /* ЧТЕНИЕ */
    Book** reading_books = allocate_books(BOOK_COUNT);
    if (read_books_multiline(reading_books, BOOK_COUNT, "example_6_m.txt") != 0)
        concrete_error();
    else
        show_books(reading_books, BOOK_COUNT);

    free(books);
    free(reading_books);
}
