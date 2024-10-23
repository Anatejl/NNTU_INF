#include <stdio.h>
#include <stdbool.h>

typedef struct Variables{

    int n, d, a1;

}Variables;

bool get_input(Variables var){

    printf("Input n: ");
    scanf("%d", var.n);

    printf("Input a1: ");
    scanf("%d", var.a1);


    return true;
}

int main(){

    Variables var;

    get_input(var);

    return 0;

}