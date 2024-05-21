//
// Created by Anatejl on 20.04.2024.
//

#include "vector.h"
#include <iostream>

auto vectorValueInitialize() {

    int first, second;
    std::pair <bool, std::pair<int, int>> final_pair;

    if(!std::cin.eof()) {
        std::cin >> first;
    }

    if (!std::cin.eof()) {
        std::cin >> second;
        final_pair = std::make_pair(true, vectorMakePair(first, second));
    }
    else {
        final_pair = std::make_pair(false, vectorMakePair(first, second));;
    }

    return final_pair;

}

auto vectorMakePair(int first, int second) {

    return std::make_pair(first, second);
}

int vectorGetSize(Vector &v) {

    return v.value.size();
}

int vectorGetSize_pair(VectorPair& v){

    return v.value.size();
}

bool vectorGetEmpty(Vector &v) {

    return v.value.empty();
}

bool vectorGetEmpty_pair(VectorPair& v){

    return v.value.empty();
}

