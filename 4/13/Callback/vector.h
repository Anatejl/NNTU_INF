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

struct tempVector {

    std::vector<int> temp_to_erase;
};

initialVector vectorInitializeData(const initialVector& initialArray);
std::vector<int> vectorAVectorInitialize(const initialVector& initialArray, int va, int a0);
std::vector<int> vectorBVectorInitialize(const initialVector& initialArray, int vb, int b0);

int vectorGetSizeInitialData(initialVector& v);
int vectorGetSizeTempData(tempVector& v);
bool vectorGetEmptyInitialData(initialVector& v);

#endif //NNTU_VECTOR_H
