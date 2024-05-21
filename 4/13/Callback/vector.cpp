//
// Created by Anatejl on 20.04.2024.
//

#include <iostream>
#include "vector.h"

int vectorDataInitialize() {
    int to_write;
    std::cin >> to_write;
    return to_write;
}

int vectorAVectorInitialize(int va, int a0, int second) {
    int to_write = va * second + a0;
    return to_write;
}

int vectorBVectorInitialize(int vb, int b0, int second) {
    int to_write = vb * second + b0;
    return to_write;
}

int vectorGetSizeInitialData(initialVector &v) {
    return v.initialData.size();
}

bool vectorGetEmptyInitialData(initialVector &v) {
    return v.initialData.empty();
}