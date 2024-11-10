#include "4-array-functions.h"

void get_input(char str[81]) {
    printf("Enter a string (up to 80 characters): ");
    fgets(str, 81, stdin);
    
    str[strcspn(str, "\n")] = '\0';
}
