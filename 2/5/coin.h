#ifndef COIN_H
#define COIN_H

#define MAX_COINS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int price;
    int year;
} Coin;

void select_coins(Coin coins[], int coin_count, int year, int price);

#endif // COIN_H
