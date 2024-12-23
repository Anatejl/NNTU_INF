// VAR 8

#include "5a.h"

void polar_to_cartesian(PolarPoint polar, double cartesian[2]) {
    double alpha_rad = polar.alpha * M_PI / 180.0; 
    cartesian[0] = polar.r * cos(alpha_rad);
    cartesian[1] = polar.r * sin(alpha_rad);
}

int input_polar_points(PolarPoint points[]) {
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

Rectangle calculate_bounding_rectangle(PolarPoint points[], int num_points) {
    Rectangle rect;
    rect.min_x = rect.min_y = INFINITY;
    rect.max_x = rect.max_y = -INFINITY;
    double cartesian[2];

    for (int i = 0; i < num_points; i++) {
        polar_to_cartesian(points[i], cartesian);

        if (cartesian[0] < rect.min_x) rect.min_x = cartesian[0];
        if (cartesian[0] > rect.max_x) rect.max_x = cartesian[0];
        if (cartesian[1] < rect.min_y) rect.min_y = cartesian[1];
        if (cartesian[1] > rect.max_y) rect.max_y = cartesian[1];
    }
    return rect;
}

void output_rectangle(Rectangle rect) {
    printf("Bounding Rectangle:\n");
    printf("Min X: %.2lf\n", rect.min_x);
    printf("Max X: %.2lf\n", rect.max_x);
    printf("Min Y: %.2lf\n", rect.min_y);
    printf("Max Y: %.2lf\n", rect.max_y);
}

int main() {

    PolarPoint points[MAX_POINTS];

    int num_points = input_polar_points(points);
    if (num_points == -1) {
        return 1; 
    }

    Rectangle rect = calculate_bounding_rectangle(points, num_points);
    output_rectangle(rect);

    return 0;
}