#include <stdio.h>
#include <stdlib.h>

int main() {

    double a, b, c, d, k, min, max;

    system("chcp 1251 > nul"); // Строка дублирует ввод в консоли.

    printf("Введите последовательность (a, b, c, d, k): ");
    scanf_s("%lf", &a);
    scanf_s("%lf", &b);
    scanf_s("%lf", &c);
    scanf_s("%lf", &d);
    scanf_s("%lf", &k);

    if (c > d && c > k) {
        max = c;
    } else if (c < d && d > k) {
        max = d;
    } else {
        max = k;
    }

    if (a < b) {
        min = a;
    } else {
        min = b;
    }

    if (min < max) {
        printf("%.1f\n", max);
    } else {
        printf("%.1f\n", min);
    }

    system("pause");

    return 0;
}