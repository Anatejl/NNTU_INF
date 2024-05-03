//
// Created by Anatejl on 20.04.2024.
//

#ifndef NNTU_VECTOR_H
#define NNTU_VECTOR_H

#include <vector>

struct Vector{

    std::vector<int> value;

};

struct VectorPair {

    std::vector<std::pair<int, int>> value;

};

Vector vectorValueArrayInitialize(const Vector& valueArray);
int vectorGetSize(Vector& v);
int vectorGetSize_pair(VectorPair& v);
bool vectorGetEmpty(Vector& v);
bool vectorGetEmpty_pair(VectorPair& v);

#endif //NNTU_VECTOR_H
