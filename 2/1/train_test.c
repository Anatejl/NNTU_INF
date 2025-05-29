#include "train.h"

int main() {
    int train_count = 10;
    printf("Enter number of trains: %d\n", train_count);

    Train trains_depot[10] = {
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

    for (int i = 0; i < train_count; ++i) {
        printf("Enter type for train %d (0 - Suburban, 1 - LongDistance): %d\n", i + 1, trains_depot[i].is_long_distance ? 1 : 0);
        printf("Enter direction for train %d: %s\n", i + 1, trains_depot[i].direction);
        printf("Enter departure time for train %d (HH MM): %02d %02d\n", i + 1, trains_depot[i].departure_time / 60, trains_depot[i].departure_time % 60);
        printf("Enter departure mode for train %d: %s\n", i + 1, trains_depot[i].departure_mode);
        printf("Enter arrival time for train %d (HH MM): %02d %02d\n", i + 1, trains_depot[i].arrival_time / 60, trains_depot[i].arrival_time % 60);
    }

    int type_input = 0; // Suburban
    int h = 16, m = 30;
    printf("Enter train type to search (0 - Suburban, 1 - LongDistance): %d\n", type_input);
    printf("Enter desired departure time (HH MM): %02d %02d\n", h, m);
    bool search_is_long_distance = (type_input == 1);
    int desired_time = h * 60 + m;

    Train trains_selected[10];
    int selected_num = select_trains(trains_depot, trains_selected, train_count, search_is_long_distance, desired_time);
    print_trains(trains_selected, selected_num);

    return 0;
}
