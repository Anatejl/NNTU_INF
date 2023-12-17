#ifndef solve_H_
#define solve_H_


struct IrNumber {
    int x;
    int y;

    int getSquareOfRadius() {
        return x * x + y * y;
    }
};

#endif