#include "application.h"

int app_launch(Application &app){

    app_input(app);
    app_process(app);
    app_output(app);

    return 0;
}

bool app_input(Application& app){

    // std::cout << "Input n: " << std::endl;
    // std::cin >> app.n;

    //REMOVE ME
    app.n = 100;

    // std::cout << "Input a0: " << std::endl;
    // std::cin >> app.a0;

    //REMOVE ME
    app.a0 = 1;

    return true;
}

bool app_process(Application& app){

    app.array = vector_generate(app.a0, app.n);




    return true;
}

bool app_output(Application& app){

    //DEBUG
    for(int i : app.array){

        std::cout << i << " ";

    }


    return true;
}