#include <stdio.h>
#include <math.h>

double calculate_YK(int K, double b, double A, double C, double B) {

    double numerator = log(10.0*(A*K+C));
    double denominator = sqrt(K+A+B);

    return b * (numerator / denominator);

}

double calculate_sum(int start, int end, double b, double A, double C, double B) {

    double sum = 0.0;
    for (int K = start; K <= end; K++) {
        sum += calculate_YK(K, b, A, C, B);
    }

    return sum;
}

int main() {
    
    double b = 1, A = 0, B = 9, C = 1;
    
    double sum1 = calculate_sum(3, 10, b, A, C, B);
    double sum2 = calculate_sum(6, 20, b, A, C, B);
    double sum3 = calculate_sum(11, 30, b, A, C, B);
    
    double Z = sin(sum1)+B*cos(sum2)+(C/sum3);
    
    printf("Z = %lf\n", Z);
    
    return 0;
}