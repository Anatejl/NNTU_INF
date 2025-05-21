#include "coin.h"

void select_coins(Coin coins[], int coin_count, int year, int price) {
    printf("Selected coins:\n");
    for (int i = 0; i < coin_count; ++i) {
        if (coins[i].year <= year && coins[i].price >= price) {
            printf("%s %d %d\n", coins[i].name, coins[i].price, coins[i].year);
        }
    }
}

#ifndef TEST_BUILD
int main() {
    int coin_count;
    Coin coins[MAX_COINS];

    printf("Enter number of coins: ");
    scanf("%d", &coin_count);

    for (int i = 0; i < coin_count; ++i) {
        printf("Enter name for the coin %d: ", i + 1);
        scanf("%s", coins[i].name);
        printf("Enter price for the coin %d: ", i + 1);
        scanf("%d", &coins[i].price);
        printf("Enter year for the coin %d: ", i + 1);
        scanf("%d", &coins[i].year);
    }

    int year, price;
    printf("Enter a year: ");
    scanf("%d", &year);
    printf("Enter a price: ");
    scanf("%d", &price);

    select_coins(coins, coin_count, year, price);

    return 0;
}
#endif
