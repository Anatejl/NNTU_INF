//Реализация исполнителя "N-мерный вектор"
#include "vector.h"
#include <iostream>
using namespace std;

void vectorResize(Vector& v, unsigned size) {
   v.coordinates.resize(size);
   return;
}

bool vectorRead(Vector& v)
{
    unsigned size = v.coordinates.size();
    for(unsigned i = 0; i < size; ++i)
        cin >> v.coordinates[i];
    return true;
}

double vectorScalar(const Vector& first, const Vector& second)
{
    double result = 0;
    unsigned size = first.coordinates.size();
    for(unsigned i = 0; i < size; ++i)
        result += first.coordinates[i] * second.coordinates[i];
    return result;
}



