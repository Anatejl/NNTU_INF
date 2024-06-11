//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

void inputConstantR(Application &app);
std::string formatResult(Application &app, bool isFirst);

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

int appRun(Application &app) {

    inputConstantR(app);

    while (operation(&inputNextValue, &app)) {
        if (operation(&processCurrentValue, &app)) {
            operation(&printCurrentResult, &app);
        }
    }
    return 0;
}

void inputConstantR(Application &app) {
    std::cout << "Input a R constant, to compare adjacent values:" << std::endl;
    std::cin >> app.constR;
}

bool inputNextValue(void *rawApp) {
    Application &app = *((Application *) rawApp);
    if (std::cin.eof()) {
        return false;
    }
    app.prevValue = app.curValue;
    std::cin >> app.curValue;
    ++app.curIndex;
    return true;
}

bool processCurrentValue(void *rawApp) {
    Application &app = *((Application *) rawApp);
    return std::abs(static_cast<long>(app.prevValue) - app.curValue) > app.constR;
}

bool printCurrentResult(void *rawApp) {
    Application &app = *((Application *) rawApp);
    std::cout << formatResult(app, app.curIndex == 1) << std::endl;
    return true;
}

std::string formatResult(Application &app, bool isFirst) {
    return "{\n\tindex: " + std::to_string(app.curIndex) +
           (!isFirst ? ",\n\tprevious value: " + std::to_string(app.prevValue) : "") +
           ",\n\tcurrent value: " + std::to_string(app.curValue) + "\n}";
}
