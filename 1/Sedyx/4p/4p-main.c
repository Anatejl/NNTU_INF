#include "4p-header.h"

int main() {
    
    char source_string[100], remove_string[100];

    do_input(source_string, remove_string);
    do_process(source_string, remove_string);
    do_output(source_string);

    return 0;
}
