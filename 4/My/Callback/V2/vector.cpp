//
// Created by Anatejl on 20.04.2024.
//

#include "vector.h"
#include <iostream>

int vectorValueInitialize() {

    int to_write;
    std::cin >> to_write;

    return to_write;
}

int vectorGetSize(Vector &v) {
    return v.value.size();
}
