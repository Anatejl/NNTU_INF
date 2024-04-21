//
// Created by Anatejl on 20.04.2024.
//

#ifndef NNTU_VECTOR_H
#define NNTU_VECTOR_H

#include <vector>

struct Vector{

    std::vector<unsigned> value;
    unsigned counter;

};

Vector vectorInitialize(const Vector& valueArray);
unsigned vectorGetSize(Vector& v);

#endif //NNTU_VECTOR_H
