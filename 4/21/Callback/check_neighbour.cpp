//
// Created by Anatejl on 17.06.2024.
//

#include <cmath>
#include "check_neighbour.h"

bool check_neighbour(int array[], int D){
    if (abs(((array[0]-array[1])+(array[0]-array[2])+(array[1]-array[2]))) < D){
        return true;
    }
    else{
        return false;
    }
}