#include "train.h"

int main() {
    Train trains[10] = {
        {1, false, "North",  480, "Daily",         540},  // 08:00 - 09:00
        {2, true,  "South",  600, "OddDays",       780},  // 10:00 - 13:00
        {3, false, "East",   720, "EvenDays",      780},  // 12:00 - 13:00
        {4, true,  "West",   900, "ExceptHoliday", 1080}, // 15:00 - 18:00
        {5, false, "North", 1020, "Monday",        1080}, // 17:00 - 18:00
        {6, true,  "South", 1140, "Friday",        1260}, // 19:00 - 21:00
        {7, false, "East",  1260, "Daily",         1320}, // 21:00 - 22:00
        {8, true,  "West",  360,  "Sunday",        600},  // 06:00 - 10:00
        {9, false, "North",  60,  "Saturday",      180},  // 01:00 - 03:00
        {10,true,  "South", 1380, "Daily",         60}    // 23:00 - 01:00
    };

    printf("All trains:\n");
    printf("Idx | Type         | Direction      | Dep  | Mode            | Arr\n");
    printf("----+--------------+---------------+------+-----------------+------\n");
    for (int i = 0; i < 10; ++i) {
        const char* type_str;
        if (trains[i].is_long_distance)
            type_str = "LongDistance";
        else
            type_str = "Suburban";
        printf("%-3d | %-12s | %-13s | %02d:%02d | %-15s | %02d:%02d\n",
            trains[i].index,
            type_str,
            trains[i].direction,
            trains[i].departure_time / 60, trains[i].departure_time % 60,
            trains[i].departure_mode,
            trains[i].arrival_time / 60, trains[i].arrival_time % 60
        );
    }

    printf("\nTest: Most appropriate suburban train for 16:30 (990 min):\n");
    Train selected[1];
    int found = select_trains(trains, selected, 10, false, 990); // 16:30
    print_trains(selected, found);

    printf("\nTest: Most appropriate long-distance train for 16:30 (990 min):\n");
    found = select_trains(trains, selected, 10, true, 990); // 16:30
    print_trains(selected, found);

    return 0;
}
