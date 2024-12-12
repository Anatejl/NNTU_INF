// VAR 20
#include <stdio.h>
#include <math.h>

int main(){

    double x, y, R;

    printf("Enter x/y for the dot (x y): ");
    scanf("%lf %lf", &x, &y);

    printf("Enter raduis - R: ");
    scanf("%lf", &R);

    if (x * x + y * y <= R * R) {

        if ((y < fabs(x)) || (y > -fabs(x))) {
            printf("Dot (%.lf, %.lf) is inside the square.\n", x, y);
        } 
        else {
            printf("Dot (%.lf, %.lf) is outside the square.\n", x, y);
        }
    } 
    else {
        printf("Dot (%.lf, %.lf) is outside the ssquare.\n", x, y);
    }

    return 0;
}