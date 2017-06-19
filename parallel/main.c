#include "parallelCountingSort.h"
#include "serialCountingSort.h"

#include "populateArray.h"

#define TAMANHO_ARRAY 10000

int main(){
    int array [TAMANHO_ARRAY];
    int i = 0;
    clock_t tInicio, tFim, tDecorrido;

    /**
    *   Serial
    */
    populateArray(array, TAMANHO_ARRAY);

    /** CONTADOR DE TEMPO */
    tInicio = clock();
    SerialCountSort(array, TAMANHO_ARRAY); /** executa o countsort **/
    tFim = clock();
    double tempo = (float)(tFim - tInicio) / CLOCKS_PER_SEC;
    /** CONTADOR DE TEMPO */

    printf("Serial:");

    /** Bloco para conferir se elementos foram ordenados **/
    /*
    printf("\n");
    for(i = 0; i < TAMANHO_ARRAY; i++){
        printf("%d\t", array[i]);
    }
    */

    printf("\nTempo: %f", tempo);

    // ------------------------------------------

    /**
    *   Paralelo
    */
    populateArray(array, TAMANHO_ARRAY);

    /** CONTADOR DE TEMPO */
    tInicio = clock();
    parallelCountingSort(array, TAMANHO_ARRAY); /** executa o countsort **/
    tFim = clock();
    tempo = (float)(tFim - tInicio) / CLOCKS_PER_SEC;
    /** CONTADOR DE TEMPO */

    printf("\n\nParalela:");

    /** Bloco para conferir se elementos foram ordenados **/
    /*
    printf("\n");
    i = 0;
    for(i = 0; i < TAMANHO_ARRAY; i++){
        printf("%d\t", array[i]);
    }
    */

    printf("\nTempo: %f", tempo);

    printf("\n\n");
    return 0;
}
