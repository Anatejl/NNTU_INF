//
// Created by anatejl on 8/21/24.
//
#include  "application.h"

int main(int argc, char* argv[]) {

    std::cout << "VAR 1" << std::endl;
    Application app;
    int ret = app_run(app);

    return ret;
}