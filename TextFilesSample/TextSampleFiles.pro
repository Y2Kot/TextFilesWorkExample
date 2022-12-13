TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.c \
        base_operations.h base_operations.c \
        read_write_operations.h read_write_operations.c \
        read_write_operations_struct.h read_write_operations_struct.c \
        examples.h examples.c
