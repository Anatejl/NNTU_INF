/*
 * Интерфейс counting.
*/
#ifndef COUNTING_H_
#define COUNTING_H_

#include <complex>
#include <vector>
#include <utility>
#include <cmath>

int counting(std::vector<double> subsequence);

std::pair<std::complex<double>, int> rule(const std::complex<double> value);

#endif