//processing.cpp
#include "application.h"

//Return square of radius in IrNumber data type.
int IrNumber::getSquareOfRadius() {

    return x * x + y * y;

}

//Fill initial vactor
auto application::app_initVector(int k) {
    std::vector<IrNumber> init_points(int k); {

        std::vector<IrNumber> initialVector(k);

        for (int i = 0; i < k; ++i) {

            std::cout << "Input set - " << i << ":" << std::endl;
            std::cin >> initialVector[i].x >> initialVector[i].y;

        }

        return initialVector;
    }
}

//Process data into final vector.
auto application::app_processVector(std::vector<IrNumber>& z, int R) {
    std::vector<IrNumber> filterZ(std::vector<IrNumber>& z, int R); {

        std::vector<IrNumber> resultNumbers;

        resultNumbers.reserve(z.size());

        for (int i = 0; i < z.size(); ++i) {

            if (z[i].getSquareOfRadius() <= R * R) {
                resultNumbers.push_back(z[i]);
            }
        }

        return resultNumbers;
    }
}