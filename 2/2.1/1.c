//
// Created by Anatejl on 13.04.2023.
//
//2.1 SEEMS KURCOVAYA

#include <stdio.h>
#include <string.h>
#include <sqlite3.h>


//Making ease of inputting fixed values of strings
#define MAX_COUNTRY 195
#define MAX_NAME_SIZE 100

//Declaring array of said continents
struct CountryContinent{
    char name[MAX_NAME_SIZE];
};

struct CountryContinent Continent[8];

//Adding values into created continent array
void CountryContinentInit(){

    strcpy(Continent[1].name, "Asia");
    strcpy(Continent[2].name, "Africa");
    strcpy(Continent[3].name, "North America");
    strcpy(Continent[4].name, "South America");
    strcpy(Continent[5].name, "Antarctica");
    strcpy(Continent[6].name, "Europe");
    strcpy(Continent[7].name, "Oceania");

}

//Declaring main array
struct Country {
    int number;
    char name[7];
    char continent[MAX_NAME_SIZE];
    int population;
    int area;
};

struct Country sequentialNumber[MAX_COUNTRY];



void arrayInitialization(){

   //main array init

}


//Main
int main(void){

    arrayInitialization();
    CountryContinentInit();

    printf("Welcome to Hell.");
    printf("\n%s", Continent[1].name);

    return 0;
}

