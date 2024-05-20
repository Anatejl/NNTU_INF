//
// Created by Anatejl on 20.04.2024.
//

#include "vector.h"
#include <iostream>

initialVector vectorInitialArrayInitialize(const initialVector &initialArray) {
    initialVector temporaryVector;

    while (true) {
        std::pair<double, double> tempCIN;

        for (int i = 0;; ++i) {
            if (!std::cin.eof()) {
                ++temporaryVector.counter;
                std::cin >> tempCIN.first;

                if (!std::cin.eof()) {
                    std::cin >> tempCIN.second;
                } else {
                    break;
                }
            } else {
                break;
            }

            temporaryVector.row.push_back(tempCIN);
        }
        break;
    }

    return temporaryVector;
}

int vectorGetSize(initialVector &v) {
    return v.row.size();
}
