#ifndef CARTESIAN_H
#define CARTESIAN_H

#include <vector>
#include <utility>
#include <math.h>

bool cartesian_add(double x, double y, std::vector<std::pair<double, double>> &array); // Функция добавления точки
bool cartesian_find(std::vector<std::pair<double, double>>& array, std::pair<std::pair<double,double>, std::pair<double, double>>& distanced); // Функция поиска самой удалённой пары точек
double cartesian_find_distance(std::pair<double, double>& pair_one, std::pair<double, double>& pair_two); // Функция вычисления расстояния между двумя точками

#endif //CARTESIAN_H