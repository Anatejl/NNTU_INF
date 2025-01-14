#ifndef NNTU_VECTOR_H
#define NNTU_VECTOR_H

#include <iostream>
#include <vector>

// Объявление функций для работы с вектором
bool vector_push(std::vector<int>& vector, int value); // Добавление значения в вектор
bool vector_display(std::vector<int>& vector); // Отображение содержимого вектора
int vector_size(std::vector<int>& vector); // Получение размера вектора

#endif // NNTU_VECTOR_H