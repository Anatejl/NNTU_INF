//
// Created by Anatejl on 20.04.2024.
//

#include "vector.h"
#include <iostream>

Vector vectorInitialize(const Vector& valueArray){

    Vector temporaryVector;
    temporaryVector.counter = 0;

    while (!std::cin.eof()) {

        int temporary_value_storage = 0;

        for (int k = 0; k <= temporaryVector.counter; k++) {

            //std::cout << "Iteration - "<< k << " " << "EOF IS: " << std::cin.eof() << std::endl;

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

unsigned vectorGetSize(Vector& v){

    return v.value.size();
}
