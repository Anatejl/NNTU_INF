//vector.cpp
//
// Created by Anatejl on 20.04.2024.
//

#include "vector.h"
#include <iostream>

Vector vectorValueArrayInitialize(const Vector &valueArray) {

    Vector temporaryVector;
    int counter = 0;

    while (!std::cin.eof()) {

        int temporary_value_storage = 0;

        for (int k = 0; k <= counter; k++) {

            std::cin >> temporary_value_storage;
            temporaryVector.value.push_back(temporary_value_storage);

            counter++;

            if (std::cin.eof()) {
                break;
            }
        }
    }

    //Demonstrate input data
    std::cout << "Provided vector consists of " << vectorGetSize(temporaryVector) << " entries." << std::endl;
    std::cout << "Values as follows:" << std::endl;

    for (int i : temporaryVector.value) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return temporaryVector;

}

int vectorGetSize(Vector &v) {

    return v.value.size();
}
