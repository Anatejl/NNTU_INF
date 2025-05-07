#include <stdio.h>
#include <assert.h>
#include "circle.h"

void test_is_outside_circle() {
    circle_t test_circle = {0.0, 0.0, 5.0};
    point_t test_points[] = {
        {6.0, 0.0},  // Outside
        {3.0, 4.0},  // On the circle
        {0.0, 0.0},  // Inside
        {5.0, 5.0},  // Outside
        {-6.0, 0.0}, // Outside
        {0.0, -5.0}, // On the circle
        {4.0, 3.0}   // Inside
    };

    int expected_results[] = {1, 0, 0, 1, 1, 0, 0};
    for (int i = 0; i < 7; i++) {
        int result = is_outside_circle(test_points[i], test_circle);
        if (result != expected_results[i]) {
            printf("Test case %d failed: Point (%.2f, %.2f), Expected %d, Got %d\n",
                   i, test_points[i].x, test_points[i].y, expected_results[i], result);
        }
        assert(result == expected_results[i]);
    }
    printf("All test cases passed!\n");
}

int main() {
    test_is_outside_circle();
    return 0;
}