#include "cartesian.h"

bool cartesian_add(double x, double y, std::vector<std::pair<double, double>> &array){
    std::pair<double, double> temp_pair = std::make_pair(x, y); // Создание пары координат
    array.push_back(temp_pair); // Добавление пары в массив
    return true; // Успешное добавление
}

bool cartesian_find(std::vector<std::pair<double, double>>& array, std::pair<std::pair<double, double>, std::pair<double, double>>& distanced){
    double distance_max = 0; // Переменная для хранения максимального расстояния
    for (int i = 0; i < array.size(); ++i){ // Первый цикл для выбора первой точки
        for (int j = i+1; j < array.size(); ++j){ // Второй цикл для выбора второй точки
            double distance = cartesian_find_distance(array[i], array[j]);    // Вычисление расстояния между двумя точками
            if (distance > distance_max){ // Проверка на новое максимальное расстояние
                distance_max = distance; // Обновление максимального расстояния
                distanced = {array[i], array[j]}; // Сохранение пары точек
            }
        }
    }
    return true; // Успешное завершение поиска
}

double cartesian_find_distance(std::pair<double, double>& pair_one, std::pair<double, double>& pair_two){
    return pow(pair_two.first - pair_one.first, 2) + pow(pair_two.second - pair_one.second, 2); // Вычисление квадрата расстояния между двумя точками
}
