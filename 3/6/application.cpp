#include "application.h"

int app_run(Application& app){
    app_begin(app); // Функция получения данных от пользотвателя, и сборки вектора
    app_process(app); // Функция сжатия вектора
    app_end(app); // Функция вывода сжатого вектора
    return 0;
}

bool app_begin(Application& app){
    int n, temp_read_value;
    std::cout << "What's n?" << std::endl; //Запрос числа n
    std::cin >> n;
    for (int i = 0; i < n; ++i){ // Сборка вектора, путам запроса значений у пользователя
        std::cout << "<" << i+1 << " of " << n << ">" << " item assigning:" << std::endl;
        std::cout << "Input a value:" << std::endl;
        std::cin >> temp_read_value;
        vector_push(app.array, temp_read_value);
    }
    std::cout << "Initial vector is: ";
    vector_display(app.array); // Вывод получившегося вектора на стандартное устройство вывода
    return true;
}

bool app_process(Application& app){
    for (int i = 1; i < vector_size(app.array); ++i){ // Цикл поиска четных элементов вектора
        app.array.erase(app.array.begin()+i); // Удаление четного элемента последовательности
    }
    return true;
}

bool app_end(Application& app){
    std::cout << "Processed vector is: ";
    vector_display(app.array); // Вывод сжатого вектора
    return true;
}