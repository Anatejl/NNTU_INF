#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>

//структура описания футбольной команды
typedef struct {
    char team_name[15];
    int points;
    int scored;
    int missed;
    int goal_diff;
}team_list;

//структура описания матча
typedef struct {
    team_list team_1;
    team_list team_2;
}match_result;

//функция сортировки
void sort(team_list* sort_table, int sort_count);

//функция поиска
int search(team_list* search_table, int search_count, char* team_need);

//максимальные значения количества матчей и команд
const int max_matches = 10, max_teams = 20;

int main()
{
    //локализация русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Программа: Статистика футбольной команды\nАвтор: Бекетов А.С.\n");

    match_result matches[max_matches];
    team_list score_table[max_teams];
    char team_search[15];
    int i, j, match_count, team_count, index_need;

    printf("Введите количество сыгранных матчей: ");
    scanf("%d", &match_count);

    team_count = match_count * 2;

    for (i = j = 0; i < match_count; i++)
    {
        while (getchar() != '\n');
        printf("Введите результат %uго матча:\nКоманда ", i + 1);
        fgets(matches[i].team_1.team_name, 15, stdin);
        matches[i].team_1.team_name[strlen(matches[i].team_1.team_name) - 1] = 0;
        printf("Забито голов: ");
        scanf("%d", &matches[i].team_1.scored);
        while (getchar() != '\n');
        printf("Команда ");
        fgets(matches[i].team_2.team_name, 15, stdin);
        matches[i].team_2.team_name[strlen(matches[i].team_2.team_name) - 1] = 0;
        printf("Забито голов: ");
        scanf("%d", &matches[i].team_2.scored);

        //забитые голы одной команды - это пропущенные голы ее соперника
        matches[i].team_1.missed = matches[i].team_2.scored;
        matches[i].team_2.missed = matches[i].team_1.scored;

        //вычисление разницы забитых и пропущенных голов
        matches[i].team_1.goal_diff = matches[i].team_1.scored - matches[i].team_1.missed;
        matches[i].team_2.goal_diff = 0 - matches[i].team_1.goal_diff;

        //вычисление выигранных очков
        //победа первой команды
        if (matches[i].team_1.goal_diff > 0)
        {
            matches[i].team_1.points = 3;
            matches[i].team_2.points = 0;
        }

        //победа второй команды
        if (matches[i].team_1.goal_diff < 0)
        {
            matches[i].team_1.points = 0;
            matches[i].team_2.points = 3;
        }

        //ничья
        if (matches[i].team_1.goal_diff == 0)
        {
            matches[i].team_1.points = 1;
            matches[i].team_2.points = 1;
        }

        //создание турнироной таблицы
        score_table[j] = matches[i].team_1;
        j++;
        score_table[j] = matches[i].team_2;
        j++;
    }

    //сортировка по убыванию очков
    sort(score_table, team_count);

    //ввод критерия поиска
    while (getchar() != '\n');
    printf("\nВведите название искомой команды: ");
    fgets(team_search, 15, stdin);
    team_search[strlen(team_search) - 1] = 0;

    //поиск запрашиваемой команды
    index_need = search(score_table, team_count, team_search);

    //условие существования искомой команды
    if (index_need != 100)
    {
        printf("\nРезультат поиска:\nКоманда\tМесто\tОчки\tЗабито\tПропущено\n");
        printf("%s\t%d\t%d\t%d\t%d\n", score_table[index_need].team_name, (index_need + 1), 
               score_table[index_need].points, score_table[index_need].scored, 
               score_table[index_need].missed);
    }
    else
        printf("\nТакой команды не найдено\n");
    return 0;
}

//функция сортировки турнирной таблицы по убыванию очков и,
//в случае равенства очков, по возрастанию разности голов
void sort(team_list* sort_table, int sort_count)
{
    int i, j;
    team_list temp;

    for (i = 1; i < sort_count; i++)
    {
        temp = *(sort_table + i);
        for (j = i - 1; j >= 0; j--)
        {
            if ((((sort_table + j)->points) > temp.points) || \
               (((((sort_table + j)->points) == temp.points)) && \
               (((sort_table + j)->goal_diff) > temp.goal_diff)))
                break;

            *(sort_table + j + 1) = *(sort_table + j);
            *(sort_table + j) = temp;
        }
    }
}

//функция поиска введенной команды
int search(team_list* search_table, int search_count, char* team_need)
{
    int i, cmp, flag = 100;

    for (i = 0; i < search_count; i++)
    {
        //сравнение введенного названия с названием текущей команды
        cmp = strcmp(team_need, (search_table + i)->team_name);
        if (cmp == 0)
        {
            flag = i;
            break;
        }
    }
    return flag;
}