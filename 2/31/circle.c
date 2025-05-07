#include <stdio.h>
#include "circle.h"

int is_outside_circle(point_t point, circle_t circle) {
    double distance_squared = (point.x - circle.x) * (point.x - circle.x) + (point.y - circle.y) * (point.y - circle.y);
    return distance_squared > circle.radius * circle.radius;
}

#ifndef TEST_BUILD
int main() {
    int num_points;
    circle_t circle;

    printf("Enter the circle's center (xc, yc): ");
    scanf("%lf %lf", &circle.x, &circle.y);
    printf("Enter the circle's radius (r): ");
    scanf("%lf", &circle.radius);

    printf("Enter the number of points: ");
    scanf("%d", &num_points);

    point_t points[num_points];
    printf("Enter the points (x y):\n");
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    // Form the new set of points outside the circle
    printf("Points outside the circle:\n");
    for (int i = 0; i < num_points; i++) {
        if (is_outside_circle(points[i], circle)) {
            printf("(%.2lf, %.2lf)\n", points[i].x, points[i].y);
        }
    }

    return 0;
}
#endif