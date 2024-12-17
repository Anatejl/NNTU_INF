//VAR 9
#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

void func_input(char *str);
void func_process(char *str, int *word_count);
void func_output(int *word_count);

#endif