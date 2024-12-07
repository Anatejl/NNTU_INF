#include <stdio.h>
#include <math.h>

double sum_squares(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

double sum_xi(int n, double *x) {
    double sum = 0.0;
    for (int i = 3; i <= n; i++) {
        sum += x[i - 1];
    }
    return sum;
}

double calculate_xi(int i, int a, int b) {
    return b * log10(7.2 + i) / 2.0 + sqrt(i + a + b);
}

int main() {
    
    int n = 8;
    int a = 4, b = 2;

    double sum_sq = sum_squares(n);

    double x[n];
    for (int i = 1; i <= n; i++) {
        x[i - 1] = calculate_xi(i, a, b);
    }

    double sum_x = sum_xi(n, x);

    double r = (sum_sq - sum_x) / sqrt((n - 2) * sum_x);

    printf("r = %.2f\n", r);

    return 0;
}