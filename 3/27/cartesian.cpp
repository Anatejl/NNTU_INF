#include "cartesian.h"

bool cartesian_add(int n, int x, int y, std::vector<std::pair<int, int>> &array){
    std::pair<int, int> temp_pair = std::make_pair(x, y);
    array.push_back(temp_pair);
    return true;
}

bool cartesian_find(std::vector<std::pair<int, int>>& array, std::pair<std::pair<int,int>, std::pair<int,int>>& distanced){
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

double cartesian_find_distance(std::pair<int, int>& pair_one, std::pair<int, int>& pair_two){
    return pow(pair_two.first - pair_one.first, 2) + pow(pair_two.second - pair_one.second, 2);
}