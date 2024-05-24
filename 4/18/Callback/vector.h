//
// Created by Anatejl on 20.04.2024.
//

#ifndef NNTU_VECTOR_H
#define NNTU_VECTOR_H

#include <bemapiset.h>
#include <vector>

struct initialVector {

    std::vector<int> value;

};

struct platoVector{

    std::vector<std::vector<int>> row;

};

int vectorDataInitialize();

//int vectorGetSize(platoVector& v);
//bool vectorGetEmpty(initialVector& v);

#endif //NNTU_VECTOR_H
