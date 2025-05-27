#include "train.h"

// Find the train of the specified type with the closest departure time >= given time
int select_trains(Train trains_depot[], Train trains_selected[], int train_count, bool is_long_distance, int desired_time) {
   
    int found = 0;
    int min_diff = 1441; // max minutes in a day + 1
    int min_idx = -1;

    for (int i = 0; i < train_count; ++i) {
        if (trains_depot[i].is_long_distance == is_long_distance) {
            int dep_time = trains_depot[i].departure_time;
            int diff = dep_time - desired_time;
            if (diff < 0) diff += 1440; // wrap around midnight
            if (diff < min_diff) {
                min_diff = diff;
                min_idx = i;
            }
        }
    }

    if (min_idx != -1) {
        trains_selected[found++] = trains_depot[min_idx];
    }

    return found;
}

void print_trains(Train trains_selected[], int selected_num) {
    
    if (selected_num == 0) {
        printf("No trains are applicable.\n");
        return;
    }
    printf("Applicable train(s):\n");

    for (int i = 0; i < selected_num; ++i) {

        const char* type_str;

        if (trains_selected[i].is_long_distance){
            type_str = "LongDistance";
        }
        else {
            type_str = "Suburban";
        }

        printf("%d. %s %s Dep: %02d:%02d Mode: %s Arr: %02d:%02d\n",

            trains_selected[i].index,
            type_str,
            trains_selected[i].direction,
            trains_selected[i].departure_time / 60, trains_selected[i].departure_time % 60,
            trains_selected[i].departure_mode,
            trains_selected[i].arrival_time / 60, trains_selected[i].arrival_time % 60

        );
    }
}

#ifndef TEST_BUILD
int main() {
    
    int train_count;
    printf("Enter number of trains: ");
    scanf("%d", &train_count);

    Train *trains_depot = malloc(sizeof(Train) * train_count);
    if (!trains_depot) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < train_count; ++i) {
        trains_depot[i].index = i + 1;
        int type_input;
        printf("Enter type for train %d (0 - Suburban, 1 - LongDistance): ", i + 1);
        scanf("%d", &type_input);
        trains_depot[i].is_long_distance = (type_input == 1);
        printf("Enter direction for train %d: ", i + 1);
        scanf("%s", trains_depot[i].direction);
        int h, m;
        printf("Enter departure time for train %d (HH MM): ", i + 1);
        scanf("%d %d", &h, &m);
        trains_depot[i].departure_time = h * 60 + m;
        printf("Enter departure mode for train %d: ", i + 1);
        scanf("%s", trains_depot[i].departure_mode);
        printf("Enter arrival time for train %d (HH MM): ", i + 1);
        scanf("%d %d", &h, &m);
        trains_depot[i].arrival_time = h * 60 + m;
    }

    int type_input, h, m;
    printf("Enter train type to search (0 - Suburban, 1 - LongDistance): ");
    scanf("%d", &type_input);
    bool search_is_long_distance = (type_input == 1);
    printf("Enter desired departure time (HH MM): ");
    scanf("%d %d", &h, &m);
    int desired_time = h * 60 + m;

    Train *trains_selected = malloc(sizeof(Train) * train_count);
    if (!trains_selected) {
        printf("Memory allocation failed.\n");
        free(trains_depot);
        return 1;
    }

    int selected_num = select_trains(trains_depot, trains_selected, train_count, search_is_long_distance, desired_time);
    print_trains(trains_selected, selected_num);

    free(trains_depot);
    free(trains_selected);

    return 0;
}
#endif // TEST_BUILD