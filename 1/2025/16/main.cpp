#include "header.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

rect compute_bounding_rect(const std::vector<std::pair<double,double>> &points){
    const double deg2rad = M_PI / 180.0;

    rect r;
    r.min_x = std::numeric_limits<double>::infinity();
    r.max_x = -std::numeric_limits<double>::infinity();
    r.min_y = std::numeric_limits<double>::infinity();
    r.max_y = -std::numeric_limits<double>::infinity();

    for (const std::pair<double,double> &p : points){
        double R = p.first;
        double alpha = p.second;
        // alpha is always provided in degrees in this program
        alpha *= deg2rad;

        double x = R * std::cos(alpha);
        double y = R * std::sin(alpha);

        if (x < r.min_x) r.min_x = x;
        if (x > r.max_x) r.max_x = x;
        if (y < r.min_y) r.min_y = y;
        if (y > r.max_y) r.max_y = y;
    }

    return r;
}

int main() {

    int n;
    // Ask the user how many polar points will be entered
    std::cout << "Enter number of points: " << std::endl;
    // Read N and validate it is positive
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid number of points" << std::endl;
        return 1;
    }

    // Read points into a vector (junior-friendly but using STL)
    std::vector<std::pair<double,double>> points;
    points.reserve(n);

    // Prompt user to enter each polar point as `R alpha_deg` (degrees)
    std::cout << "Enter points (R alpha_deg), one per line:" << std::endl;
    for (int i = 0; i < n; ++i) {
        double r, alpha_deg;
        std::cout << "Point " << (i+1) << ": " << std::endl;
        // Read R and alpha (in degrees) for this point
        if (!(std::cin >> r >> alpha_deg)) {
            std::cerr << "Invalid input at point " << i << std::endl;
            return 1;
        }
        // Store the raw polar pair; conversion happens in the compute function
        points.emplace_back(r, alpha_deg);
    }

    // Compute the bounding rectangle from the list of polar points
    // alpha values are expected in degrees
    rect result = compute_bounding_rect(points);

    // If rectangle seems invalid, report and exit (guard against empty input)
    if (!result.valid()){
        std::cout << "No points or invalid rectangle." << std::endl;
        return 0;
    }

    std::cout << std::fixed << std::setprecision(6);

    // Print rectangle edges and derived quantities
    std::cout << "Bounding rectangle (axis-aligned):" << std::endl;
    std::cout << "  left  = " << result.min_x << std::endl;
    std::cout << "  right = " << result.max_x << std::endl;
    std::cout << "  bottom= " << result.min_y << std::endl;
    std::cout << "  top   = " << result.max_y << std::endl;

    // Width, height and area computed from edges
    std::cout << "Width  = " << (result.max_x - result.min_x) << "  Height = " << (result.max_y - result.min_y) << std::endl;
    std::cout << "Area   = " << ((result.max_x - result.min_x) * (result.max_y - result.min_y)) << std::endl;

    return 0;
}