//
// Created by Anatejl on 15.04.2024.
//

#include "application.h"
#include <iostream>
#include <sstream>

int main() {

    std::cout << "XUYNYA COUNTER!" << std::endl;

    Application app;

   // for (std::string line; std::getline(std::cin, line, ';');) {
   //     auto temp_int = std::stoi(line);
   //     std::cout << temp_int << std::endl;
   // }

    int ret = appRun(app);

    return ret;
}
