#include "application.h"
#include <iostream>

int main (){
    std::cout << "Cartesian dot finder!" << std::endl;
    Application app;
    int ret = app_run(app);
    return 0;
}