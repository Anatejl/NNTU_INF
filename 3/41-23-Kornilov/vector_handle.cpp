#include "vector_handle.h"
#include <iostream>

std::vector<int> vector_generate(int a0, int n){

    std::vector<int> to_return;

    //DEBUG:
    to_return.push_back(0);

    for(int i = 0; i < n; ++i){

        to_return.push_back(a0+i);

    }

    return to_return;

}

int vector_count_odd(std::vector<int>to_comppute){

    int counter = 0;

    for(int i : to_comppute){

        if ( i % 2 && i != 0){

            ++counter;

        }

    }

    return counter;
}

int vector_count_even(std::vector<int>to_comppute){

    int counter = 0;

    for(int i : to_comppute){

        if ( !(i % 2) && i != 0){

            ++counter;

        }

    }

    return counter;
}

int vector_count_zeroes(std::vector<int>to_comppute){

    int counter = 0;

    for(int i : to_comppute){

        if ( i == 0 ){

            ++counter;

        }

    }

    return counter;
}

void vector_show(std::vector<int>to_comppute){

    //DEBUG
    std::cout << "Vector is: " << std::endl;
    for (int i : to_comppute){

        std::cout << i << " "; 

    }
    std::cout << std::endl;

}