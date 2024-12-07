#include <stdio.h>
#include <math.h>

int main() {

    double x1, x2, x3;

    printf("Enter the coordinate x1 (x1 < 0): ");
    scanf("%lf", &x1);

    printf("Enter the coordinate x2 (x2 < 0): ");
    scanf("%lf", &x2);

    printf("Enter the coordinate x3 (x3 < 0): ");
    scanf("%lf", &x3);

    if (x1 >= 0 || x2 >= 0 || x3 >= 0) {
        printf("Error: All points must be less than 0.\n");
        return 1;
    }

    double dot_one = fabs(x1);
    double dot_two = fabs(x2);
    double dot_three = fabs(x3);

    double min_distance = dot_one;
    int closest_point = 1;

    if (dot_two < min_distance) {
        min_distance = dot_two;
        closest_point = 2;
    }

    if (dot_three < min_distance) {
        min_distance = dot_three;
        closest_point = 3;
    }

    printf("Point x%d (x= -%.2lf) is closest to the center.\n", closest_point, min_distance);

    return 0;
}
