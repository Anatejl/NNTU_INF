#include <iostream>
#include "Application.h"

bool app_get_D(Application &app) {
    std::cout << "Enter the value of D: ";
    std::cin >> app.D;
    std::cout << app.D << std::endl;
    return true;
}

bool app_get_element(Application &app) {
    std::cin >> app.xn;
    return true;
}

bool app_output_match(Application &app) {
    if (app.fLi != 0 && app.fRi != 0) {
        std::cout << "Current best segment: from " << app.fLi + 1 << " to " << app.fRi + 1 << std::endl;
    }
    return true;
}

bool app_process(Application &app) {
    if (app.isFirst) {
        app.tLv = app.tRv = app.xn;
        app.isFirst = false;
    }
    if (app.tCS == 1) {
        app.tLi = app.n - 1;
        app.tLv = app.tRv;
        app.tRi = app.n;
        app.tRv = app.xn;
        app.tCS = 2;
    } else {
        if (app.xn > app.tRv) {
            app.tRi = app.n;
            app.tRv = app.xn;
            app.tCS++;
        } else {
            app.tLi = app.n;
            app.tLv = app.xn;
            app.tRi = app.n;
            app.tRv = app.xn;
            app.tCS = 1;
        }
        if (app.tCS > app.fCS && (app.tRv - app.tLv >= app.D)) {
            app.fLi = app.tLi;
            app.fRi = app.tRi;
            app.fCS = app.tCS;
        }
    }
    app.n++;
    return true;
}

int app_run(Application &app) {
    app_get_D(app);
    while (!std::cin.eof()) {
        app_get_element(app);
        app_process(app);
        app_output_match(app);
    }
    return 0;
}