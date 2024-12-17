// VAR 20
#include <stdio.h>
#include <math.h>

int main(){

    double x, y, R;

    printf("Enter x/y for the dot (x y): ");
    scanf("%lf %lf", &x, &y);

    printf("Enter raduis - R: ");
    scanf("%lf", &R);

    if ((x * x + y * y <= R * R) && (fabs(x) + fabs(y) <= R)) {
        printf("The point (%.2lf, %.2lf) is inside region.\n", x, y);
    } 
    else {
        printf("The point (%.2lf, %.2lf) is outside region.\n", x, y);
    }

    return 0;
}