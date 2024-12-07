#include <math.h>
#include <stdio.h>

int main() {

    double x0 = 2.0, xk = 3.0, h = 0.1;
    double x, y;

    printf("x\t  y\n");
    printf("---------------------\n");

    for (x = x0; x <= xk; x += h) {
        y = 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
        printf("%.2f\t %.4f\n", x, y);
    }

    return 0;
}
