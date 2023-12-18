#include <iostream>
#include <vector>

using namespace std;

std::vector<double> subsequence(int k) {

    std::vector<double> initialVector(k);

    for (int i = 0; i < k; ++i) {
        cout << "Input point #" << i << endl;
        cin >> initialVector[i];
    }

    return initialVector;
};

int counting(vector<double>& vectorValue)
{
    int reps = 0;

    int replacements_count = 0;

    for (int i = 0; i < vectorValue.size(); ++i) {

        if (abs(vectorValue[i]) > 1) {
      
            reps++;
        }
    }

    return reps;
}

int main()
{
    int n;

    std::cout << "Number of points Z: " << endl;
    std::cin >> n;

    auto dots = subsequence(n);

    auto final = counting(dots);

    cout << "MADE REPLACEMENTS:" << endl;
    cout << final << endl;
  
    return 0;
}