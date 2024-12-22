// VAR 12

#include <stdio.h>

int main(){

    double x = 0.5;
    int n_limit = 7;
    double L[n_limit];

    L[0] = 1;
    printf("L1(%.1lf) = %lf\n", x, L[0]);

    L[1] = 1 - x;
    printf("L2(%.1lf) = %lf\n", x, L[1]);

    for (int n = 2; n < n_limit; n++) {
        L[n] = (x - (2 * n + 1)) * L[n - 1] - (n - 1) * (n - 1) * L[n - 2];
        printf("L%d(%.1lf) = %lf\n", n+1, x, L[n]);
    }
    
    return 0;
}