//
// Created by Anatejl on 15.05.2023.
//

#ifndef NNTU_DATA_H
#define NNTU_DATA_H

#define INPUT_MAX_DOTS 5
#define CIRCLES_MAX 11

typedef struct arrayCircles{

    int x1;
    int x2;
    int y1;
    int y2;

} arrayCircles;

arrayCircles circleCode[CIRCLES_MAX];

typedef struct cirRad{

    int R;

} circleRad;

circleRad circleRadius[CIRCLES_MAX];

typedef struct arrayInput{

    int x;
    int y;

} arrayInput;

arrayInput inputDot[INPUT_MAX_DOTS];

//typedef struct arrayFinal{
//
//    long ID;
//
//}arrayFinal;
//
//arrayFinal finalCode[1];


#endif //NNTU_DATA_H
