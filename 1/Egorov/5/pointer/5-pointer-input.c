#include "5-pointer-header.h"

void do_input(Personnel* employees, Aux* aux){
    
    for (int i = 0; i < DEPT_COUNT; i++) {
        aux->known_departments[i] = 101 + i;
        aux->department_counts[i] = 0;
    }

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