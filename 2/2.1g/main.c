
#include <stdio.h>
#include <string.h>
#include "programs.c"
#include "programs.h"

// Функция для ввода значения строки с проверкой на максимальную длину
void inputString(char str[], int max_length, const char* prompt) {
    printf("%s", prompt);
    scanf("%s", str);

    // Очищаем входной буфер от лишних символов
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    // Ограничиваем введенную строку максимальной длиной
    if (strlen(str) > max_length) {
        str[max_length] = '\0';
    }
}

int main() {
    // Вычисляем размер массива передач
    int size = programs_count;

    // Задаем целевой день и интервал времени
    char target_day[20];
    char start_time[10];
    char end_time[10];

    inputString(target_day, sizeof(target_day) - 1, "day of week: ");
    inputString(start_time, sizeof(start_time) - 1, "start time: ");
    inputString(end_time, sizeof(end_time) - 1, "end time: ");

    // Выводим список передач на заданный день и в заданный интервал времени
    printPrograms(programs, size, target_day, start_time, end_time);

    return 0;
}
