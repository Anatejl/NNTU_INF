//
// Created by anatejl on 8/21/24.
//

#include "application.h"

int app_run(Application &app) {
    app_get_input(app);
    app_generate_batch(app);
    //app_evaluate_batch(app);
    //app_do_output(app);

    return 0;
}

bool app_get_input(Application &app) {
    //get n
    std::cout << "Input a N number to generate batch: " << std::endl;
    app.n = handler_get_int();

    //get delta
    std::cout << "Input a delta, which will serve as acceptable dimmensions drift: " << std::endl;
    app.delta = handler_get_int();

    return true;
}

bool app_generate_batch(Application &app) {
    batch_template to_push{};

    for (int i = 0; i < app.n; ++i) {
        to_push.a = i + 2;
        to_push.b = i * 2;
        to_push.is_good = true;

        app.batch.push_back(to_push);
    }

    //DEBUG: SHOW THE BATCH
    std::cout << "--- BEGIN DEBUG ENTRY ---" << std::endl;
    for (int i = 0; i < app.batch.size(); ++i) {
        std::cout << i+1 << ": " << std::endl;
        std::cout << "  " << app.batch[i].a << " - a" << std::endl;
        std::cout << "  " << app.batch[i].b << " - b" << std::endl;
    }
    std::cout << "--- END DEBUG ENTRY ---" << std::endl;
    return true;
}
