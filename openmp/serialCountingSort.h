#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

/**
 * @param a int[] Array principal
 * @param n int   Tamanho do array principal
 */
void SerialCountSort(int a[], int n){
    int i, j, count;
    int *temp = malloc(n*sizeof(int));
    for(i = 0; i < n; i++){
        count = 0;
        for(j = 0; j < n; j++)
            if(a[j] < a[i])
                count++;
            else if(a[j] == a[i] && j < i)
                count++;
            temp[count] = a[i];
    }
    memcpy(a, temp, n*sizeof(int));
    free(temp);
}
