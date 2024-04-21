//
// Created by Anatejl on 15.04.2024.
//

#include "application.h"
#include <iostream>
#include <sstream>

int main() {

    std::cout << "XUYNYA COUNTER!" << std::endl;

    Application app;

    std::istringstream input;
    input.str("1\n2\n3\n4\n5\n6\n7\n");
    int sum = 0;
    for (std::string line; std::getline(input, line);)
        sum += std::stoi(line);
    std::cout << "\nThe sum is " << sum << ".\n\n";

    int ret = appRun(app);

    return ret;
}
