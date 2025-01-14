#ifndef NNTU_APPLICATION_H
#define NNTU_APPLICATION_H

#include <iostream>
#include "cartesian.h"

typedef struct Application_mainline{

    std::pair<std::pair<double, double>, std::pair<double, double>> distanced;
    // Пара точек, представляющих самую удалённую пару
    // distanced.first - первая точка
    // distanced.second - вторая точка
    // distanced.first.first/second - x/y координаты первой точки
    // distanced.second.first/second - x/y координаты второй точки

}Application_mainline;

typedef struct Application_source{

    std::vector<std::pair<double, double>> array;
    // Массив точек, каждая точка представлена парой координат (x, y)

}Application_source;

int app_run(Application_mainline& app_main, Application_source& app_source); // Основная функция запуска приложения
bool app_start(Application_mainline& app_main, Application_source& app_source); // Инициализация и ввод данных
bool app_process(Application_mainline &app_main, Application_source& app_source); // Обработка данных
bool app_end(Application_mainline& app_main, Application_source& app_source); // Завершение работы приложения и вывод результатов

#endif //NNTU_APPLICATION_H