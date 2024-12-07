#include "4p-header.h"

void do_process(char *source_string, char *remove_string) {
    
    int character_flags[256] = {0};
    char *read_ptr = remove_string;

    while (*read_ptr) {
        character_flags[(unsigned char)*read_ptr] = 1;
        read_ptr++;
    }

    char *read_source = source_string; 
    char *write_source = source_string;

    while (*read_source) {
        if (!character_flags[(unsigned char)*read_source]) {
            *write_source = *read_source;
            write_source++;
        }
        read_source++;
    }
    *write_source = '\0';
}