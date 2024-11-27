#include "vector_handle.h"
#include <iostream>

std::vector<int> vector_fill(int n){
    std::vector<int> to_return;
    int temp_int;
    for(int i = 0; i < n; ++i){
        std::cout << "Input a_" << i+1 << " / " << "a_" << n << " character:" << std::endl;
        std::cin >> temp_int;
        to_return.push_back(temp_int);
    }
    return to_return;
}

int vector_count_odd(std::vector<int>to_compute){
    int counter = 0;
    for(int i : to_compute){
        if ( i % 2 && i != 0){
            ++counter;
        }
    }
    return counter;
}

int vector_count_even(std::vector<int>to_compute){
    int counter = 0;
    for(int i : to_compute){
        if ( !(i % 2) && i != 0){
            ++counter;
        }
    }
    return counter;
}

int vector_count_zeroes(std::vector<int>to_compute){
    int counter = 0;
    for(int i : to_compute){
        if ( i == 0 ){
            ++counter;
        }
    }
    return counter;
}

void vector_show(std::vector<int>to_compute){
    //DEBUG
    std::cout << "Vector is: " << std::endl;
    for (int i : to_compute){
        std::cout << i << " "; 
    }
    std::cout << std::endl;
}