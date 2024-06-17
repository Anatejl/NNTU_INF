//main.cpp
//
// Created by Anatejl on 15.04.2024.
//

#include "application.h"
#include <iostream>

int main() {
    std::cout << "KUTAK Inc. Software ver. 666" << std::endl;
    Application app;
    int ret = appRun(app);
    return 0;
}