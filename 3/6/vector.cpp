#include "vector.h"

// Функция получения размера вектора
int vector_size(std::vector<int>& vector) {
    return vector.size(); // Возвращение количества элементов
}

// Функция добавления значения в вектор
bool vector_push(std::vector<int>& vector, int value) {
    vector.push_back(value); // Добавление элемента в конец вектора
    return true; // Успешное завершение операции
}

// Функция отображения содержимого вектора
bool vector_display(std::vector<int>& vector) {
    for (int i : vector) { // Итерация по всем элементам вектора
        std::cout << i << " "; // Вывод значения
    }
    std::cout << std::endl; // Переход на новую строку
    return true; // Успешное завершение операции
}