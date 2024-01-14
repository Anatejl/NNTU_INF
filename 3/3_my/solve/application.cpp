//application.cpp

#include "IrNumber.h"

int application::app_run() {

    int n, R;

    std::cout << "Input n:" << std::endl;
    std::cin >> n;

    auto points = app_initVector(n);

    std::cout << "Input R:" << std::endl;
    std::cin >> R;

    auto finalVector = app_processVector(points, R);

    for (int i = 0; i < finalVector.size(); ++i) {

        std::cout << "{" << finalVector[i].x << ", " << finalVector[i].y << "}; " << std::endl;

    };

    return 0;
}

