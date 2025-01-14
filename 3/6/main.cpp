#include "application.h"

// Основная функция программы
int main() {
    std::cout << "Array shortener program!" << std::endl; // Вывод сообщения о начале программы
    Application app; // Создание экземпляра структуры Application
    int ret = app_run(app); // Запуск основного цикла программы
    return ret; // Возврат результата работы программы
}