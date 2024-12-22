// VAR 4

#include <stdio.h>
#include <math.h>

double calculate_Yk(int k, double A, double B, double C, double b) {
    return b * (log(10.0 * (A * k + C)) / sqrt(k + A + B));
}

double calculate_summation(int start, int end, double A, double B, double C, double b) {
    double sum = 0.0;
    for (int k = start; k <= end; k++) {
        sum += calculate_Yk(k, A, B, C, b);
    }
    return sum;
}

int main() {
    double A = 0.0;
    double B = 9.0;
    double C = 1.0;
    double b = 1.0;

    double sum1 = calculate_summation(3, 10, A, B, C, b);
    double sum2 = calculate_summation(6, 20, A, B, C, b);
    double sum3 = calculate_summation(11, 30, A, B, C, b);

    double Z = sin(sum1) + B * cos(sum2) + (C / sum3);

    printf("Z = %lf\n", Z);

    return 0;
}
