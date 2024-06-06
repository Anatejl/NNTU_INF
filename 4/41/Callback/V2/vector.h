//
// Created by Anatejl on 20.04.2024.
//
#pragma once
#ifndef NNTU_VECTOR_H
#define NNTU_VECTOR_H

#include <vector>

struct initialVector{

    std::vector<std::pair<double, double>>row;
    int counter = 0;

};

struct finalVector {

    std::vector<double> row;
    std::vector<std::vector<int>> insideTheCircleGroup;

};

initialVector vectorInitialArrayInitialize(const initialVector& initialArray);
int vectorGetSize(initialVector& v);

#endif //NNTU_VECTOR_H
