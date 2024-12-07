#include "4a-header.h"

void do_process(char s1[], char s2[]) {

    int char_map[256] = {0};
    for (int i = 0; s2[i] != '\0'; i++) {
        char_map[(unsigned char)s2[i]] = 1;
    }

    int new_index = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (!char_map[(unsigned char)s1[i]]) {
            s1[new_index++] = s1[i];
        }
    }
    s1[new_index] = '\0';

}