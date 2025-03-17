#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct app_backbone{
    int input_string_length;
    char string[];
}app_backbone;

int app_count_string_length(char* string);
void app_convert_to_lowercase(char* string, int length);