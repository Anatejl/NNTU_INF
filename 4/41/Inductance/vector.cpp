//
// Created by Anatejl on 20.04.2024.
//

#include "vector.h"
#include <iostream>

Vector vectorInitialArrayInitialize(const Vector &initialArray) {

    int tempFirst = 0, tempSecond = 0;
    Vector temporaryVector;
    temporaryVector.counter = 0;

    while (!std::cin.eof()) {

        if (!std::cin.eof()) {
            std::cin >> tempFirst;
        }
        if (!std::cin.eof()) {
            std::cin >> tempSecond;
        } else {
            tempSecond = INT_MAX;
        }

        temporaryVector.value.push_back(std::make_pair(tempFirst, tempSecond)); // NOLINT(*-use-emplace)

        temporaryVector.counter++;

        if (std::cin.eof()) {
            break;
        }
    }

    if (temporaryVector.value[temporaryVector.counter-1].second == INT_MAX) {

        temporaryVector.value.pop_back();
        std::cout << "ATTENTION: Last X coordinate doesn't pair an Y, so it was destroyed." << std::endl;

    }

    //Demonstrate input data
    std::cout << "Provided vector consists of " << vectorGetSize(temporaryVector) << " pairs." << std::endl;
    std::cout << "Pairs of X/Y as follows:" << std::endl;

    for (int i = 0; i < vectorGetSize(temporaryVector); ++i) {
        std::cout << temporaryVector.value[i].first << "/" << temporaryVector.value[i].second << " ";
    }
    std::cout << std::endl;

    return temporaryVector;

}

int vectorGetSize(Vector &v) {

    return v.value.size();
}
