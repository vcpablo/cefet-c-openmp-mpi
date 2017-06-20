#include <stdio.h>
#include <stdlib.h>

void populateArray(int array[], int tamanhoArray){
    int i = 0;
    for(i = 0; i < tamanhoArray; i++){
        if(i % 2 == 0){
            array[i] = i * 2;
        } else {
            array[i] = i;
        }
    }
}
