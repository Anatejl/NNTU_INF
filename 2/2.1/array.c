//array.c
//
// Created by Anatejl on 03.05.2023.
//

#include "data.h"

//Explicitly filling main array.
void arrayInit() {

    // EU = 1
    // AS = 2
    // AF = 3
    // NA = 4

    //1
    strcpy(AccessCode[1].title, "Austria");
    strcpy(AccessCode[1].continent, "Europe");
    AccessCode[1].continentCode = 1;
    strcpy(AccessCode[1].population, "8,945");
    AccessCode[1].area = 82409;

    //2
    strcpy(AccessCode[2].title, "China");
    strcpy(AccessCode[2].continent, "Asia");
    AccessCode[2].continentCode = 2;
    strcpy(AccessCode[2].population, "1,393,601");
    AccessCode[2].area = 9596961;

    //3
    strcpy(AccessCode[3].title, "France");
    strcpy(AccessCode[3].continent, "Europe");
    AccessCode[3].continentCode = 1;
    strcpy(AccessCode[3].population, "67,458");
    AccessCode[3].area = 547557;

    //4
    strcpy(AccessCode[4].title, "Germany");
    strcpy(AccessCode[4].continent, "Europe");
    AccessCode[4].continentCode = 1;
    strcpy(AccessCode[4].population, "83,149");
    AccessCode[4].area = 348560;

    //5
    strcpy(AccessCode[5].title, "Iran");
    strcpy(AccessCode[5].continent, "Asia");
    AccessCode[5].continentCode = 1;
    strcpy(AccessCode[5].population, "88,628");
    AccessCode[5].area = 1628550;

    //6
    strcpy(AccessCode[6].title, "Italy");
    strcpy(AccessCode[6].continent, "Europe");
    AccessCode[6].continentCode = 1;
    strcpy(AccessCode[6].population, "60,273");
    AccessCode[6].area = 294140;

    //7
    strcpy(AccessCode[7].title, "Japan");
    strcpy(AccessCode[7].continent, "Asia");
    AccessCode[7].continentCode = 2;
    strcpy(AccessCode[7].population, "126,490");
    AccessCode[7].area = 364555;

    //8
    strcpy(AccessCode[8].title, "Kenya");
    strcpy(AccessCode[8].continent, "Africa");
    AccessCode[8].continentCode = 3;
    strcpy(AccessCode[8].population, "62,072");
    AccessCode[8].area = 569140;

    //9
    strcpy(AccessCode[9].title, "Luxembourg");
    strcpy(AccessCode[9].continent, "Europe");
    AccessCode[9].continentCode = 1;
    strcpy(AccessCode[9].population, "618");
    AccessCode[9].area = 2590;

    //10
    strcpy(AccessCode[10].title, "Mexico");
    strcpy(AccessCode[10].continent, "North America");
    AccessCode[10].continentCode = 4;
    strcpy(AccessCode[10].population, "140,450");
    AccessCode[10].area = 1943950;

    //11
    strcpy(AccessCode[11].title, "North Korea");
    strcpy(AccessCode[11].continent, "Asia");
    AccessCode[11].continentCode = 2;
    strcpy(AccessCode[11].population, "67,458");
    AccessCode[11].area = 547557;

    //12
    strcpy(AccessCode[12].title, "Norway");
    strcpy(AccessCode[12].continent, "Europe");
    AccessCode[12].continentCode = 1;
    strcpy(AccessCode[12].population, "5,560");
    AccessCode[12].area = 304280;

    //13
    strcpy(AccessCode[13].title, "Russian Federation");
    strcpy(AccessCode[13].continent, "Europe");
    AccessCode[13].continentCode = 1;
    strcpy(AccessCode[13].population, "139,955");
    AccessCode[13].area = 16377742;

    //14
    strcpy(AccessCode[14].title, "Serbia");
    strcpy(AccessCode[14].continent, "Europe");
    AccessCode[14].continentCode = 1;
    strcpy(AccessCode[14].population, "7,097");
    AccessCode[14].area = 77480;

    //15
    strcpy(AccessCode[15].title, "Spain");
    strcpy(AccessCode[15].continent, "Europe");
    AccessCode[15].continentCode = 1;
    strcpy(AccessCode[15].population, "47,750");
    AccessCode[15].area = 498980;

    //16
    strcpy(AccessCode[16].title, "Syria");
    strcpy(AccessCode[16].continent, "Asia");
    AccessCode[16].continentCode = 2;
    strcpy(AccessCode[16].population, "23,742");
    AccessCode[16].area = 183630;

    //17
    strcpy(AccessCode[17].title, "Turkey");
    strcpy(AccessCode[17].continent, "Asia");
    AccessCode[17].continentCode = 2;
    strcpy(AccessCode[17].population, "49,524");
    AccessCode[17].area = 197100;

    //18
    strcpy(AccessCode[18].title, "Uganda");
    strcpy(AccessCode[18].continent, "Africa");
    AccessCode[18].continentCode = 3;
    strcpy(AccessCode[18].population, "49,524");
    AccessCode[18].area = 197100;

    //19
    strcpy(AccessCode[19].title, "United States");
    strcpy(AccessCode[19].continent, "North America");
    AccessCode[19].continentCode = 4;
    strcpy(AccessCode[19].population, "352,912");
    AccessCode[19].area = 9147593;

    //20
    strcpy(AccessCode[20].title, "Zimbabwe");
    strcpy(AccessCode[20].continent, "Africa");
    AccessCode[20].continentCode = 3;
    strcpy(AccessCode[20].population, "14,611");
    AccessCode[20].area = 386850;

}