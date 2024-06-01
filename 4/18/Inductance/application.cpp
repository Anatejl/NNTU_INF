//application.cpp
//
// Created by Anatejl on 20.04.2024.
//

#include "application.h"
#include <iostream>

int appRun(Application &app) {

    if (!appInitializeK(app)) {
        std::cout << "DATA INPUT FAILURE." << std::endl;
        return 1;
    }

    while (!std::cin.eof()) {
        //Get Value from cin
        if (!appInitializeData(app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        if (!appProcessData(app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }

        ++app.temp_data.temp_counter;
    }

    for (auto i: app.plato.row) {
        if (!appGetOutput(app)) {
            std::cout << "DATA INPUT FAILURE." << std::endl;
            return 1;
        }
    }

    return 0;
}

bool appInitializeK(Application& app) {

    std::cin >> app.constK;

    if (std::cin.fail()) {
        return false;
    }

    return true;
}

bool appInitializeData(Application& app) {

    app.temp_data.cin_read.value.push_back(vectorDataInitialize());

    if (!app.temp_data.plato_candidate.value.empty() && app.temp_data.plato_candidate.value.back() != app.
        temp_data.cin_read.value.back()) {
        app.temp_data.plato_candidate.value.clear();
    }
    app.temp_data.plato_candidate.value.push_back(app.temp_data.cin_read.value.back());

    return true;
}

bool appProcessData(Application& app) {

    std::vector<int> column;

    if (app.temp_data.plato_candidate.value.back() == app.temp_data.cin_read.value.back() && app.temp_data.
        plato_candidate.value.back() >= app.constK) {
        if (app.plato.row.empty() || app.plato.row.back().back() != app.temp_data.
            plato_candidate.value.back()) {
            app.plato.row.push_back(column);
        }
        if (app.plato.row.back().empty()) {
            app.plato.row.back().push_back(app.temp_data.cin_read.value.back());
        } else {
            app.plato.row.back().push_back(app.temp_data.cin_read.value.back());
        }
    }

    return true;
}

bool appGetOutput(Application& app) {

    std::cout << app.temp_data.output_counter + 1 << " plato is: ";

    for (int i: app.plato.row[app.temp_data.output_counter]) {
        std::cout << i << " ";
    }
    std::cout << "- (" << app.plato.row[app.temp_data.output_counter].size() << ")" << std::endl;
    ++app.temp_data.output_counter;

    return true;
}
