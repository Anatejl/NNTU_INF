#include "header.h"

rect process_compute_rect(const std::vector<std::pair<double,double>> &points){
    
    const double deg2rad = M_PI / 180.0;

    rect r;
    r.min_x = std::numeric_limits<double>::infinity();
    r.max_x = -std::numeric_limits<double>::infinity();
    r.min_y = std::numeric_limits<double>::infinity();
    r.max_y = -std::numeric_limits<double>::infinity();

    for (const std::pair<double,double> &p : points){
        double R = p.first;
        double alpha = p.second;

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

bool input(std::vector<std::pair<double,double>> &points){
    
    int n;
    std::cout << "Enter number of points: " << std::endl;
    
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Invalid number of points" << std::endl;
        return false;
    }

    points.clear();
    points.reserve(n);
    std::cout << "Enter points (R alpha_deg), one per line:" << std::endl;
    
    for (int i = 0; i < n; ++i) {
        double r, alpha_deg;
        std::cout << "Point " << (i+1) << ": " << std::endl;
        if (!(std::cin >> r >> alpha_deg)) {
            std::cerr << "Invalid input at point " << (i + 1) << std::endl;
            return false;
        }
        points.emplace_back(r, alpha_deg);
    }
    
    return true;
}

bool output(const rect &result){

    if (!result.valid()){
        std::cout << "No points or invalid rectangle." << std::endl;
        return false;
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Bounding rectangle (axis-aligned):" << std::endl;
    std::cout << "  left  = " << result.min_x << std::endl;
    std::cout << "  right = " << result.max_x << std::endl;
    std::cout << "  bottom= " << result.min_y << std::endl;
    std::cout << "  top   = " << result.max_y << std::endl;
    std::cout << "Width  = " << (result.max_x - result.min_x) << "  Height = " << (result.max_y - result.min_y) << std::endl;
    std::cout << "Area   = " << ((result.max_x - result.min_x) * (result.max_y - result.min_y)) << std::endl;
    
    return true;
}

int main() {
    
    std::vector<std::pair<double,double>> points;

    if (!input(points)){
        return 1;
    }

    rect result = process_compute_rect(points);
    
    if (!output(result)){
        return 0;
    }

    return 0;
}