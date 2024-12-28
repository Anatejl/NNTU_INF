// VAR 14
#include <stdio.h>
#include <math.h>

#define A 1.5
#define B 2
#define C 3
#define a 1

double calculate_y_k(int k) {
    return (a * (k * k + B * k)) / (A * k * k + C * k + B);
}

double calculate_sum1() {
    double sum = 0;
    for (int k = 1; k <= 5; k++) {
        sum += 0.2 * calculate_y_k(k);
    }
    return sum;
}

double calculate_sum2() {
    double sum = 0;
    for (int k = 3; k <= 15; k++) {
        sum += calculate_y_k(k);
    }
    return sum;
}

double calculate_sum3() {
    double sum = 0;
    for (int k = 4; k <= 10; k++) {
        sum += calculate_y_k(k);
    }
    return sum;
}

double calculate_z() {
    double sum1 = calculate_sum1();
    double sum2 = calculate_sum2();
    double sum3 = calculate_sum3();

    double z = A * log(sum1) + B * sum2 + C / (15 * sum3);
    return z;
}

int main() {
    double z = calculate_z();
    printf("Z is: %.6f\n", z);
    return 0;
}