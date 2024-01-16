// application.h
#ifndef APPLICATION_H_  // Директива препроцессора, проверяющая, что APPLICATION_H_ не определен
#define APPLICATION_H_  // Определение макроса APPLICATION_H_

#include "vector.h"     // Подключаем заголовочный файл для работы с векторами
using namespace std;    // Используем пространство имен std для удобства

// Объявление структуры Application, представляющей данные приложения
struct Application {
    Vector evenArray;         // Вектор для четных элементов
    Vector oddArray;          // Вектор для нечетных элементов
    Vector originalArray;     // Вектор для оригинальных элементов
};

// Объявление функции appRun, представляющей основную логику приложения
int appRun(Application& app);

#endif /* APPLICATION_H_ */  // Конец блока условной компиляции APPLICATION_H_
