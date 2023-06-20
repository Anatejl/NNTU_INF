#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>


//информация о студенте
typedef struct {
    char name[25];
    char groupe[7];
    int rec_number;
    int scores[5];
}students;

//прототип функции обработки данных
int statistics(students *p_list, int num, int p_subject);

//максимальное количество записей в списке
const int MaxNumber = 30;

int main()
{
    //локализация русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf("Программа: Поиск студентов, имеющих задолженность\nАвтор: Оразов И.Д.\n");

    students list[MaxNumber];
    int number, i, i_end, subject;

    printf("\nВведите количество студентов: ");
    scanf("%d", &number);

    //Ввод списка студентов
    for (i = 0; i < number; i++)
    {
        //очистка консоли
        while (getchar() != '\n');

        printf("\nВведите ФИО студента: ");
        fgets(list[i].name, 25, stdin);
        list[i].name[strlen(list[i].name) - 1] = 0;

        printf("Введите номер группы: ");
        fgets(list[i].groupe, 7, stdin);
        
        printf("Введите номер зачетной книжки: ");
        scanf("%d", &list[i].rec_number);

        printf("Введите оценки по дисциплинам (информатика, математика, физика, русский, английский): ");
        scanf("%d,%d,%d,%d,%d", &list[i].scores[0], &list[i].scores[1], 
              &list[i].scores[2], &list[i].scores[3], &list[i].scores[4]);
    }

    //Ввод параметра обработки
    printf("\nВведите дисциплину, по которой нужна статистика");
    printf("\n(1-информатика, 2-математика, 3-физика, 4-русский, 5-английский: ");
    scanf("%d", &subject);
    subject--;

    //Выполнение функции обработки
    i_end = statistics(list, number, subject);

    //условие отсутствия студентов с задолженностями
    if (i_end == -1)
        printf("\nЗадолженностей не найдено");
    //вывод в консоль списка студентов с задолженностями
    else
    {
        printf("\nСтуденты, имеющие задолженности:\nФИО\t\t\tГруппа\n");
        for (i = 0; i <= i_end; i++)
        {
            //вывод результата 
            printf("%s\t\t%s", list[i].name, list[i].groupe);
        }
    }

    return 0;
}


int statistics(students *p_list, int num, int p_subject)
{
    int i, j, step, end = -1, flag;
    students temp;

    //сортировка по выбранному предмету сортировкой Шелла
    //выбор смещения "step"
    for (step = num / 2; step > 0; step /= 2)
    {
        //сортировка по возрастанию
        for (i = step; i < num; i++)
        {
            temp = *(p_list + i);
            for (j = i; j >= step; j -= step)
            {
                if ((temp.scores[p_subject]) < (p_list + j - step)->scores[p_subject])
                    *(p_list + j) = *(p_list + j - step);
                else
                    break;
            }
            *(p_list + j) = temp;
        }
    }

    //поиск индекса последнего студента с задолженностью в списке
    for (i = 0; i < num; i++)
    {
        flag = (p_list + i)->scores[p_subject];
        if (flag == 2)
            end = i;
        else
            break;
    }

    //функция возвращает найденный индекс
    return end;
}