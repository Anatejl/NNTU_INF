//
// Created by Anatejl on 21.12.2022.
//

#include <stdio.h>
#include <stdlib.h>

void main() {
    system("chcp 1251 > nul");

    int i;
    float a[6];

    a[0] = 20;
    for (i = 1; i <= 5; i++) {
        a[i] = a[i - 1] / 2 + a[i - 1];
    }

    printf("Элементы вектора a:\n");
    for (i = 0; i <= 5; i++) {
        printf("%0.1f ", a[i]);
    }

    printf("\n\n");

    system("pause");
}