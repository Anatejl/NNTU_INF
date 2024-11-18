
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

using namespace std;

// Function to calculate the squared distance between two points
double squaredDistance(const pair<int, int>& p1, const pair<int, int>& p2) {
    return pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2);
}

int main() {
    // Sample input: list of points (you can modify this as needed)
    vector<pair<int, int>> array = {{1, 2}, {4, 6}, {5, 3}, {10, 15}, {2, 8}};
    
    // Variables to store the pair of points that are farthest apart
    pair<pair<int, int>, pair<int, int>> distanced;
    double maxDistance = 0;

    // Brute force approach: check every pair of points
    for (size_t i = 0; i < array.size(); ++i) {
        for (size_t j = i + 1; j < array.size(); ++j) {
            double dist = squaredDistance(array[i], array[j]);
            if (dist > maxDistance) {
                maxDistance = dist;
                distanced = {array[i], array[j]};
            }
        }
    }

    // Output the result
    cout << "The farthest pair of points are: (" 
         << distanced.first.first << ", " << distanced.first.second << ") and ("
         << distanced.second.first << ", " << distanced.second.second << ")" << endl;
    
    // Print the original index of the points
    for (size_t i = 0; i < array.size(); ++i) {
        if (array[i] == distanced.first) {
            cout << "First point index in the sequence: " << i << endl;
        }
        if (array[i] == distanced.second) {
            cout << "Second point index in the sequence: " << i << endl;
        }
    }
    return 0;
}