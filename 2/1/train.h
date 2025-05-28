#ifndef TRAIN_H
#define TRAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MODE_LEN 32
#define DIR_LEN 64

typedef struct {

    //1.1
    int index;
    //1.2
    bool is_long_distance; // 0: suburban, 1: long-distance
    //1.3
    char direction[DIR_LEN];
    //1.4
    int departure_time; // minutes since midnight
    //1.5
    char departure_mode[MODE_LEN];
    //1.6
    int arrival_time; // minutes since midnight

} Train;

int select_trains(Train trains_depot[], Train trains_selected[], int train_count, bool search_is_long_distance, int desired_time);
void print_trains(Train trains_selected[], int selected_num);

#endif // TRAIN_H