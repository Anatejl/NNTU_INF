#include "header.h"

std::vector<IrNumber> init_points(int k) {

    std::vector<IrNumber> initialVector(k);

    for (int i = 0; i < k; ++i) {

        std::cout << "Input set - " << i << ":" << std::endl;
        std::cin >> initialVector[i].x >> initialVector[i].y;
    }

    return initialVector;
}