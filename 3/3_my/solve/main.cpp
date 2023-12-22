#include "header.h"
#include "initVector.cpp"
#include "processing.cpp"

int main() {

    int n, R;

    std::cout << "Input n:" << std::endl;
    std::cin >> n;
    auto points = init_points(n);

    std::cout << "Input R:" << std::endl;
    std::cin >> R;

    auto finalVector = filterZ(points, R);

    for (int i = 0; i < finalVector.size(); ++i) {
        std::cout << "{" << finalVector[i].x << ", " << finalVector[i].y << "}; " << std::endl;

    };

    return 0;
}
