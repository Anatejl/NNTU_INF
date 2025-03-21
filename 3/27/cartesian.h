#ifndef CARTESIAN_H
#define CARTESIAN_H

#include <vector>
#include <utility>
#include <iostream>
#include <math.h>

bool cartesian_add(double x, double y, std::vector<std::pair<double, double>> &array);
bool cartesian_find(std::vector<std::pair<double, double>>& array, std::pair<std::pair<double,double>, std::pair<double, double>>& distanced);
double cartesian_find_distance(std::pair<double, double>& pair_one, std::pair<double, double>& pair_two);
void cartesian_show(std::vector<std::pair<double, double>>& array);

#endif //CARTESIAN_H