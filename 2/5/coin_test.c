#include <assert.h>
#include "coin.h"

#define ANSI_BG_GREEN "\033[42m"
#define ANSI_BG_RED   "\033[41m"
#define ANSI_RESET    "\033[0m"

int main() {
    Coin coins[] = {
        {1, "Penny", 1, 2000},
        {2, "Nickel", 5, 1995},
        {3, "Dime", 10, 2010},
        {4, "Quarter", 25, 1990},
        {5, "HalfDollar", 50, 1980},
        {6, "Euro", 100, 2020}
    };
    int coin_count = sizeof(coins) / sizeof(coins[0]);
    int year = 2000;
    int price = 5;

    printf("Test filter: year=%d, price=%d\n", year, price);

    // Print table header
    printf("+-------+------------+-------+------+-------------------+\n");
    printf("| %-5s | %-10s | %-5s | %-4s | %-16s|\n", "Index", "Name", "Price", "Year", "Selected");
    printf("+-------+------------+-------+------+-------------------+\n");

    // Print decision for each coin with color-coded selection, table format
    for (int i = 0; i < coin_count; ++i) {
        int year_ok = coins[i].year <= year;
        int price_ok = coins[i].price >= price;
        int selected = year_ok && price_ok;
        printf("| %-5d | %-10s | %-5d | %-4d | %s%-15s%s |\n",
            coins[i].index, coins[i].name, coins[i].price, coins[i].year,
            selected ? ANSI_BG_GREEN : ANSI_BG_RED,
            selected ? "YES" : "NO",
            ANSI_RESET
        );
    }
    printf("+-------+------------+-------+------+-------------------+\n");

    // Redirect stdout to buffer
    char buffer[512];
    FILE *orig_stdout = stdout;
    FILE *f = fmemopen(buffer, sizeof(buffer), "w");
    stdout = f;

    Coin coins_selected[coin_count];
    int selected_num = select_coins(coins, coins_selected, coin_count, year, price);
    print_coins(coins_selected, selected_num);

    fflush(f);
    stdout = orig_stdout;
    fclose(f);

    // Check output
    assert(strstr(buffer, "Nickel 5 1995") != NULL);      // selected
    assert(strstr(buffer, "Quarter 25 1990") != NULL);    // selected
    assert(strstr(buffer, "HalfDollar 50 1980") != NULL); // selected

    assert(strstr(buffer, "Penny") == NULL);   // not selected (price too low)
    assert(strstr(buffer, "Dime") == NULL);    // not selected (year too high)
    assert(strstr(buffer, "Euro") == NULL);    // not selected (year too high)

    // Also check that index is present in output for selected coins
    assert(strstr(buffer, "2. Nickel 5 1995") != NULL);
    assert(strstr(buffer, "4. Quarter 25 1990") != NULL);
    assert(strstr(buffer, "5. HalfDollar 50 1980") != NULL);

    printf("coin_test passed\n");
    return 0;
}
