#include "4-array-functions.h"

void do_process(char str[81]) {
    int length = strlen(str);
    
    // Reverse the string in-place
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}
