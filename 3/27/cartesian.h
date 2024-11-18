#ifndef CARTESIAN_H
#define CARTESIAN_H

#include <vector>
#include <utility>

bool cartesian_add(int n, int x, int y, std::vector<std::pair<int, int>> &array);
bool cartesian_find(std::vector<std::pair<int, int>>& array, std::pair<std::pair<int,int>, std::pair<int,int>>& distanced);
bool cartesian_find_distance(std::pair<int, int>& pair_one, std::pair<int, int>& pair_two);

#endif //CARTESIAN_H