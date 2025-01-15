#ifndef HEADER_H // Проверить, был ли уже включен файл заголовка
#define HEADER_H // Определить защиту от повторного включения

#include <iostream> // Включить библиотеку iostream для операций ввода/вывода
#include "vector_handle.h" // Включить файл заголовка для функций обработки векторов

typedef struct Application{ // Определить структуру для хранения данных приложения

    int counter_positive = 0, counter_negative = 0, counter_zero = 0; // Счетчики для положительных, отрицательных и нулевых чисел

}Application;

typedef struct Source_data{ // Определить структуру для хранения исходных данных

    std::vector<int>array; // Вектор для хранения входного массива

}Source_data;

int app_launch(Application& app, Source_data& source); // Прототип функции запуска основного приложения
bool app_input(Application& app, Source_data& source); // Прототип функции ввода
bool app_process(Application& app, Source_data& source); // Прототип функции обработки
bool app_output(Application& app); // Прототип функции вывода

#endif // Конец защиты от повторного включения