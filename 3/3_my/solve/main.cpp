#include <iostream>
#include <vector>
#include <algorithm>
#include "header.h"

/* Инициализируешь массив
 * Комплексное число представляется ввиде z = x + y * i, где
 * i - комплексная единица
 * z - комплексное число
 * x - вещественная часть
 * y - комплексная часть
 * Те нам чтобы однозначно его представить нужно 2 числа x и y
 */
std::vector<IrNumber> init_points(int k) {

    std::vector<IrNumber> initialVector(k);

    for (int i = 0; i < k; ++i) {

        std::cout << "Input set - " << i << ":" << std::endl;
        std::cin >> initialVector[i].x >> initialVector[i].y;
    }

    return initialVector;
}

/* Теперь основная программа
 * Комплексное число можно представить в двух видах:
 * 1) z = x + y * i
 * 2) z = r(cos(phi) + sin(phi) * i)
 * Формулу перевода из системы координат (x, y) в (r, phi) можно посмотреть в интернете,
 * но основное что нам нужно r^2 = x^2 + y^2 и факт что |z|^2 = x^2 + y^2
 * поэтому вычисляем |z[i]|^2 и сравниваем с переданным нам R^2
 * Те что нам подходят по условию выкидываем  |z[i]|^2 > R^2
 */

std::vector<IrNumber> filterZ(std::vector<IrNumber>& z, int R) {

    std::vector<IrNumber> resultNumbers;

    resultNumbers.reserve(z.size());

    for (int i = 0; i < z.size(); ++i) {

        if (z[i].getSquareOfRadius() <= R * R) {
            resultNumbers.push_back(z[i]);
        }
    }

    return resultNumbers;
}

int main() {

    int n, R;

    std::cout << "Input n:" << std::endl;
    std::cin >> n;
    auto points = init_points(n);

    std::cout << "Input R:" << std::endl;
    std::cin >> R;

    auto finalVector = filterZ(points, R);

    for (int i = 0; i < finalVector.size(); ++i) {
        std::cout << "{" << finalVector[i].x << ", " << finalVector[i].y << "}; ";
    }
    std::cout << std::endl;

    return 0;
}
