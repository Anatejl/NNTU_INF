#include "cartesian.h"

bool cartesian_add(double x, double y, std::vector<std::pair<double, double>> &array){
    std::pair<double, double> temp_pair = std::make_pair(x, y);
    array.push_back(temp_pair);
    return true;
}

bool cartesian_find(std::vector<std::pair<double, double>>& array, std::pair<std::pair<double, double>, std::pair<double, double>>& distanced){
    double distance_max = 0;
    for (int i = 0; i < array.size(); ++i){
        for (int j = i+1; j < array.size(); ++j){
            double distance = cartesian_find_distance(array[i], array[j]);    
            if (distance > distance_max){
                distance_max = distance;
                distanced = {array[i], array[j]};
            }
        }
    }
    return true;
}

double cartesian_find_distance(std::pair<double, double>& pair_one, std::pair<double, double>& pair_two){
    return pow(pair_two.first - pair_one.first, 2) + pow(pair_two.second - pair_one.second, 2);
}