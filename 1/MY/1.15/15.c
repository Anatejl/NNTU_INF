//
// Created by Anatejl on 14.12.2022.
//
// Task 5 - Var 14 - array // Beautified

#include <stdio.h>
#include <string.h>

#define NAME_MAX_SIZE 500

int input;
char userAnswer = 'y';

struct Library {
    char author[NAME_MAX_SIZE];
    int cypher;
    int udk;
    int year;
    char inplace[NAME_MAX_SIZE];
};
struct Library AccessCode[4];

int getInput() {
    printf("Welcome to our IT library.\n Which book you wish to access? (1 to 3)\n");
    scanf_s("%u", &input);

    return input;
}

char getOutput() {

    printf("\nBook: %d\n", input);
    printf(" Author: %s\n", AccessCode[input].author);
    printf(" Cypher: %u\n", AccessCode[input].cypher);
    printf(" UDK: %u\n", AccessCode[input].udk);
    printf(" Year: %u\n", AccessCode[input].year);
    printf(" In stock: %s\n", AccessCode[input].inplace);

    return 0;
}

int main() {

    strcpy(AccessCode[1].author, "AuthorOne");
    AccessCode[1].cypher = 1;
    AccessCode[1].udk = 1;
    AccessCode[1].year = 2001;
    strcpy(AccessCode[1].inplace, "yes");

    strcpy(AccessCode[2].author, "AuthorTwo");
    AccessCode[2].cypher = 2;
    AccessCode[2].udk = 2;
    AccessCode[2].year = 2002;
    strcpy(AccessCode[2].inplace, "no");

    strcpy(AccessCode[3].author, "AuthorThree");
    AccessCode[3].cypher = 3;
    AccessCode[3].udk = 3;
    AccessCode[3].year = 2003;
    strcpy(AccessCode[3].inplace, "yes");

    while (userAnswer == 'y') {

        getInput();
        getOutput();

        printf("\n");
        printf("Again? (y/n) :\n");
        scanf_s("%s", &userAnswer);
        printf("\n");
    }

    return 0;
}