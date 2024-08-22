//main.cpp
//
// Created by Anatejl on 15.01.2024.
//

#include <iostream>
#include "application.h"

int main(){

    std::cout << "Dot includance counter!" << std::endl;
    Application app;
    int ret = appRun(app);
    return ret;

}

