// VAR 11
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_POINTS 3


int main(){

    int x[NUMBER_OF_POINTS];

    int closest_value = 99999;
    int closest_index = 0;

    for (int i = 0; i < NUMBER_OF_POINTS; ++i){

        printf("Input dot (integer) %d\n", i+1);
        scanf("%d", &x[i]);

    }

    for(int i = 0; i < NUMBER_OF_POINTS; ++i){

        if (abs(x[i]) < abs(closest_value)){

            closest_value = x[i];
            closest_index = i+1;
        }

    }

    printf("Closest is dot %d, with value of %d\n", closest_index, closest_value);

    return 0;
}