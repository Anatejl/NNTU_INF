//header.h
#ifndef solve_H_
#define solve_H_

#include <iostream>
#include <vector>
#include <algorithm>

struct IrNumber {
    int x;
    int y;

    int getSquareOfRadius() {
        return x * x + y * y;
    }
};

#endif