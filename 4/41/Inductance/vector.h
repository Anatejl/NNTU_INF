//
// Created by Anatejl on 20.04.2024.
//
#pragma once
#ifndef NNTU_VECTOR_H
#define NNTU_VECTOR_H

#include <vector>

struct Vector{

    std::vector<std::vector<int>>row;
    bool insideTheCircle = false;
    int counter = 0;

};

Vector vectorInitialArrayInitialize(const Vector& initialArray, int coeffK);
int vectorGetSize(Vector& v);

#endif //NNTU_VECTOR_H
