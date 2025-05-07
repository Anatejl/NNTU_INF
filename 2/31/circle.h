#ifndef CIRCLE_H
#define CIRCLE_H

typedef struct {
    double x;
    double y;
} point_t;

typedef struct {
    double x;
    double y;
    double radius;
} circle_t;

int is_outside_circle(point_t point, circle_t circle);

#endif // CIRCLE_H