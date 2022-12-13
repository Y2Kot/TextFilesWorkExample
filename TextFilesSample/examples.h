#ifndef EXAMPLES_H
#define EXAMPLES_H

#include <stdlib.h>
#include "base_operations.h"
#include "read_write_operations.h"
#include "read_write_operations_struct.h"

#define WRITE_TEXT_DATA "Line 1\nLine 2\nThis is line 3\nLeft\t\t\tRight\n\n"
#define FIVE 5
#define PI 3.14159265359
#define TEXT_DATA "FIVE is not PI"
#define READ_DATA_MAX_SIZE 10

void show_existance_samples();
void show_write_examples();
void show_write_read_example();
void count_lines_example();
void read_and_write_structure_example();
void read_and_write_structure_multiline_example_with_allocation();

#endif // EXAMPLES_H
