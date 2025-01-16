#include "vector.h"

int vector_size(std::vector<int>& vector) {
    return vector.size(); 
}

bool vector_compress(std::vector<int>& vector){

    for (int i = 1; i < vector_size(vector); ++i) { 
        vector.erase(vector.begin() + i); 
    }

    return true;
}

bool vector_push(std::vector<int>& vector, int value) {
    vector.push_back(value); 
    return true; 
}

bool vector_display(std::vector<int>& vector) {
    for (int i : vector) { 
        std::cout << i << " "; 
    }
    std::cout << std::endl; 
    return true; 
}