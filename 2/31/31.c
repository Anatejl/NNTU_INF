#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} point_t;

typedef struct {
    double x;
    double y;
    double radius;
} circle_t;

// Function to check if a point is outside the circle
int is_outside_circle(point_t point, circle_t circle) {
    double distance_squared = (point.x - circle.x) * (point.x - circle.x) + (point.y - circle.y) * (point.y - circle.y);
    return distance_squared > circle.radius * circle.radius;
}

int main() {
    int num_points;
    circle_t circle;

    // Input the circle's center and radius
    printf("Enter the circle's center (xc, yc): ");
    scanf("%lf %lf", &circle.x, &circle.y);
    printf("Enter the circle's radius (r): ");
    scanf("%lf", &circle.radius);

    // Input the number of points
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