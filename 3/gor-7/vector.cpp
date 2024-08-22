// vector.cpp
#include "vector.h"          // Подключаем заголовочный файл для работы с векторами
#include <iostream>           // Подключаем заголовочный файл для ввода/вывода
#include <algorithm>          // Подключаем заголовочный файл для работы с алгоритмами

// Функция изменения размера вектора
void vectorResize(Vector& v, unsigned size)
{
    v.originalArray.resize(size);  // Изменяем размер оригинального массива в векторе
}

// vector.cpp

// Функция для чтения элементов вектора с проверкой ошибок
bool vectorRead(Vector& v)
{
    // Используем алгоритм std::all_of для проверки условия на каждом элементе
    if (!std::all_of(v.originalArray.begin(), v.originalArray.end(),
                     [](int& element) { return static_cast<bool>(std::cin >> element); })) {
        return false;  // Возвращаем false, если хотя бы для одного элемента произошла ошибка ввода
    }

    return true;  // Возвращаем true, если ввод для всех элементов прошел успешно
}

// Функция для сортировки векторов и разделения на четные и нечетные
void vectorSorting(const Vector& original, Vector& even, Vector& odd)
{
    for (int i = 0; i < original.originalArray.size(); ++i)
    {
        if (i % 2 == 0)
        {
            even.originalArray.push_back(original.originalArray[i]);  // Добавляем четные элементы
        }
        else
        {
            odd.originalArray.push_back(original.originalArray[i]);   // Добавляем нечетные элементы
        }
    }
}

// Функция для вывода элементов вектора в консоль
void vectorOutput(const Vector& v)
{
    for (int i = 0; i < v.originalArray.size(); ++i)
    {
        std::cout << v.originalArray[i];  // Выводим элементы вектора

        if (i < v.originalArray.size() - 1) {
            std::cout << " ";  // Выводим пробел между элементами, если это не последний элемент
        }
    }

    std::cout << std::endl;  // Печатаем пустую строку для форматирования вывода
}