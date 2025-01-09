//Реализация исполнителя "Приложение"
#include "application.h"
#include <iostream>
using namespace std;

static bool appRead(Application& app);
static double appScalarProduct(Application& app);
static void appOutputResult(Application& app, double value);

int appRun(Application& app)
{
    if ( !appRead(app) ) {
        cout << "ошибка при вводе данных" << endl;
        return 1;
    }
    double scalar = appScalarProduct(app);
    appOutputResult(app,scalar);
    return 0;
}

static bool appRead(Application& /*app*/)
{
    cout << "ввод данных" << endl;
    return true;
}

static double appScalarProduct(Application& /*app*/)
{
    cout << "вычисление" << endl;
    return 0;
}

static void appOutputResult(Application& /*app*/, double /*value*/)
{
    cout << "вывод результата" << endl;
    return;
}
