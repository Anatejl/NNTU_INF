//vector.cpp
//
// Created by Anatejl on 15.01.2024.
//

#include "vector.h"

void vectorResize(initialVector& v, unsigned size) {

    v.coordX.resize(size);
    v.coordY.resize(size);

}

unsigned vectorGetSizeOfFinal(initialVector& v){

    return v.coordX.size();

}

initialVector vectorProcess(const initialVector& initial, const initialVector& final, unsigned R, unsigned n)
{
    initialVector temporaryVector;
    temporaryVector.counter = 0;

    for (int i = 0; i < n; ++i) {

        int x = initial.coordX[i];
        int y = initial.coordY[i];

        if (x * x + y * y <= R * R) {
            temporaryVector.coordX.push_back(initial.coordX[i]);
            temporaryVector.coordY.push_back(initial.coordY[i]);
            temporaryVector.counter++;

        }
    }
    return temporaryVector;
}
