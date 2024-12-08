#include <stdio.h>
#include <math.h>

int main() {

    double x, y, R;

    printf("Enter the coords for the dot (x, y): ");
    scanf("%lf %lf", &x, &y);
    printf("Enter the radius R: ");
    scanf("%lf", &R);

    if (x * x + y * y <= R * R) {

        if ((y > fabs(x)) || (y < -fabs(x))) {
            printf("Dot (%.2lf, %.2lf) is inside the region.\n", x, y);
        } 
        else {
            printf("Dot (%.2lf, %.2lf) is outside the region.\n", x, y);
        }
    } 
    else {
        printf("Dot (%.2lf, %.2lf) is outside the region.\n", x, y);
    }

    return 0;
}