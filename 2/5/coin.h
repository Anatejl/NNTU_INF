#ifndef COIN_H
#define COIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50

typedef struct {
    int index;
    char name[NAME_LEN];
    int price;
    int year;
} Coin;

int select_coins(Coin coins_collection[], Coin coins_selected[], int coin_count, int year, int price);
void print_coins(Coin coins_selected[], int selected_num);

#endif // COIN_H