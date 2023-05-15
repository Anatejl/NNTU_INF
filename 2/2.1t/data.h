//
// Created by Anatejl on 15.05.2023.
//

#ifndef NNTU_DATA_H
#define NNTU_DATA_H

#define INPUT_MAX_DOTS 11
#define CIRCLES_MAX 11

typedef struct arrayCircles{

    int x;
    int y;

} arrayCircles;

arrayCircles circlesCode[CIRCLES_MAX];

typedef struct arrayInput{

    int x;
    int y;

} arrayInput;

arrayInput inputCode[INPUT_MAX_DOTS];

//typedef struct arrayFinal{
//
//    long ID;
//
//}arrayFinal;
//
//arrayFinal finalCode[1];


#endif //NNTU_DATA_H
