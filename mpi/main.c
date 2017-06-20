#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>



#define TAMANHO_ARRAY 100

main(void){
    int my_rank, comm_sz;

    MPI_Init(NULL,NULL);

    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    mpiCountingSort(my_rank, comm_sz, TAMANHO_ARRAY, MPI_COMM_WORLD);

    MPI_Finalize();
}