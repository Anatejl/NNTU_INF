#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data.h"
#include "array.c"

void process_count() {

    for (int i = 0; i < CIRCLES_MAX; i++) {
        circleRadius[i].R = sqrt(
                pow(circleCode[i].a - circleCode[i].x, 2) +
                pow(circleCode[i].b - circleCode[i].y, 2));
        printf("\nrad - %f\n", circleRadius[i].R);
    }
}

void getInput() {

    printf("\nWelcome to dot count program!\n");
    printf("\nPerquisites are:\n %d circles, with start in %d,%d.\n", CIRCLES_MAX-1, circleCode[0].x, circleCode[0].y);
    printf(" Radius of circle is counted from order number multiplied by 2 (e.g. 3rd circle has radius of 6).");

    for (int i = 0; i < INPUT_MAX_DOTS; i++) {

        printf("\nInput %d/%d set of coordinates (x y):", i + 1, INPUT_MAX_DOTS);
        scanf_s("%d", &inputDot[i].x);
        scanf_s("%d", &inputDot[i].y);
    }
    fflush(stdin);
}

int *process_compare() {

    int *resultValue = malloc(sizeof(int *));
    *resultValue = 0;

    for (int i = 0; i < INPUT_MAX_DOTS; i++) {

        for (int j = 0; j < CIRCLES_MAX; j++) {

            double line = sqrt(pow(inputDot[i].x - circleCode[j].x, 2) +
                                  pow(inputDot[i].y - circleCode[j].y, 2));
            //printf("\nline %.2f\n", line);
            if (line < circleRadius[j].R) {

                (*resultValue)++;
                printf("%d. Dot %d (%d, %d) interfere circle with radius of %0.f.\n",
                       *resultValue, i+1, inputDot[i].x, inputDot[i].y, circleRadius[j].R);
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