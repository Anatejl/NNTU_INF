#include "application.h"

// Основной цикл работы приложения
int app_run(Application& app) {
    app_begin(app); // Инициализация приложения
    app_process(app); // Обработка данных
    app_end(app); // Завершение работы приложения
    return 0; // Возврат успешного завершения
}

// Функция инициализации приложения
bool app_begin(Application& app) {
    int n, temp_read_value; // Переменные для ввода количества элементов и временного значения
    std::cout << "What's n?" << std::endl; // Запрос размера массива
    std::cin >> n; // Ввод размера массива
    for (int i = 0; i < n; ++i) { // Цикл по количеству элементов
        std::cout << "<" << i + 1 << " of " << n << "> item assigning:" << std::endl; // Сообщение о текущем элементе
        std::cout << "Input a value:" << std::endl; // Запрос ввода значения
        std::cin >> temp_read_value; // Сохранение введенного значения
        vector_push(app.array, temp_read_value); // Добавление значения в вектор
    }
    std::cout << "Initial vector is: ";
    vector_display(app.array); // Отображение начального вектора
    return true; // Успешное завершение инициализации
}

// Функция обработки данных
bool app_process(Application& app) {
    for (int i = 1; i < vector_size(app.array); ++i) { // Удаление каждого второго элемента
        app.array.erase(app.array.begin() + i); // Удаление элемента
    }
    return true; // Успешное завершение обработки
}

// Функция завершения работы приложения
bool app_end(Application& app) {
    std::cout << "Processed vector is: ";
    vector_display(app.array); // Отображение обработанного вектора
    return true; // Успешное завершение
}