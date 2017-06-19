#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <time.h>

/**
 * @param a int[] Array principal
 * @param n int   Tamanho do array principal
 */
void parallelCountingSort(int a[], int n){
    int i, j, count;
    int *temp = malloc(n*sizeof(int));

    /**
     * Bloco para dividir o array principal entre as threads.
     */
#pragma omp parallel for shared(a, n, temp) private(i, j, count)
    for(i = 0; i < n; i++){
        count = 0;
        /**
         * For para varrer todo o array em busca dos menores elementos em relação
         * ao elemento na posição i.
         */
        for(j = 0; j < n; j++){
            if(a[j] < a[i]){
                count++;
            }else if(a[j] == a[i] && j < i){
                count++;
            }
        }
        temp[count] = a[i];
    }

    /**
     * Bloco paralelizado para realizar a copia do array temp (temporário) para o principal (a),
     * utilizando as variaveis a, n, temp como compartilhadas e i como privada.
     */
#pragma omp parallel for shared(a, n, temp) private(i)
    for (i = 0; i < n; i++){
        a[i] = temp[i];
    }

    free(temp);
}

