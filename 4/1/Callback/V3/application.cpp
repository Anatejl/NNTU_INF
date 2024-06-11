//
// Created by l3t on 11.06.2024.
//

#include "application.h"

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

int appRun(Application &app) {

    operation(&inputConstantR, &app);

    //Consider using !std::cin.eof() for testing purposes.
    while (!std::cin.eof()) {

        if(!operation(&inputNextValue, &app)){
            return 1;
        }

        if (operation(&processCurrentValue, &app)) {
            operation(&printCurrentResult, &app);
        }
    }
    return 0;
}

bool inputConstantR(void *rawApp) {

    Application &app = *((Application *) rawApp);
    std::cout << "Input a R constant, to compare adjacent values:" << std::endl;
    std::cin >> app.constR;
    return true;
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
