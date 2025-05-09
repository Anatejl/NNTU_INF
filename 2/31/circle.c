#include "circle.h"

bool is_outside_circle(point_t point, circle_t circle) {
    double distance_squared = (point.x - circle.x) * (point.x - circle.x) + (point.y - circle.y) * (point.y - circle.y);
    if (distance_squared > circle.radius * circle.radius) {
        return true;
    } else {
        return false;
    }
}

#ifndef TEST_BUILD
int main() {
    
    circle_t circle;
    
    printf("Enter the circle's center (xc, yc): \n");
    scanf("%lf %lf", &circle.x, &circle.y);
    printf("Enter the circle's radius (r): \n");
    scanf("%lf", &circle.radius);
    
    int num_points;
    printf("Enter the number of points: \n");
    scanf("%d", &num_points);
    
    point_t points[num_points];
    printf("Enter the points (x y):\n");
    for (int i = 0; i < num_points; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    point_t outside_points[num_points];
    int outside_count = 0;

    for (int i = 0; i < num_points; i++) {
        if (is_outside_circle(points[i], circle)) {
            outside_points[outside_count++] = points[i];
        }
    }

    if (outside_count == 0) {
        printf("No points are outside the circle.\n");
    } else {
        printf("Points outside the circle:\n");
        for (int i = 0; i < outside_count; i++) {
            printf("(%.2lf, %.2lf)\n", outside_points[i].x, outside_points[i].y);
        }
    }

    return 0;
}
#endif