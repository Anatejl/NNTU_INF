#include "vector_handle.h" // Включить файл заголовка для функций обработки векторов
#include <iostream> // Включить библиотеку iostream для операций ввода/вывода

std::vector<int> vector_fill(int n){
    std::vector<int> to_return; // Создать вектор для хранения входных элементов
    int temp_int; // Временная переменная для хранения входного элемента
    for(int i = 0; i < n; ++i){
        std::cout << "Input a_" << i+1 << " / " << "a_" << n << " character:" << std::endl; // Запрос на ввод
        std::cin >> temp_int; // Прочитать входной элемент
        to_return.push_back(temp_int); // Добавить входной элемент в вектор
    }
    return to_return; // Вернуть заполненный вектор
}

int vector_count_positive(std::vector<int>to_compute){
    int counter = 0; // Инициализировать счетчик положительных элементов
    for(int i : to_compute){ // Пройтись по вектору
        if (i > 0){ // Проверить, является ли элемент положительным
            ++counter; // Увеличить счетчик
        }
    }
    return counter; // Вернуть количество положительных элементов
}

int vector_count_negative(std::vector<int>to_compute){
    int counter = 0; // Инициализировать счетчик отрицательных элементов
    for(int i : to_compute){ // Пройтись по вектору
        if (i < 0){ // Проверить, является ли элемент отрицательным
            ++counter; // Увеличить счетчик
        }
    }
    return counter; // Вернуть количество отрицательных элементов
}

int vector_count_zeroes(std::vector<int>to_compute){
    int counter = 0; // Инициализировать счетчик нулевых элементов
    for(int i : to_compute){ // Пройтись по вектору
        if ( i == 0 ){ // Проверить, является ли элемент нулевым
            ++counter; // Увеличить счетчик
        }
    }
    return counter; // Вернуть количество нулевых элементов
}

void vector_show(std::vector<int>to_compute){
    //DEBUG
    std::cout << "Vector is: " << std::endl; // Вывести сообщение, указывающее на вектор
    for (int i : to_compute){ // Пройтись по вектору
        std::cout << i << " "; // Вывести каждый элемент
    }
    std::cout << std::endl; // Вывести новую строку
}