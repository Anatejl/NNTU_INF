//Представление АТД "N-мерный вектор"
#ifndef VECTOR_H_
#define VECTOR_H_

#include <vector>

struct Vector {
   std::vector<double> coordinates;
};

void vectorResize(Vector& v, unsigned size);
bool vectorRead(Vector& v);
double vectorScalar(const Vector& first, const Vector& second);

#endif /* VECTOR_H_ */
