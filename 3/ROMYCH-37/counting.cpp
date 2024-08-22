/*
 * Файл реализующий интерфейс counting.
*/
#include "counting.h"

using namespace std;

/*
 * Функция для подсчета замен, если флаг выставлен на 1.
*/
int counting(std::vector<double> subsequence)
{
    int replacements_count = 0;

    for (int value : subsequence) {
        auto result = rule(static_cast<double>(value));

        if (result.second == 1) {
            replacements_count += result.second;
        }
    }

    return replacements_count;
}

/*
 * Функция для проверки числа в последовательности по правилу
 * и возвращению его просчитанным по формуле с флагом 1 при успехе.
*/
pair<complex<double>, int> rule(const complex<double>value) 
{
    if (abs(value) > 1) {
        // Нахуя применять формулу, если в ответе все равно нужно лишь замены выводить.
        complex<double> result = value / (pow(value.real(), 2) + pow(value.imag(), 2));

        return make_pair(result, 1);
    } else {
        return make_pair(value, 0);
    }
}