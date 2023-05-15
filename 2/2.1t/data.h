#ifndef NNTU_DATA_H
#define NNTU_DATA_H

#define INPUT_MAX_DOTS 5
#define CIRCLES_MAX 11

typedef struct arrayCircles {

    int x;
    int a;
    int y;
    int b;

} arrayCircles;
arrayCircles circleCode[CIRCLES_MAX];

typedef struct cirRad {

    double R;

} circleRad;
circleRad circleRadius[CIRCLES_MAX];

typedef struct arrayInput {

    int x;
    int y;

} arrayInput;
arrayInput inputDot[INPUT_MAX_DOTS];

#endif //NNTU_DATA_H
