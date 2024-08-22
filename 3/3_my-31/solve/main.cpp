//main.cpp

#include "application.h"

int main() {

    char userAnswer = 'y';

    while (true) {

        std::cout << "Dot includance counter! V1.0" << std::endl;

        if (userAnswer == 'y') {

            application::app_run();

            std::cout << "Run program again? (y/n)" << std::endl;
            std::cin >> userAnswer;

        }

        else if (userAnswer == 'n') {

            return 0;

        }

        else {

            std::cout << "Invalid parameter, try again." << std::endl;
            std::cout << "Run program again? (y/n)" << std::endl;
            std::cin >> userAnswer;

        }
    }

    return 0;

}
