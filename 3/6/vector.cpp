#include "vector.h"

// Функция получения количества элементов вектора
int vector_size(std::vector<int>& vector){
    return vector.size();
}

// Функция добавления элемента в конец вектора
bool vector_push(std::vector<int>& vector, int value){
    vector.push_back(value);
    return true;
}

// Функция отображения вектора
bool vector_display(std::vector<int>& vector){
    for (int i : vector) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return true;
}