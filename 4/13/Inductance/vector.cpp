//
// Created by Anatejl on 20.04.2024.
//

#include <iostream>
#include "vector.h"

initialVector vectorInitializeData(const initialVector &initialArray) {

    initialVector temporaryVector;
    int tempValue;

    while(!std::cin.eof()) {

        std::cin >> tempValue;
        temporaryVector.initialData.push_back(tempValue);

    }

    return temporaryVector;

}

//initialVector vectorIndexArrayInitialize(const initialVector &initialArray) {
//
//
//    return temporaryVector;
//}

