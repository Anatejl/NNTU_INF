#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

void ArrayInit()
{
    ArrayCode[0].day.name_d = "Monday";
    ArrayCode[0].channel.name_ch = "One";
    ArrayCode[0].name_p = "Cartoon ";
    ArrayCode[0].start_time_hour = 0;
    ArrayCode[0].start_time_minute = 0;
    ArrayCode[0].end_time_hour = 6;
    ArrayCode[0].end_time_minute = 20;

    ArrayCode[1].day.name_d = "Monday";
    ArrayCode[1].channel.name_ch = "Two";
    ArrayCode[1].name_p = "Game Show";
    ArrayCode[1].start_time_hour = 6;
    ArrayCode[1].start_time_minute = 20;
    ArrayCode[1].end_time_hour = 15;
    ArrayCode[1].end_time_minute = 10;

    ArrayCode[2].day.name_d = "Monday";
    ArrayCode[2].channel.name_ch = "Three";
    ArrayCode[2].name_p = "Reality Show";
    ArrayCode[2].start_time_hour = 15;
    ArrayCode[2].start_time_minute = 10;
    ArrayCode[2].end_time_hour = 23;
    ArrayCode[2].end_time_minute = 59;

    ArrayCode[3].day.name_d = "Tuesday";
    ArrayCode[3].channel.name_ch = "One";
    ArrayCode[3].name_p = "Talk show";
    ArrayCode[3].start_time_hour = 0;
    ArrayCode[3].start_time_minute = 0;
    ArrayCode[3].end_time_hour = 7;
    ArrayCode[3].end_time_minute = 10;

    ArrayCode[4].day.name_d = "Tuesday";
    ArrayCode[4].channel.name_ch = "Two";
    ArrayCode[4].name_p = "The news";
    ArrayCode[4].start_time_hour = 7;
    ArrayCode[4].start_time_minute = 10;
    ArrayCode[4].end_time_hour = 10;
    ArrayCode[4].end_time_minute = 10;

    ArrayCode[5].day.name_d = "Tuesday";
    ArrayCode[5].channel.name_ch = "Three";
    ArrayCode[5].name_p = "Film   ";
    ArrayCode[5].start_time_hour = 10;
    ArrayCode[5].start_time_minute = 10;
    ArrayCode[5].end_time_hour = 23;
    ArrayCode[5].end_time_minute = 59;

    ArrayCode[6].day.name_d = "Wednesday";
    ArrayCode[6].channel.name_ch = "One";
    ArrayCode[6].name_p = "Sitcom ";
    ArrayCode[6].start_time_hour = 0;
    ArrayCode[6].start_time_minute = 0;
    ArrayCode[6].end_time_hour = 4;
    ArrayCode[6].end_time_minute = 30;

    ArrayCode[7].day.name_d = "Wednesday";
    ArrayCode[7].channel.name_ch = "Two";
    ArrayCode[7].name_p = "Soap opera";
    ArrayCode[7].start_time_hour = 4;
    ArrayCode[7].start_time_minute = 30;
    ArrayCode[7].end_time_hour = 15;
    ArrayCode[7].end_time_minute = 15;

    ArrayCode[8].day.name_d = "Wednesday";
    ArrayCode[8].channel.name_ch = "Three";
    ArrayCode[8].name_p = "Action film";
    ArrayCode[8].start_time_hour = 15;
    ArrayCode[8].start_time_minute = 15;
    ArrayCode[8].end_time_hour = 23;
    ArrayCode[8].end_time_minute = 59;

    ArrayCode[9].day.name_d = "Thursday";
    ArrayCode[9].channel.name_ch = "One";
    ArrayCode[9].name_p = "Western";
    ArrayCode[9].start_time_hour = 0;
    ArrayCode[9].start_time_minute = 0;
    ArrayCode[9].end_time_hour = 8;
    ArrayCode[9].end_time_minute = 00;

    ArrayCode[10].day.name_d = "Thursday";
    ArrayCode[10].channel.name_ch = "Two";
    ArrayCode[10].name_p = "Musical";
    ArrayCode[10].start_time_hour = 8;
    ArrayCode[10].start_time_minute = 00;
    ArrayCode[10].end_time_hour = 15;
    ArrayCode[10].end_time_minute = 15;

    ArrayCode[11].day.name_d = "Thursday";
    ArrayCode[11].channel.name_ch = "Three";
    ArrayCode[11].name_p = "Fairy tale";
    ArrayCode[11].start_time_hour = 15;
    ArrayCode[11].start_time_minute = 15;
    ArrayCode[11].end_time_hour = 23;
    ArrayCode[11].end_time_minute = 59; 
    
    ArrayCode[12].day.name_d = "Friday";
    ArrayCode[12].channel.name_ch = "One";
    ArrayCode[12].name_p = "Educational";
    ArrayCode[12].start_time_hour = 0;
    ArrayCode[12].start_time_minute = 0;
    ArrayCode[12].end_time_hour = 15;
    ArrayCode[12].end_time_minute = 45;

    ArrayCode[13].day.name_d = "Friday";
    ArrayCode[13].channel.name_ch = "Two";
    ArrayCode[13].name_p = "Fantasy";
    ArrayCode[13].start_time_hour = 15;
    ArrayCode[13].start_time_minute = 45;
    ArrayCode[13].end_time_hour = 20;
    ArrayCode[13].end_time_minute = 00;

    ArrayCode[14].day.name_d = "Friday";
    ArrayCode[14].channel.name_ch = "Three";
    ArrayCode[14].name_p = "Fiction";
    ArrayCode[14].start_time_hour = 20;
    ArrayCode[14].start_time_minute = 00;
    ArrayCode[14].end_time_hour = 23;
    ArrayCode[14].end_time_minute = 59;        

    ArrayCode[15].day.name_d = "Saturday";
    ArrayCode[15].channel.name_ch = "One";
    ArrayCode[15].name_p = "Feature film";
    ArrayCode[15].start_time_hour = 0;
    ArrayCode[15].start_time_minute = 0;
    ArrayCode[15].end_time_hour = 13;
    ArrayCode[15].end_time_minute = 45;

    ArrayCode[16].day.name_d = "Saturday";
    ArrayCode[16].channel.name_ch = "Two";
    ArrayCode[16].name_p = "Historical";
    ArrayCode[16].start_time_hour = 13;
    ArrayCode[16].start_time_minute = 45;
    ArrayCode[16].end_time_hour = 18;
    ArrayCode[16].end_time_minute = 59;

    ArrayCode[17].day.name_d = "Saturday";
    ArrayCode[17].channel.name_ch = "Three";
    ArrayCode[17].name_p = "Horror ";
    ArrayCode[17].start_time_hour = 18;
    ArrayCode[17].start_time_minute = 59;
    ArrayCode[17].end_time_hour = 23;
    ArrayCode[17].end_time_minute = 59;     

    ArrayCode[18].day.name_d = "Sunday";
    ArrayCode[18].channel.name_ch = "One";
    ArrayCode[18].name_p = "Comedy ";
    ArrayCode[18].start_time_hour = 0;
    ArrayCode[18].start_time_minute = 0;
    ArrayCode[18].end_time_hour = 17;
    ArrayCode[18].end_time_minute = 00;

    ArrayCode[19].day.name_d = "Sunday";
    ArrayCode[19].channel.name_ch = "Two";
    ArrayCode[19].name_p = "Melodrama";
    ArrayCode[19].start_time_hour = 17;
    ArrayCode[19].start_time_minute = 00;
    ArrayCode[19].end_time_hour = 21;
    ArrayCode[19].end_time_minute = 10;

    ArrayCode[20].day.name_d = "Sunday";
    ArrayCode[20].channel.name_ch = "Three";
    ArrayCode[20].name_p = "Mystery";
    ArrayCode[20].start_time_hour = 21;
    ArrayCode[20].start_time_minute = 10;
    ArrayCode[20].end_time_hour = 23;
    ArrayCode[20].end_time_minute = 59; 
}