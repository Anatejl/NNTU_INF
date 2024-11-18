#include "cartesian.h"

bool cartesian_add(int n, int x, int y, std::vector<std::pair<int, int>> &array){

    std::pair<int, int> temp_pair = std::make_pair(x, y);

    array.push_back(temp_pair);

    return true;
}