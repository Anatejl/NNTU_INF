//
// Created by Anatejl on 14.11.2022.
//
//2. Заданную фамилию распечатать по диагонали два раза слева направо, а ниже – справа налево
#include <stdio.h>
#include <strings.h>

static void DiagonalPrint(string s)
{
    for (int i = 0; i < s.Length; i++)
        Console.WriteLine("{0," + (i + 1) + "}{0," + s.Length + "}", s[i]);
    for (int i = 0; i < s.Length; i++)
        Console.WriteLine("{0," + (s.Length - i) + "}{0," + s.Length + "}", s[i]);
}

//3. В заданную строку дописать K заданных символов с M-ой позиции
static string InsertChars(string s, char[] array, int index)
{
    return s.Insert(index, new string(array));
}