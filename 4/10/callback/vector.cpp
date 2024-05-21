//
// Created by Anatejl on 20.04.2024.
//

#include <iostream>
#include "vector.h"
#include <numeric>

int vectorValueInitialize() {

    int to_write;
    std::cin >> to_write;

    return to_write;

}

int vectorAccumulate(Vector &v) {

    return std::accumulate(v.value.begin(), v.value.end(), 0);
}

int vectorGetSize(Vector &v) {

    return v.value.size();
}
