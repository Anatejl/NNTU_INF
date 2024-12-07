#include "4a-header.h"

void do_input(char s1[], char s2[]) {

    printf("Enter the first string (s1): ");
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = '\0';

    printf("Enter the second string (s2): ");
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = '\0';

}