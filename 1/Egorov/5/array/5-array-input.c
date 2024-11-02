#include "5-array-header.h"

    // MEMO
    // char name[NAME_MAX_SIZE];
    // char position[NAME_MAX_SIZE];
    // int id;
    // int department;

Personnel get_input() {

    Personnel person;

    printf("\nInput a name: ");
    scanf("%49s", person.name);

    printf("Input a position: ");
    scanf("%49s", person.position);

    printf("Input an ID: ");
    scanf("%d", &person.id);

    printf("Input a department: ");
    scanf("%d", &person.department);

    return person;
}