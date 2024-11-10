#include <stdio.h>
#include "4-functions.h"

int main() {

    char str[81]; 
    
    get_input(str, sizeof(str));
    process(str);
    do_output(str);
    
    return 0;
}