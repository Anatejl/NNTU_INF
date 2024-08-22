// vector.h
#ifndef VECTOR_H_         // Директива препроцессора, проверяющая, что VECTOR_H_ не определен
#define VECTOR_H_         // Определение макроса VECTOR_H_

#include <vector>          // Подключаем заголовочный файл для работы с векторами
using namespace std;       // Используем пространство имен std для удобства

// Объявление структуры Vector, представляющей вектор
struct Vector {
    vector<int> originalArray;  // Вектор для хранения целочисленных элементов
};

// Объявление функций для работы с векторами
void vectorResize(Vector& v, unsigned size);
bool vectorRead(Vector& v);
void vectorSorting(const Vector& original, Vector& even, Vector& odd);
void vectorOutput(const Vector& v);

#endif /* VECTOR_H_ */  // Конец блока условной компиляции VECTOR_H_

