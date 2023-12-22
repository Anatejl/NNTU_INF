//main.cpp
#include "header.h"
#include "initVector.cpp"
#include "processing.cpp"

int main() {

    int n, R;

    std::cout << "Input n:" << std::endl;
    std::cin >> n;
    auto points = init_points(n);

    std::cout << "Input R:" << std::endl;
    std::cin >> R;

    auto finalVector = filterZ(points, R);

	//PLACEHOLDER FOR OUTPUT

    return 0;
}
