#include "coin.h"

int select_coins(Coin coins_collection[], Coin coins_selected[], int coin_count, int year, int price) {
    int found = 0;
    for (int i = 0; i < coin_count; ++i) {
        if (coins_collection[i].year <= year && coins_collection[i].price >= price) {
            coins_selected[found].index = coins_collection[i].index;
            strcpy(coins_selected[found].name, coins_collection[i].name);
            coins_selected[found].price = coins_collection[i].price;
            coins_selected[found].year = coins_collection[i].year;
            found++;
        }
    }
    return found;
}

void print_coins(Coin coins_selected[], int selected_num) {
    if (selected_num == 0) {
        printf("No coins are applicable.\n");
        return;
    }
    printf("Applicable coins:\n");
    for (int i = 0; i < selected_num; ++i) {
        printf("%d. %s %d %d\n", coins_selected[i].index, coins_selected[i].name, coins_selected[i].price, coins_selected[i].year);
    }
}

int main() {
    int coin_count;
    printf("Enter number of coins: ");
    scanf("%d", &coin_count);

    Coin *coins_collection = malloc(sizeof(Coin) * coin_count);
    if (!coins_collection) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < coin_count; ++i) {
        coins_collection[i].index = i + 1;
        printf("Enter name for the coin %d: ", i + 1);
        scanf("%s", coins_collection[i].name);
        printf("Enter price for the coin %d: ", i + 1);
        scanf("%d", &coins_collection[i].price);
        printf("Enter year for the coin %d: ", i + 1);
        scanf("%d", &coins_collection[i].year);
    }

    int year, price;
    printf("Enter a year (coins from this year or earlier will be considered): ");
    scanf("%d", &year);
    printf("Enter a price (coins with this price or higher will be considered): ");
    scanf("%d", &price);

    Coin *coins_selected = malloc(sizeof(Coin) * coin_count);
    if (!coins_selected) {
        printf("Memory allocation failed.\n");
        free(coins_collection);
        return 1;
    }

    int selected_num = select_coins(coins_collection, coins_selected, coin_count, year, price);
    print_coins(coins_selected, selected_num);

    free(coins_collection);
    free(coins_selected);

    return 0;
}