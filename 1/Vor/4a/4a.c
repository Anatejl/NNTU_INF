#include "4a.h"

void func_input(char str[MAX_LENGTH]) {

    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    int len = strlen(str);

    if (len > 0 && str[len - 1] == '\n') {

        str[len - 1] = '\0';

    }

}

void func_process(const char str[MAX_LENGTH], int word_count[1]) {

    word_count[0] = 0;
    bool in_word = false;

    for (int i = 0; str[i] != '\0'; i++) {

        if (!isspace(str[i])) {

            if (!in_word) {

                in_word = true;
                word_count[0]++;
                
            }

        } 
        else {

            in_word = false;

        }

    }

}

void func_output(int word_count[1]) {

    printf("The number of words is: %d\n", word_count[0]);

}

int main() {

    char input[MAX_LENGTH];
    int word_count[1];

    func_input(input);
    func_process(input, word_count);
    func_output(word_count);

    return 0;
}