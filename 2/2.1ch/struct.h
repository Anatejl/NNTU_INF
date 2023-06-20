#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 21

struct days
{
    const char* name_d;
};

typedef struct days days;

struct channels
{
    char* name_ch;
};

typedef struct channels channels;

typedef struct
{
    struct days day;
    struct channels channel;
    char* name_p;
    int start_time_hour;
    int start_time_minute;
    int end_time_hour;
    int end_time_minute;
} programs;

programs ArrayCode[ARRAY_SIZE];

#endif