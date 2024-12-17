// VAR 24
#include <stdio.h>
#include <math.h>

int main(){

    double x, y, R;

    printf("Enter the coords for the dot (x, y): ");
    scanf("%lf %lf", &x, &y);
    printf("Enter the radius R: ");
    scanf("%lf", &R);

    if ((x * x + y * y <= R * R) && (fabs(x) + fabs(y) > R / sqrt(2))) {
        printf("The point (%.2lf, %.2lf) is ok.\n", x, y);
    } 
    else {
        printf("The point (%.2lf, %.2lf) is outside the region.\n", x, y);
    }

    return 0;
}