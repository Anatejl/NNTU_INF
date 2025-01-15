#include "application.h"

int main() {
    std::cout << "Array shortener program!" << std::endl; 
    Application app; 
    int ret = app_run(app); 
    return ret; 
}