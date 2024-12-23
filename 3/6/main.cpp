#include "application.h"

int main(){

    std::cout << "Array shortener program!" << std::endl;
    Application app; // Ввод переменной по типу АТД
    int ret = app_run(app); // Запуск приложения
    
    return ret;
}