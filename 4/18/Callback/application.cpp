//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

bool operation(Callback callback, void *data) {
    return (*callback)(data);
}

bool appInitializeK(void *app) {
    Application &tempApp = *(Application *) app;
    std::cin >> tempApp.constK;

    if (std::cin.fail()) {
        return false;
    }

    return true;
}

bool appInitializeData(void *app) {
    auto &tempApp = *(Application *) app;

    tempApp.temp_data.cin_read.value.push_back(vectorDataInitialize());

    if (!tempApp.temp_data.plato_candidate.value.empty() && tempApp.temp_data.plato_candidate.value.back() != tempApp.
        temp_data.cin_read.value.back()) {
        tempApp.temp_data.plato_candidate.value.clear();
    }
    tempApp.temp_data.plato_candidate.value.push_back(tempApp.temp_data.cin_read.value.back());

    return true;
}

bool appProcessData(void *app) {
    Application &tempApp = *(Application *) app;
    std::vector<int> column;

    if (tempApp.temp_data.plato_candidate.value.back() == tempApp.temp_data.cin_read.value.back() && tempApp.temp_data.
        plato_candidate.value.back() >= tempApp.constK) {
        if (tempApp.plato.row.empty() || tempApp.plato.row.back().back() != tempApp.temp_data.
            plato_candidate.value.back()) {
            tempApp.plato.row.push_back(column);
        }
        if (tempApp.plato.row.back().empty()) {
            tempApp.plato.row.back().push_back(tempApp.temp_data.cin_read.value.back());
        } else {
            tempApp.plato.row.back().push_back(tempApp.temp_data.cin_read.value.back());
        }
    }

    return true;
}

bool appGetOutput(void *app) {
    Application &tempApp = *(Application *) app;

    std::cout << tempApp.temp_data.output_counter + 1 << " plato is: ";

    for (int i: tempApp.plato.row[tempApp.temp_data.output_counter]) {
        std::cout << i << " ";
    }
    std::cout << "- (" << tempApp.plato.row[tempApp.temp_data.output_counter].size() << ")" << std::endl;
    ++tempApp.temp_data.output_counter;
    return true;
}

int appRun() {
    Application app;

    if (!operation(&appInitializeK, &app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    while (!std::cin.eof()) {
        //Get Value from cin
        if (!operation(&appInitializeData, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (!operation(&appProcessData, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        ++app.temp_data.temp_counter;
    }

    for (auto i: app.plato.row) {
        if (!operation(&appGetOutput, &app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }
    return 0;
}
