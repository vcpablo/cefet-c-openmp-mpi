#include <mpi.h>
#include <time.h>

#include "populateArray.h"
#include "printArray.h"
#include "position.h"

void mpiCountingSort(int my_rank, int comm_sz, int tamanho, MPI_Comm grupo){
    int i, j, contador, contadorInterno, tamanhoLocal, tamanhoDosDados;
    int array[tamanho];
    posicao arrayLocal[tamanho/comm_sz], posicoes[tamanho];

    if(my_rank == 0){
        popularArray(array, tamanho);
        printf("Pré CountSort: ");
        printArray(array, tamanho);
    }

    // Disponibiliza o array com os itens a serem ordenados
    MPI_Bcast(array, tamanho, MPI_INT, 0, grupo);

    tamanhoLocal = tamanho / comm_sz;
    // Loop para 'varrer' as posições do array de cada processo
    for(i = tamanhoLocal * my_rank, contadorInterno = 0; i < tamanhoLocal * (my_rank+1); i++){
        contador = 0;
        // Loop interno que ordenará o pedaço do array destinado ao processo em questão
        for(j = 0; j < tamanho; j++){
            if((array[j] < array[i]) || (array[j] == array[i]) && (j < i)){
                contador++;
            }
        }
        arrayLocal[contadorInterno].pos = contador;
        arrayLocal[contadorInterno].val = array[i];
        contadorInterno++;
    }

    tamanhoDosDados = tamanhoLocal * sizeof(posicao);
    // Reune os arrays locais de cada processo na variável posicoes
    MPI_Gather(arrayLocal, tamanhoDosDados, MPI_BYTE, posicoes, tamanhoDosDados, MPI_BYTE, 0, grupo);

    if(my_rank == 0){
        // Ordena o array com as novas posicoes
        for(i = 0; i < tamanho; i++){
            array[posicoes[i].pos] = posicoes[i].val;
        }
        printf("\n\n");
        printf("PÓS CountSort:\t");
        printArray(array, tamanho);
    }
}