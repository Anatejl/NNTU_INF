//
// Created by Anatejl on 06.10.2024.
//

#include "vector.h"

bool vector_display(std::vector<int>& vector){
    for (int i : vector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return true;
}

bool vector_check(std::vector<int>& vector){
    bool flag = true;
    for (int i : vector){
        if (!i%2){
            flag = false;
            break;
        }
    }

    std::cout << "VERDICT: ";
    if (flag){
        std::cout << "SUCCESS" << std::endl;
        return true;
    }
    else{
        std::cout << "FAILURE" << std::endl;
        return false;
    }
}