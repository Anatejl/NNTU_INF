#ifndef TRAIN_H
#define TRAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MODE_LEN 32
#define DIR_LEN 64

typedef struct {
    int index;
    bool is_long_distance; // false: suburban, true: long-distance
    char direction[DIR_LEN];
    int departure_time; // minutes since midnight
    char departure_mode[MODE_LEN];
    int arrival_time; // minutes since midnight
} Train;

int select_trains(Train trains_depot[], Train trains_selected[], int train_count, bool is_long_distance, int desired_time);
void print_trains(Train trains_selected[], int selected_num);

#endif // TRAIN_H