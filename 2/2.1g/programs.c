
#include <stdio.h>
#include <string.h>
#include "programs.h"

void printPrograms(struct Program programs[], int size, char target_day[], char start_time[], char end_time[]) {
    printf("Spisok peredach na %s v intervale %s - %s:\n", target_day, start_time, end_time);

    // Перебираем все передачи
    for (int i = 0; i < size; i++) {
        // Проверяем соответствие дня и времени передачи с заданными значениями
        if (strcmp(programs[i].day, target_day) == 0 &&
            strcmp(programs[i].start_time, start_time) >= 0 &&
            strcmp(programs[i].end_time, end_time) <= 0) {
            printf("- %s (%s)\n", programs[i].name, programs[i].channel);
        }
    }
}

struct Program programs[] = {
    
    {"Monday", "Channel 1", "18:00", "19:30", "News"},
    {"Monday", "Channel 2", "19:00", "20:30", "Serial"},
    {"Tuesday", "Channel 1", "20:00", "21:30", "Film"},
    {"Tuesday", "Channel 2", "17:00", "19:30", "Second Film"},
    {"Wednesday", "Channel 1", "21:00", "22:30", "Doc Film"},
    {"Wednesday", "Channel 2", "13:00", "17:30", "Documentary Film"},
    {"Thursday", "Channel 1", "19:30", "21:00", "Sports"},
    {"Thursday", "Channel 2", "20:00", "21:30", "Comedy Show"},
    {"Friday", "Channel 1", "18:30", "20:00", "Talk Show"},
    {"Friday", "Channel 2", "19:30", "21:00", "Drama"},
    {"Saturday", "Channel 1", "17:30", "19:00", "Cooking Show"},
    {"Saturday", "Channel 2", "18:00", "19:30", "Reality Show"},
    {"Sunday", "Channel 1", "16:30", "18:00", "Kids Program"},
    {"Sunday", "Channel 2", "17:00", "18:30", "Action Movie"},

    // Добавьте остальные передачи сюда
};

const int programs_count = sizeof(programs) / sizeof(programs[0]);
