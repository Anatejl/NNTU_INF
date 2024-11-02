#include "5-pointer-header.h"

void do_input(Personnel* employees, Aux* aux){

    //aux->known_departments[DEPT_COUNT] = 101, 102, 103, 104;
    aux->known_departments[0] = 101;
    aux->department_counts[DEPT_COUNT] = 0, 0, 0, 0;

    for (int i = 0; i < HR_COUNT; ++i){

        printf("\n--- Enter details for employee %d ---\n", i + 1);

        printf("\nInput a name: ");
        scanf("%49s", employees[i].name);

        printf("Input a position: ");
        scanf("%49s", employees[i].position);

        printf("Input an ID: ");
        scanf("%d", &employees[i].id);

        printf("Input a department: ");
        scanf("%d", &employees[i].department);

    }

}