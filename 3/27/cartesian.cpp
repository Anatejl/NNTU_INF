#include "cartesian.h"

bool cartesian_add(int n, int x, int y, std::vector<std::pair<int, int>> &array){

    std::pair<int, int> temp_pair = std::make_pair(x, y);

    array.push_back(temp_pair);

    return true;
}

bool cartesian_find(std::vector<std::pair<int, int>> &array, std::pair<std::pair<int,int>, std::pair<int,int>> &distanced){

    for (int i = 0; i < array.size(); ++i){

        for (int j = 0; j < array.size(); ++j){

            if (array[i].first > array[j].first){

                

            }

        }

    }


    return true;
}