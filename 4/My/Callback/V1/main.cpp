//
// Created by Anatejl on 15.04.2024.
//

#include "application.h"
#include <iostream>

int main() {

    std::cout << "An unarguably valuable piece of software, THE diamond!" << std::endl;

    Application app;

    int ret = appRun(&app);

    return ret;
}
