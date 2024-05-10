//
// Created by Anatejl on 20.04.2024.
//

#include <iostream>
#include "vector.h"

initialVector vectorInitializeData(const initialVector &initialArray) {

    initialVector temporaryVector;
    int tempValue;

    while (!std::cin.eof()) {

        std::cin >> tempValue;
        temporaryVector.initialData.push_back(tempValue);

    }

    return temporaryVector;

}

initialVector vectorAVectorInitialize(const initialVector &initialArray, int va, int a0) {

    initialVector temporaryVector;

    for (int i = 0; i < initialArray.initialData.size(); ++i) {
        temporaryVector.AVector.push_back(va * i + a0);
    }

    return temporaryVector;
}

initialVector vectorBVectorInitialize(const initialVector &initialArray, int vb, int b0) {

    initialVector temporaryVector;

    for (int i = 0; i < initialArray.initialData.size(); ++i) {
        temporaryVector.BVector.push_back(vb * i + b0);
    }

    return temporaryVector;
}

int vectorGetSizeInitialData(initialVector &v) {

    return v.initialData.size();
}

bool vectorGetEmptyInitialData(initialVector &v) {

    return v.initialData.empty();
}