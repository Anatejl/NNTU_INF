#include "5-array-header.h"

    // char name[NAME_MAX_SIZE];
    // char position[NAME_MAX_SIZE];
    // int id;
    // int department;

Personnel get_input(Personnel personnel){

    for(int i = 0; i < HR_COUNT; ++i){

        printf("Input a name:\n");
        scanf("%s", personnel[i].name);
        fflush(stdin);

        printf("Input a position:\n");
        scanf("%s", personnel[i].position);
        fflush(stdin);

        printf("Input an id:\n");
        scanf("%d", personnel[i].id);
        while(getchar() != '\n');
        fflush(stdin);
        
        printf("Input a department:\n");
        scanf("%d", personnel[i].department);
        while(getchar() != '\n');
        fflush(stdin);

    }

    return personnel;
}