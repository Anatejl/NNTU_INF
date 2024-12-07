#include "4p-header.h"

void do_input(char *source_string, char *remove_string) {

    printf("Enter the source string: ");
    fgets(source_string, 100, stdin);
    source_string[strcspn(source_string, "\n")] = '\0';

    printf("Enter the string with characters to remove: ");
    fgets(remove_string, 100, stdin);
    remove_string[strcspn(remove_string, "\n")] = '\0';

}