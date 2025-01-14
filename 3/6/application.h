#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include "vector.h"

// Структура АТД Application для хранения вектора
typedef struct Application {
    std::vector<int> array; // Вектор целых чисел
} Application;

// Объявление функций, связанных с работой Application
int app_run(Application& app); // Основной цикл приложения
bool app_begin(Application& app); // Инициализация приложения
bool app_process(Application& app); // Обработка данных
bool app_end(Application& app); // Завершение работы приложения

#endif // NNTU_APPLICATION_H