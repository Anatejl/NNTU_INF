#include "train.h"

int select_trains(Train trains_depot[], Train trains_selected[], int train_count, bool is_long_distance, int desired_time) {
    int min_diff = 1441; // More than a day in minutes
    int found = 0;
    for (int i = 0; i < train_count; ++i) {
        if (trains_depot[i].is_long_distance == is_long_distance) {
            int dep_time = trains_depot[i].departure_time;
            int diff = dep_time - desired_time;
            if (diff < 0) diff += 1440;  // Wrap around midnight
            if (diff < min_diff) {
                min_diff = diff;
                trains_selected[0] = trains_depot[i];
                found = 1;
            }
        }
    }
    return found;
}

void print_trains(Train trains_selected[], int selected_num) {
    if (selected_num == 0) {
        printf("No trains are applicable.\n");
        return;
    }
    printf("\nMost suitable train:\n");
    const char* type_str;
    if (trains_selected[0].is_long_distance) {
        type_str = "LongDistance";
    } else {
        type_str = "Suburban";
    }
    printf("%d. %s %s Dep: %02d:%02d Mode: %s Arr: %02d:%02d\n",
        trains_selected[0].index,
        type_str,
        trains_selected[0].direction,
        trains_selected[0].departure_time / 60, trains_selected[0].departure_time % 60,
        trains_selected[0].departure_mode,
        trains_selected[0].arrival_time / 60, trains_selected[0].arrival_time % 60
    );
}

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

    Train trains_selected[1];
    int selected_num = select_trains(trains_depot, trains_selected, train_count, search_is_long_distance, desired_time);
    print_trains(trains_selected, selected_num);

    free(trains_depot);

    return 0;
}