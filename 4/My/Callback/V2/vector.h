//
// Created by Anatejl on 20.04.2024.
//

#ifndef NNTU_VECTOR_H
#define NNTU_VECTOR_H

#include <vector>

struct Vector{

    std::vector<int> value;

};

int vectorValueInitialize();
int vectorGetSize(Vector& v);

#endif //NNTU_VECTOR_H
