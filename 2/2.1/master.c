//master.c
//
// Created by Anatejl on 13.04.2023.
//
//2.1 SEEMS KURCOVAYA

#include <stdio.h>
#include <stdlib.h>

//We include additional files, since they contain crucial code to run program.
#include "data.h"
#include "array.c"

//Function to get continent input from user, and allocate memory for it.
int *getInputID() {

    printf("Welcome to our cozy world archive. \n");
    printf("Choose a number of a continent: \nNote: (1-Europe, 2-Asia, 3-Africa, 4-North America)\n");
    int *inputID = malloc(INPUT_MAX_SIZE); //Allocating memory for first input variable.
    scanf_s("%d", inputID); //Storing value into inputID variable.
    fflush(stdin); //Command is used to clear input buffer.

    return inputID;
}

//Function to get area value from user, and also allocate memory for it.
int *getInputArea() {

    printf("\nWell, finally, input area in square thousands km, without any separators:\n");
    int *inputArea = malloc(INPUT_MAX_SIZE); //Allocating memory for second input variable.
    scanf_s("%d", inputArea); //Storing value into inputID variable.
    fflush(stdin); //Command is used to clear input buffer.

    return inputArea;
}

//Main function to process input information, and store it in another array.
void processing(int inputID, int inputArea) { //We're passing both input variables into function.

    for (int i = 1; i < ARRAY_MAX_SIZE; ++i) { //Invoking cycle, which shares length with main array.

        //For each iteration of cycle we are checking, for matches in requested country
        // and stored country code, if passed first, then result checked for match in area
        // inputted from user, if both gone well, iteration of cycle will add its I value
        // to corresponding place in final array, otherwise make it 0.
        if (inputID == AccessCode[i].continentCode && inputArea >= AccessCode[i].area) {
            arrayFinal[i].ID = i;
        } else {
            arrayFinal[i].ID = 0;
        }

    }
}

//Function to display resulting output to default output device.
void getOutput() {

    int resultControl = 1; //Declaring new variable to make results better.

    for (int i = 1; i < ARRAY_MAX_SIZE; ++i) { //Also introducing cycle, with same iteration amount,
        // as our arrays.

        if (arrayFinal[i].ID != 0) {
            //Now we are checking whether value of final array
            // is equal to 0, if negative, condition will output known data about country,
            // assigning resulting number to it.
            printf("\n%d. Title: %s\n", resultControl, AccessCode[i].title);
            printf("   Continent: %s\n", AccessCode[i].continent);
            printf("   Population: %s /thousands\n", AccessCode[i].population);
            printf("   Area %ld /TKM^2\n", AccessCode[i].area);
            resultControl++; //Adding +1 to variable, to continue numerating results.
        }
    }

    if (resultControl == 1) {
        //If happens for final array to not contain any values,
        // other than 0, condition will display error, marking that.
        printf("Insufficient query. Try again.");
    }

}

int main() {

    //Introducing variable to control repetitive style of a program.
    char userAnswer = 'y';

    while (userAnswer == 'y') { //First iteration run assuming that user is wanting that.

        arrayInit(); //Loading main array.

        int *inputID = getInputID(); //Getting first input.
        int *inputArea = getInputArea(); //Getting second input.

        processing(*inputID, *inputArea); //Invoke processing and pass necessary variables.

        getOutput(); //Getting output to standard device.

        free(inputID); //Freeing memory, allocated for input.
        free(inputArea); // Second time.

        //Prompting user to answer, whether he wishes to run program again,
        //if so, cycle will repeat one more time.
        printf("\n");
        printf("Run program again? (y/n):\n");
        scanf_s("%s", &userAnswer);
        printf("\n");
        fflush(stdin); //Resetting buffer.

    }
    return 0;
}