#include "4p.h"

void func_input(char *str) {

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {

        str[len - 1] = '\0';

    }

}

void func_process(char *str, int *word_count) {

    *word_count = 0;
    bool in_word = false;

    while (*str != '\0') {

        if (!isspace(*str)) {

            if (!in_word) {

                in_word = true;
                (*word_count)++;

            }

        } 
        else {

            in_word = false;

        }

        str++;

    }

}

void func_output(int *word_count) {

    printf("The number of words is: %d\n", *word_count);

}

int main() {

    char input[MAX_LENGTH];
    int word_count;

    func_input(input);
    func_process(input, &word_count);
    func_output(&word_count);

    return 0;
}
