#ifndef VAR_16
#define VAR_16

#include <vector>
#include <utility>

// Minimal header for exercise 16.
// Expose a small `rect` type and a compute function prototype.

typedef struct rect {
	double min_x;
	double max_x;
	double min_y;
	double max_y;
	// Simplified validity: check only x-range is valid (sufficient for this exercise)
	bool valid() const { return min_x <= max_x; }
} rect;

// Compute bounding rectangle from polar points (R, alpha).
// Implemented in `main.cpp` to keep header simple.
rect compute_bounding_rect(const std::vector<std::pair<double,double>> &points, bool degrees = true);

#endif //VAR_16