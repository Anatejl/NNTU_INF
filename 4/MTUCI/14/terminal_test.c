#include <stdio.h>

int main (int argc, char* argv[]){

    printf("%d argc's\n\n", argc);

    for (int i = 0; i < argc; ++i){

        printf("%d - %s \n", i+1, argv[i]);
        
    }

    return 0;
}