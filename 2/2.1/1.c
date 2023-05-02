//
// Created by Anatejl on 13.04.2023.
//
//2.1 SEEMS KURCOVAYA

#include <stdio.h>
#include <string.h>
#include <sqlite3.h>


//Making ease of inputting fixed values of strings
//#define MAX_COUNTRY 195
//#define MAX_NAME_SIZE 100

//Parsing database
//int databaseInitialization() {


   // char *sql = "SELECT * FROM mytable";
//
   // rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
//
   // if (rc != SQLITE_OK) {
   //     fprintf(stderr, "SQL error: %s\n", err_msg);
   //     sqlite3_free(err_msg);
   //     sqlite3_close(db);
   //     return 1;
   // }
//};

//
////Declaring array of said continents
//struct CountryContinent{
//    char name[MAX_NAME_SIZE];
//};
//
//struct CountryContinent Continent[7];
//
////Adding values into created continent array
//void CountryContinentInit(){
//
//    strcpy(Continent[1].name, "Asia");
//    strcpy(Continent[2].name, "Africa");
//    strcpy(Continent[3].name, "North America");
//    strcpy(Continent[4].name, "South America");
//    strcpy(Continent[5].name, "Europe");
//    strcpy(Continent[6].name, "Oceania");
//
//}

//Declaring main array
//struct Country {
//    int number;
//    char name[7];
//    char continent[MAX_NAME_SIZE];
//    int population;
//    int area;
//};
//
//struct Country sequentialNumber[MAX_COUNTRY];

//calling data from DB
int callback(void *NotUsed, int argc, char **argv, char **azColName){
     int i;
     for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
      }
     printf("\n");
     return 0;
   }

//Main
int main(){

    printf("Welcome to Hell.\n");

    sqlite3 *db;
    sqlite3_stmt *res;
    char *error_message = 0;

    int rc = sqlite3_open("master.db", &db);
    if (rc != SQLITE_OK) {
        printf("Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;

    } else {
        printf("DB '%d' opened?\n", rc);
    }



    ,lkl
    mlml


    char *sql = sqlite3_mprintf("INSERT INTO MasterTable (Name) VALUES ('petya')");

    rc = sqlite3_exec(db, sql, 0 , 0, &error_message);

    if (rc != SQLITE_OK) {

        printf("Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);

        return 1;
    }
    else {
        printf("Prepared?\n");
    }

   // if (!sql) {
   //     printf("Out of memory\n");
   //     sqlite3_close(db);
//
   //     return 1;
   // }


    //char *sql = "SELECT * FROM Main WHERE ID <= 5";

    rc = sqlite3_step(res);

    if (rc == SQLITE_ROW) {
        printf("%s\n", sqlite3_column_text(res, 0));
    }

    if (rc != SQLITE_OK) {
        printf("SQL error: %s\n", error_message);
        sqlite3_free(error_message);
        sqlite3_close(db);

        return 1;
    }




    printf("SQLite3 version is: %s\n", sqlite3_libversion());

    sqlite3_finalize(res);
    sqlite3_close(db);
    return 0;
}

