//processing.cpp
#include "header.h"

std::vector<IrNumber> filterZ(std::vector<IrNumber>& z, int R) {

    std::vector<IrNumber> resultNumbers;

    resultNumbers.reserve(z.size());

    for (int i = 0; i < z.size(); ++i) {

        if (z[i].getSquareOfRadius() <= R * R) {
            resultNumbers.push_back(z[i]);
        }
    }

    return resultNumbers;
}