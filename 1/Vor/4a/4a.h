#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 1000

void func_input(char str[MAX_LENGTH]);
void func_process(const char str[MAX_LENGTH], int word_count[1]);
void func_output(int word_count[1]);

#endif