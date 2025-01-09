//Реализация исполнителя "Приложение"
#include "application.h"
#include "vector.h"
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

static bool appRead(Application& app)
{
    cout << "введите размерность векторов:";
    unsigned size;
    cin >> size;
    vectorResize(app.first, size);
    vectorResize(app.second, size);
    cout << "введите элементы первого вектора: ";
    vectorRead(app.first);
    cout << "введите элементы второго вектора: ";
    vectorRead(app.second);
    return true;
}

static double appScalarProduct(Application& app)
{
    return vectorScalar(app.first, app.second);
}

static void appOutputResult(Application& /*app*/, double value)
{
    cout << "скалярное произведение: " << value << endl;
    return;
}

