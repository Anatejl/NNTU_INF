// VAR 14
#include <stdio.h>
#include <math.h>

double calculate_xi(int i, double a, double b) {
    return b * (log10(7.2 + i) / 2 + sqrt(i + a + b));
}

double calculate_sum(int start, int end, double a, double b) {
    double sum = 0;
    for (int i = start; i <= end; i++) {
        sum += calculate_xi(i, a, b);
    }
    return sum;
}

int main() {
    int n = 8;
    double a = 4.0, b = 2.0;

    double sum_1_to_n = calculate_sum(1, n, a, b);
    double numerator = pow(sum_1_to_n, 2) / n;

    double sum_3_to_n = calculate_sum(3, n, a, b);
    double second_term = sum_3_to_n / n;

    double sum_4_to_n = calculate_sum(4, n, a, b);
    double denominator = sqrt((n - 2) * sum_4_to_n);

    double r = (numerator - second_term) / denominator;

    printf("Result (r) = %lf\n", r);

    return 0;
}