cmake_minimum_required(VERSION 3.5)

project(TextFilesSample LANGUAGES C)

add_executable(TextFilesSample main.c
    base_operations.h base_operations.c
    read_write_operations.h read_write_operations.c
    read_write_operations_struct.h read_write_operations_struct.c
    examples.h examples.c
)

install(TARGETS TextFilesSample
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
