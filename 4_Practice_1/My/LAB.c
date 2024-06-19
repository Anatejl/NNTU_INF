//
// Created by Anatejl on 19.06.2024.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* ptr;
    int size;
// we will take the size of the array
    printf("Enter size of elements:");
    scanf("%d", &size);
// dynamically allocate memory using malloc() method.
    ptr = (int*)malloc(size * sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
    }
    else {
        printf("Memory successfully allocated using "
               "malloc.\n");
        // Get the elements of the array
        for (int j = 0; j < size; ++j) {
            ptr[j] = j + 10;
        }
        // Print the elements of the array
        printf("The elements of the array are: ");
        for (int k = 0; k < size; ++k) {
            printf("%d, ", ptr[k]);
        }
    }
    return 0;
}