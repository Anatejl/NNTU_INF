#include "4-array-functions.h"

void get_input(char *str, int length) {

    printf("Enter a string (up to %d characters): ", length - 1);
    fgets(str, length, stdin);
    
    str[strcspn(str, "\n")] = 0;
}