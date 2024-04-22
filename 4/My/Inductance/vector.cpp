//
// Created by Anatejl on 20.04.2024.
//

#include "vector.h"
#include <iostream>

Vector vectorValueArrayInitialize(const Vector &valueArray) {

    Vector temporaryVector;
    temporaryVector.counter = 0;

    while (!std::cin.eof()) {

        int temporary_value_storage = 0;

        for (int k = 0; k <= temporaryVector.counter; k++) {

            std::cin >> temporary_value_storage;
            temporaryVector.value.push_back(temporary_value_storage);

            temporaryVector.counter++;

            if (std::cin.eof()) {
                break;
            }
        }
    }

    return temporaryVector;

}

Vector vectorIndexArrayInitialize(const Vector &valueArray) {

    Vector temporaryVector;
    temporaryVector.counter = 0;

    for (int i = 0; valueArray.counter > i; ++i) {

        int temporary_index_storage = 0;
        temporary_index_storage = i;
        temporaryVector.value.push_back(temporary_index_storage);
        temporaryVector.counter++;
    }

    return temporaryVector;
}

unsigned vectorGetSize(Vector &v) {

    return v.value.size();
}
