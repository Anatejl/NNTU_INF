// VAR 8

#include "5p.h"

void polar_to_cartesian(PolarPoint *polar, double *x, double *y) {
    double alpha_rad = polar->alpha * M_PI / 180.0;
    *x = polar->r * cos(alpha_rad);
    *y = polar->r * sin(alpha_rad);
}

int input_polar_points(PolarPoint *points) {
    int num_points;
    printf("Enter the number of points (up to %d): ", MAX_POINTS);
    if (scanf("%d", &num_points) != 1 || num_points <= 0 || num_points > MAX_POINTS) {
        printf("Invalid number of points.\n");
        return -1;
    }

    printf("Enter the polar coordinates (alpha r) for each point:\n");
    for (int i = 0; i < num_points; i++) {
        if (scanf("%lf %lf", &points[i].alpha, &points[i].r) != 2) {
            printf("Invalid input for point %d.\n", i + 1);
            return -1;
        }
    }
    return num_points;
}

void calculate_bounding_rectangle(PolarPoint *points, int num_points, Rectangle *rect) {
    rect->min_x = rect->min_y = INFINITY;
    rect->max_x = rect->max_y = -INFINITY;
    double x, y;

    for (int i = 0; i < num_points; i++) {
        polar_to_cartesian(&points[i], &x, &y);

        if (x < rect->min_x) rect->min_x = x;
        if (x > rect->max_x) rect->max_x = x;
        if (y < rect->min_y) rect->min_y = y;
        if (y > rect->max_y) rect->max_y = y;
    }
}

void output_rectangle(Rectangle *rect) {
    printf("Bounding Rectangle:\n");
    printf("Min X: %.2lf\n", rect->min_x);
    printf("Max X: %.2lf\n", rect->max_x);
    printf("Min Y: %.2lf\n", rect->min_y);
    printf("Max Y: %.2lf\n", rect->max_y);
}

int main() {

    PolarPoint points[MAX_POINTS];
    Rectangle rect;

    int num_points = input_polar_points(points);
    if (num_points == -1) {
        return 1;
    }

    calculate_bounding_rectangle(&points, num_points, &rect);
    output_rectangle(&rect);

    return 0;
}