//vector.h
//
// Created by Anatejl on 15.01.2024.
//

#ifndef NNTU_VECTOR_H
#define NNTU_VECTOR_H

#include <iostream>
#include <vector>

struct Vector {

    std::vector<int> coordX;
    std::vector<int> coordY;
    unsigned counter;

};

void vectorResize(Vector& v, unsigned size);
Vector vectorProcess(const Vector& initial, const Vector& final, unsigned R, unsigned n);
unsigned vectorGetSizeOfFinal(Vector& v);

#endif //NNTU_VECTOR_H
