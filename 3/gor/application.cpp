// application.cpp
#include "application.h"  // Подключаем заголовочный файл для структуры Application
#include "vector.h"       // Подключаем заголовочный файл для работы с векторами
#include <iostream>        // Подключаем заголовочный файл для ввода/вывода

// Объявление статических функций, чтобы они были видны только в пределах этого файла
static bool appRead(Application& app);             // Функция для ввода данных
static void appSortingProduct(Application& app);    // Функция для сортировки данных
static void appOutputResult(const Application& app); // Функция для вывода результатов

// Основная функция приложения
int appRun(Application& app)
{
    appRead(app);           // Вызываем функцию ввода данных
    appSortingProduct(app); // Вызываем функцию сортировки данных
    appOutputResult(app);   // Вызываем функцию вывода результатов
    return 0;               // Возвращаем 0, что означает успешное завершение
}

// Функция для ввода данных
static bool appRead(Application& app)
{
    std::cout << "input n: ";   // Выводим приглашение для ввода размерности массива
    unsigned size;
    std::cin >> size;  // Считываем размерность массива

    // Изменяем размеры векторов в структуре Application
    //vectorResize(app.evenArray, size);
    //vectorResize(app.oddArray, size);
    vectorResize(app.originalArray, size);

    std::cout << "input elements of an array: ";   // Выводим приглашение для ввода элементов массива
    vectorRead(app.originalArray);               // Считываем элементы массива с помощью функции vectorRead

    return true;  // Возвращаем true, чтобы показать, что ввод данных прошел успешно
}

// Функция для сортировки данных
static void appSortingProduct(Application& app)
{
    vectorSorting(app.originalArray, app.evenArray, app.oddArray);  // Вызываем функцию сортировки
}

// Функция для вывода результатов
static void appOutputResult(const Application& app)
{
    std::cout << std::endl;                            // Печатаем пустую строку для форматирования вывода
    std::cout << "even: ";
    vectorOutput(app.evenArray);                      // Выводим нечетные элементы
    std::cout << "odd: ";
    vectorOutput(app.oddArray);                       // Выводим четные элементы
    std::cout << std::endl;                            // Печатаем пустую строку для форматирования вывода
}
