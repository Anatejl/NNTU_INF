//
// Created by Anatejl on 05.11.2022.
//
//Task 4 - Var 14

#include <stdio.h>
#include <string.h>

int main() {

    double k, final;
    const char *s;

    printf("Input a line, followed by a number:");
    scanf_s("%lf", &s);
    scanf_s("%lf", &k);

    int i, size = strlen(s);
    if (k >= size) {
        memset(s, '\0', size);
        return 0;
    }

    for (i = 0; i < size - k; i++) {
        s[i] = s[i + k];
        s[i + k] = '\0';
    };

    printf(shiftLeft)

}


return 0;
}
