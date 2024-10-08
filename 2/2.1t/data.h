#ifndef NNTU_DATA_H
#define NNTU_DATA_H

#define INPUT_MAX_DOTS 5
#define CIRCLES_MAX 11

typedef struct arrayCircles {

    int x;
    int a;
    int y;
    int b;
    double R;

} arrayCircles;
arrayCircles circleMaster[CIRCLES_MAX];

typedef struct arrayInput {

    int a;
    int b;

} arrayInput;
arrayInput inputDot[INPUT_MAX_DOTS];

#endif //NNTU_DATA_H
