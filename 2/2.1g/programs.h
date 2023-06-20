#ifndef PROGRAMS_H
#define PROGRAMS_H

// Структура для хранения информации о передаче
struct Program {
    char day[20];
    char channel[20];
    char start_time[10];
    char end_time[10];
    char name[50];
};

// Функция для вывода списка передач на заданный день и в заданный интервал времени
void printPrograms(struct Program programs[], int size, char target_day[], char start_time[], char end_time[]);

#endif