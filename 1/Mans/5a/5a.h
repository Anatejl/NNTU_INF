// VAR 8

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double alpha; 
    double r;     
} PolarPoint;

typedef struct {
    double min_x;
    double max_x;
    double min_y;
    double max_y;
} Rectangle;

void polar_to_cartesian(PolarPoint polar, double cartesian[2]);
int input_polar_points(PolarPoint points[]);
Rectangle calculate_bounding_rectangle(PolarPoint points[], int num_points);
void output_rectangle(Rectangle rect);