//
// Created by Anatejl on 20.04.2024.
//

#ifndef NNTU_VECTOR_H
#define NNTU_VECTOR_H

#include <vector>

struct initialVector{

    std::vector<int> AVector;
    std::vector<int> BVector;
    std::vector<int> initialData;

};

int vectorInitializeData();
int vectorAVectorInitialize(int va, int a0, int second);
int vectorBVectorInitialize(int vb, int b0, int second);

int vectorGetSizeInitialData(initialVector& v);
bool vectorGetEmptyInitialData(initialVector& v);

#endif //NNTU_VECTOR_H
