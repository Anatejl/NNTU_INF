/*
 * Файл реализующий интерфейс application.
*/
#include "application.h"
#include "counting.h"
#include <vector>

using namespace std;

std::vector<double> subsequence {1, 2, 3, 4, 6, 7, 8, 9, 10};

int appRun()
{
    return counting(subsequence);
}