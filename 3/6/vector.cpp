//
// Created by Anatejl on 06.10.2024.
//

#include "vector.h"

int vector_size(std::vector<int>& vector){
    return vector.size();
}

bool vector_push(std::vector<int>& vector, int value){
    vector.push_back(value);
    return true;
}

bool vector_erase(std::vector<int>& vector, int index){
    vector.erase(vector.begin()+index);
    return true;
}

bool vector_display(std::vector<int>& vector){
    for (int i : vector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return true;
}