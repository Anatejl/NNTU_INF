#ifndef EX16_RECT_H
#define EX16_RECT_H

#include <vector>
#include <utility>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

typedef struct rect {
	double min_x;
	double max_x;
	double min_y;
	double max_y;
	bool valid() const { return min_x <= max_x; }
} rect;

rect process_compute_rect(const std::vector<std::pair<double,double>> &points);

bool input(std::vector<std::pair<double,double>> &points);

bool output(const rect &result);

#endif // EX16_RECT_H