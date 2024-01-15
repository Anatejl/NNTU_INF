//
// Created by Anatejl on 15.01.2024.
//
#include "vector.h"

void vectorResize(Vector& v, unsigned size) {

    v.coordX.resize(size);
    v.coordY.resize(size);

}

unsigned vectorGetSizeOfFinal(Vector& v){

    return v.coordX.size();

}

Vector vectorProcess(const Vector& initial, const Vector& final, unsigned R, unsigned n)
{
    Vector temporaryVector;
    for (int i = 0; i < n; ++i) {

        int x = initial.coordX[i];
        int y = initial.coordY[i];

        if (x * x + y * y <= R * R) {
            temporaryVector.coordX.push_back(initial.coordX[i]);
            temporaryVector.coordY.push_back(initial.coordY[i]);

        }
    }
    return temporaryVector;
}
