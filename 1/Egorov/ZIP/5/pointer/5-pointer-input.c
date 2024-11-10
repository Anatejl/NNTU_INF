#include "5-pointer-header.h"

//DEBUG STUFF
// #include <stdlib.h>
// #include <time.h>

void do_input(Company* company){
    
    printf("Welcome to our comanys' HR indexing system!\n");

    //artificially fill departments and reset it's counters to zeroes
    printf("\n--- FYI, known departments are:");
    for (int i = 0; i < DEPT_COUNT; i++) {

        company->known_departments[i] = 101 + i;
        printf(" %d", company->known_departments[i]);
        company->department_counts[i] = 0;

    }

    // GIVE THE RAND SOME RANDOM SEED, ALSO GETTING BOUNDARIES FOR RAND()
    // srand(time(NULL));
    // int upper_bound = company->known_departments[DEPT_COUNT-1];
    // int lower_bound = company->known_departments[DEPT_COUNT-DEPT_COUNT];
    // printf("\n\n%d - ub, %d - lb\n\n", upper_bound, lower_bound);

    //fill the employees
    for (int i = 0; i < HR_COUNT; ++i){

        printf("\n--- Enter details for employee %d of %d ---\n", i + 1, HR_COUNT);

        printf("\nInput a name: ");
        scanf("%49s", company->personnel[i].name);

        printf("Input a position: ");
        scanf("%49s", company->personnel[i].position);

        printf("Input an ID: ");
        scanf("%d", &company->personnel[i].id);

        printf("Input a department: ");
        scanf("%d", &company->personnel[i].department);

        // IS USED TO BATCH PSEUDO_RANDOMLY FILL DEPARTMENTS
        // company->personnel[i].department = rand() % (upper_bound-lower_bound+1) + lower_bound;
        // printf("GOD's FAVOUR IS UPON: %d", company->personnel[i].department);

    }

}