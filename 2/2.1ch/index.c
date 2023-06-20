#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "array.c"


int main(void)
{
    ArrayInit();

    int h1, h2, e1, e2;
    int dd = 0;
    int i;
    const char d[50];  
    
    //Введите день просмотра
    printf("Enter day watch: ");
    scanf("%s", d); 
    
    for (int i = 0; i <= ARRAY_SIZE; i++)
    {
        int r = strcmp(d, ArrayCode[i].day.name_d);
        if (r == 0)
        {
            dd = 1;
            i = 22;
        }
        else if ((i == ARRAY_SIZE) && (dd != 1))
        {
            printf("Enter day watch again (example: Monday): ");
            scanf("%s", d);
            i = 0;
        }
    }

    //Введите время начала просмотра в формате "00:00   :"
    printf("Enter time start watch (hh:mm): ");
    scanf("%d:%d", &h1, &h2);
    // printf("%d %d\n", h1, h2);

    int hh1 = 0;
    int hh2 = 0;
    for (hh1 = 0; hh1 <= 1; hh1++)
    {
        if ((h1 < 0) || (h1 > 23))
        {
            printf("Enter time start watch again: ");
            scanf("%d:%d", &h1, &h2);
            // printf("%d %d\n", h1, h2);
            hh1 = 0;
        }
        else
        {
            hh1 = 2;
        }        
    }

    for (hh2 = 0; hh2 <= 1; hh2++)
    {
        if ((h2 < 0) || (h1 > 59))
        {
            printf("Enter time start watch again: ");
            scanf("%d:%d", &h1, &h2);
            // printf("%d %d\n", h1, h2);
            hh2 = 0;
        }
        else
        {
            hh2 = 2;
        }        
    }

    printf("Enter time end watch: ");
    scanf("%d:%d", &e1, &e2);
    // printf("%d %d\n", e1, e2);

    int ee1 = 0;
    int ee2 = 0;
    for (ee1 = 0; ee1 <= 1; ee1++)
    {
        if ((e1 < 0) || (e1 > 23))
        {
            printf("Enter time end watch again: ");
            scanf("%d:%d", &e1, &e2);
            // printf("%d %d\n", e1, e2);
            ee1 = 0;
        }
        else
        {
            ee1 = 2;
        }        
    }

    for (ee2 = 0; ee2 <= 1; ee2++)
    {
        if ((e2 < 0) || (e1 > 59))
        {
            printf("Enter time end watch again: ");
            scanf("%d:%d", &e1, &e2);
            printf("%d %d\n", e1, e2);
            ee2 = 0;
        }
        else
        {
            ee2 = 2;
        }        
    }


    for (i = 0; i < 21; i++)
    {
        int r = strcmp(d, ArrayCode[i].day.name_d);
        if ((r == 0) && (h1 <= ArrayCode[i].start_time_hour) && (e1 >= ArrayCode[i].end_time_hour))
        {
            if (h1 < ArrayCode[i].start_time_hour)
            {
                if (e1 > ArrayCode[i].end_time_hour)
                {
                    printf("Day: %s\tChannel: %s\tProgram: %s\tStart time: %d:%d \tEnd time: %d:%d\n", ArrayCode[i].day.name_d, ArrayCode[i].channel.name_ch, ArrayCode[i].name_p, ArrayCode[i].start_time_hour, ArrayCode[i].start_time_minute, ArrayCode[i].end_time_hour, ArrayCode[i].end_time_minute);
                }
                else if ((e1 == ArrayCode[i].end_time_hour) && (e2 >= ArrayCode[i].end_time_minute))
                {
                    printf("Day: %s\tChannel: %s\tProgram: %s\tStart time: %d:%d \tEnd time: %d:%d\n", ArrayCode[i].day.name_d, ArrayCode[i].channel.name_ch, ArrayCode[i].name_p, ArrayCode[i].start_time_hour, ArrayCode[i].start_time_minute, ArrayCode[i].end_time_hour, ArrayCode[i].end_time_minute);
                }
            }
            else if ((h1 == ArrayCode[i].start_time_hour) && (h2 <= ArrayCode[i].start_time_minute))
            {
                if (e1 > ArrayCode[i].end_time_hour)
                {
                    printf("Day: %s\tChannel: %s\tProgram: %s\tStart time: %d:%d \tEnd time: %d:%d\n", ArrayCode[i].day.name_d, ArrayCode[i].channel.name_ch, ArrayCode[i].name_p, ArrayCode[i].start_time_hour, ArrayCode[i].start_time_minute, ArrayCode[i].end_time_hour, ArrayCode[i].end_time_minute);
                }
                else if ((e1 == ArrayCode[i].end_time_hour) && (e2 >= ArrayCode[i].end_time_minute))
                {
                    printf("Day: %s\tChannel: %s\tProgram: %s\tStart time: %d:%d \tEnd time: %d:%d\n", ArrayCode[i].day.name_d, ArrayCode[i].channel.name_ch, ArrayCode[i].name_p, ArrayCode[i].start_time_hour, ArrayCode[i].start_time_minute, ArrayCode[i].end_time_hour, ArrayCode[i].end_time_minute);
                }            
            }
        }
    }
}