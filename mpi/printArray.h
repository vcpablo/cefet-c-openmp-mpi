#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int tamanho){
    int i;
    for(i = 0; i < tamanho; i++)
        printf("\t%d", array[i]);
}