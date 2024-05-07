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

struct finalVector {

    std::vector<int> sortedVector;

};

initialVector vectorInitializeData(const initialVector& initialValueArray, int va, int a0, int vb, int b0);
initialVector vectorAVectorInitialize(const initialVector& initialValueArray, int va, int a0);
initialVector vectorBVectorInitialize(const initialVector& initialValueArray);
int vectorGetSize(initialVector& v);

#endif //NNTU_VECTOR_H
