#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data.h"
#include "array.c"

void process_count() {

    for (int i = 0; i < CIRCLES_MAX; i++) {
        circleMaster[i].R = sqrt(
                pow(circleMaster[i].a - circleMaster[i].x, 2) +
                pow(circleMaster[i].b - circleMaster[i].y, 2));
    }
}

void getInput() {

    printf("\nWelcome to dot count program!\n");
    printf("\nPerquisites are:\n %d circles, with start in %d,%d.\n", CIRCLES_MAX - 1, circleMaster[0].x,
           circleMaster[0].y);
    printf(" Radius of circle is counted from order number multiplied by 2 (e.g. 3rd circle has radius of 6).");

    for (int i = 0; i < INPUT_MAX_DOTS; i++) {

        printf("\nInput %d/%d set of coordinates (x y):", i + 1, INPUT_MAX_DOTS);
        scanf_s("%d", &inputDot[i].a);
        scanf_s("%d", &inputDot[i].b);
    }
    fflush(stdin);
}

int *process_compare() {

    int *resultValue = malloc(sizeof(int *));
    *resultValue = 0;

    for (int i = 0; i < INPUT_MAX_DOTS; i++) {

        for (int j = 0; j < CIRCLES_MAX; j++) {

            double line = sqrt(pow(inputDot[i].a - circleMaster[j].x, 2) +
                               pow(inputDot[i].b - circleMaster[j].y, 2));
            if (line < circleMaster[j].R) {

                (*resultValue)++;
                printf("%d. Dot %d (%d, %d; Radius: %.1f) interfere circle with radius of %0.f.\n",
                       *resultValue, i + 1, inputDot[i].a, inputDot[i].b, line, circleMaster[j].R);
            }

        }
        printf("---\n");
    }

    return resultValue;
}

void getOutput(int resultValue) {

    printf("\nDots interfere total of %d circles.\n", resultValue);

}

int main() {

    circlesArray();
    process_count();

    getInput();

    int *processedValue = process_compare();

    getOutput(*processedValue);

    printf("\nPress any key to close...\n");
    getchar();

    fflush(stdin);
    free(processedValue);

    return 0;
}