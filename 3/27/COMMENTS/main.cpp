#include "application.h"
#include <iostream>

int main (){
    std::cout << "Cartesian dot finder!" << std::endl; // Вывод приветственного сообщения
    Application_mainline app_main; // Создание экземпляра структуры Application_mainline
    Application_source app_source; // Создание экземпляра структуры Application_source
    int ret = app_run(app_main, app_source); // Запуск основного цикла приложения
    return 0; // Завершение программы
}