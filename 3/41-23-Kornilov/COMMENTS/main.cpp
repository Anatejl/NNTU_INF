#include "application.h" // Включить файл заголовка Application

int main(){

    std::cout << "Welcome to Positive/Negative/Zero evaluation program." << std::endl; // Вывести приветственное сообщение
    Application app; // Создать экземпляр Application
    Source_data source; // Создать экземпляр Source_data
    int ret = app_launch(app, source); // Запустить приложение и сохранить возвращаемое значение
    return ret; // Вернуть значение, возвращенное функцией app_launch()

}