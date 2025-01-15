#include "application.h" // Включить файл заголовка для класса Application

int app_launch(Application &app, Source_data& source){ // Функция запуска основного приложения
    app_input(app, source); // Вызвать функцию ввода
    app_process(app, source); // Вызвать функцию обработки
    app_output(app); // Вызвать функцию вывода
    return 0; // Вернуть 0, чтобы указать на успешное выполнение
}

bool app_input(Application& app, Source_data& source){

    int temp_n = 0; // Временная переменная для хранения количества элементов

    std::cout << "Input n: " << std::endl; // Запросить у пользователя количество элементов
    std::cin >> temp_n; // Прочитать количество элементов от пользователя
    source.array = vector_fill(temp_n); // Заполнить вектор входными данными пользователя
    return true; // Указать на успешный ввод
}

bool app_process(Application& app, Source_data& source){
    vector_show(source.array); // Отобразить входной вектор
    app.counter_positive = vector_count_positive(source.array); // Подсчитать количество положительных элементов
    app.counter_negative = vector_count_negative(source.array); // Подсчитать количество отрицательных элементов
    app.counter_zero = vector_count_zeroes(source.array); // Подсчитать количество нулевых элементов
    return true; // Указать на успешную обработку
}

bool app_output(Application& app){
    std::cout << "Positive: " << app.counter_positive << std::endl; // Вывести количество положительных элементов
    std::cout << "Negative: " << app.counter_negative << std::endl; // Вывести количество отрицательных элементов
    std::cout << "Zero: " << app.counter_zero << std::endl; // Вывести количество нулевых элементов
    return true; // Указать на успешный вывод
}
