#ifndef CIRCLE_H
#define CIRCLE_H

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    double x;
    double y;
} point_t;

typedef struct {
    double x;
    double y;
    double radius;
} circle_t;

bool is_outside_circle(point_t point, circle_t circle);

#endif // CIRCLE_H