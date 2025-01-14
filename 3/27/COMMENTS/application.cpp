#include "application.h"

int app_run(Application_mainline& app_main, Application_source& app_source){
    app_start(app_main, app_source); // Вызов функции инициализации
    if (app_process(app_main, app_source)){ // Проверка успешной обработки данных
        app_end(app_main, app_source); // Завершение приложения
        return 0; // Успешное завершение
    }
    else{
        std::cout << "An error has occured." << std::endl; // Сообщение об ошибке
        return 1; // Завершение с ошибкой
    }
}

bool app_start(Application_mainline& app_main, Application_source& app_source){
    double temp_x = 0, temp_y = 0; // Временные переменные для координат точек
    int temp_n = 0; // Временная переменная для количества точек
    std::cout << "START START" << std::endl; // Сообщение о начале работы
    std::cout << "Input a n number:" << std::endl; // Запрос количества точек
    std::cin >> temp_n; // Ввод количества точек
    for (int i = 0; i < temp_n; ++i){ // Цикл для ввода координат точек
        std::cout << "[" << i+1 << "/" << temp_n << "]" << " set is being assigned:" << std::endl; // Сообщение о текущей точке
        std::cout << "Input a x:" << std::endl; // Запрос координаты x
        std::cin >> temp_x; // Ввод координаты x
        std::cout << "Input an y:" << std::endl; // Запрос координаты y
        std::cin >> temp_y; // Ввод координаты y
        cartesian_add(temp_x, temp_y, app_source.array); // Добавление точки в массив
    }
    return true; // Успешная инициализация
}

bool app_process(Application_mainline& app_main, Application_source& app_source){
    std::cout << "PROCESSING" << std::endl; // Сообщение о начале обработки
    if (app_source.array.size() > 1){ // Проверка наличия хотя бы двух точек
        cartesian_find(app_source.array, app_main.distanced); // Поиск самой удалённой пары точек
        return true; // Успешная обработка
    }
    std::cout << "Insufficient data. ABORTING..." << std::endl;   // Сообщение о недостаточности данных
    return false; // Ошибка обработки
}

bool app_end(Application_mainline& app_main, Application_source& app_source){

    std::cout << "ENDING" << std::endl; // Сообщение о завершении работы
    std::cout << "The farthest pair of points are:\n"; // Сообщение о выводе результата

    for (int i = 0; i < app_source.array.size(); ++i) { // Цикл для проверки и вывода точек
        if (app_source.array[i] == app_main.distanced.first) { // Проверка первой точки
            std::cout << "First point: is " << i+1 << " - ["<< app_main.distanced.first.first << ", " << app_main.distanced.first.second << "]" <<  std::endl;
        } 
        if (app_source.array[i] == app_main.distanced.second) { // Проверка второй точки
            std::cout << "Second point is: " << i+1 << " - ["<< app_main.distanced.second.first << ", " << app_main.distanced.second.second << "]" <<  std::endl;;
        }
    }
    return true; // Успешное завершение
}