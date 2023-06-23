#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct {
    int hours;
    int minuts;
    int sum_minuts;
}Time;

typedef struct {
    int type; //1- пригородный электропоезд, 2- поезд дальнего следования
    char destination[20];
    int mode; //1-ежедневно, 2-по четным, 3-по нечетным дням, 4-кроме праздников, 5- конкретный день недели
    Time departure;
    Time arrival;
}train;

//прототип функции сортировки
void sorting(train* sort_list, int sort_quant);

//прототип функции поиска
int search(train* p_schedule, int quant, train* p_search_list, int search_type, Time search_time);

//максимальное количество записей
const int MaxTrains = 30;

int main()
{
    //локализация русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Программа: Поиск поезда в расписании\nАвтор: Бахметьев К.В.\n");

    train schedule[MaxTrains], search_list[MaxTrains], result;
    Time required_time;
    int i, required_type, quantity, index;

    printf("\nВведите количество поездов в расписании: ");
    scanf("%d", &quantity);
    
    printf("Введите данные расписания.\n");

    //ввод записей
    for (i = 0; i < quantity; i++)
    {
        printf("\nТип поезда (1-2): ");
        scanf("%d", &schedule[i].type);

        switch (schedule[i].type)
        {
        case 1:
        {
            printf("\tВы ввели тип \"Пригородный электропоезд\"");
            break;
        }
        case 2:
        {
            printf("\tВы ввели тип \"Поезд дальнего следования\"");
            break;
        }
        default:
            printf("\tОшибка!");
        }

        printf("\nПункт назначения: ");
        while (getchar() != '\n');
        fgets(schedule[i].destination, 20, stdin);

        printf("Режим отправления (1-5): ");
        scanf("%d", &schedule[i].mode);

        switch (schedule[i].mode)
        {
        case 1:
        {
            printf("\tВы ввели режим отправления \"Ежедневно\"");
            break;
        }
        case 2:
        {
            printf("\tВы ввели режим отправления \"По четным дням\"");
            break;
        }
        case 3:
        {
            printf("\tВы ввели режим отправления \"По нечетным дням\"");
            break;
        }
        case 4:
        {
            printf("\tВы ввели режим отправления \"Кроме праздников\"");
            break;
        }
        case 5:
        {
            printf("\tВы ввели режим отправления \"В конкретный день недели\"");
            break;
        }
        default:
            printf("\tОшибка!");
        }

        printf("\nВремя отправления (ЧЧ.ММ): ");
        scanf("%d.%d", &schedule[i].departure.hours, &schedule[i].departure.minuts);

        //перевод времени в минуты
        schedule[i].departure.sum_minuts = (schedule[i].departure.hours) * 60 + schedule[i].departure.minuts;

        printf("Время прибытия(ЧЧ.ММ): ");
        scanf("%d.%d", &schedule[i].arrival.hours, &schedule[i].arrival.minuts);
    }

    //ввод критерия поиска
    printf("\nВведите требуемый тип поезда (1- пригородный электропоезд, 2- поезд дальнего следования): ");
    scanf("%d", &required_type);
    printf("Введите требуемое время (ЧЧ.ММ): ");
    scanf("%d.%d", &required_time.hours, &required_time.minuts);

    //перевод времени в минуты
    required_time.sum_minuts = (required_time.hours) * 60 + required_time.minuts;

    printf("\nВаш запрос: ");
    switch (required_type)
    {
        case 1:
        {
            printf("Пригородный электропоезд, ");
            break;
        }
        case 2:
        {
            printf("Поезд дальнего следования, ");
            break;
        }
        default:
            printf("Ошибка! ");
    }
    printf("желаемое время отправления %.2u:%.2u\n", required_time.hours, required_time.minuts);

    //проверка, что введено корректное условие поиска
    if ((required_type == 1) || (required_type == 2))
    {
        index = search(schedule, quantity, search_list, required_type, required_time);

        printf("\nНайден поезд, наиболее подходящий по времни:\nНаправление: %s", search_list[index].destination);
        printf("Время отправления: %.2u:%.2u", search_list[index].departure.hours, search_list[index].departure.minuts);
    }
    else
        printf("Внимание! Введены некорректные данные.");

    return 0;
}


int search(train* p_schedule, int quant, train* p_search_list, int search_type, Time search_time)
{
    int i, j, quantity_list, flag, difference, temp_diff;

    //фильтр массива данных по введенному типу поезда
    for (i = j = 0; i < quant; i++)
    {
        if (search_type == (p_schedule + i)->type)
        {
            *(p_search_list + j) = *(p_schedule + i);
            j++;
        }
    }

    //определение количества отобранных поездов
    quantity_list = j;

    //условие наличия нужных структур
    if (quantity_list > 0)
        // функция сортировки вставками по возрастанию времени
        sorting(p_search_list, quantity_list);
    else
        printf("Поездов данного типа не найдено");

    //поиск поезда, удовлетворяющего условию (поиск минимальной разности во времени (в минутах))
    //по умолчанию результат поиска - нулевой элемент массива
    difference = abs(p_search_list->departure.sum_minuts - search_time.sum_minuts);
    flag = 0;

    for (i = 1; i < quantity_list; i++)
    {
        temp_diff = abs((p_search_list + i)->departure.sum_minuts - search_time.sum_minuts);
        if (temp_diff < difference)
        {
            difference = temp_diff;
            flag = i;
        }
    }

    return flag;
}

//функция сортировки вставками
void sorting(train* sort_list, int sort_quant)
{
    int i, j;
    train temp;
    for (i = 1; i < sort_quant; i++)
    {
        temp = *(sort_list + i);
        for (j = i - 1; j >= 0; j--)
        {
            if (((sort_list + j)->departure.sum_minuts) < (temp.departure.sum_minuts))
                break;

            *(sort_list + j + 1) = *(sort_list + j);
            *(sort_list + j) = temp;
        }
    }
}