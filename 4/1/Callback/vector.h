//
// Created by Anatejl on 20.04.2024.
//

#ifndef NNTU_VECTOR_H
#define NNTU_VECTOR_H

#include <vector>

struct VectorPair {

    std::vector<std::pair<int, int>> value;

};

std::pair<bool, std::pair<int, int>> vectorPairInitialize();
std::pair<int, int> vectorMakePair(int first, int second);


int vectorGetSize_pair(VectorPair& v);
bool vectorGetEmpty_pair(VectorPair& v);

#endif //NNTU_VECTOR_H
