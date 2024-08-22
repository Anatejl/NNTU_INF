//
// Created by anatejl on 8/21/24.
//

#include "handler.h"

#include <iostream>

int handler_get_int() {
    int input;

    std::cin >> input;
    std::cout << input << std::endl;

    return input;
}

/*
void handler_debug_show_the_batch(auto batch) {
    for (int i = 0; i < batch.size(); ++i) {
        std::cout << i << ": " << std::endl;
        std::cout << "  " << batch[i].a << " - a" << std::endl;
        std::cout << "  " << batch[i].b << " - b" << std::endl;
    }
}
*/
