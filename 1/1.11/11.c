#include <stdio.h>
#include <string.h>

struct Point {
    double x;
    double y;
};

int main() {

    struct Point A = { 1.1, 2.2 };
    printf("Point A =  %f %f\n", A.x, A.y );

    struct Point B;
    B.x = -5.5;
    B.y = -8.1;
    printf("Point B = %f %f\n", B.x, B.y );
    struct Point * ptrPoint;
    ptrPoint = &A;
    printf("Point A = %f %f\n", ptrPoint->x, ptrPoint->y );
    ptrPoint = &B;
    printf("Point B = %f %f\n", (*ptrPoint).x, (*ptrPoint).y );

    printf("Point C = %f %f\n", B.x, B.y );

    return 0;
}