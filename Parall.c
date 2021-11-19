#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define ms 3
int main(int argc, char* argv[])
{
    int i,j,k;
    int x,c;
    int M_A[ms][ms];
    int M_B[ms][ms];
    int M_C[ms][ms];
    int rank, p;
    int NRPE;
    double starttime, endtime;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &p);
    MPI_Status status;
    NRPE = ms / p;
    if(rank == 0)
    {
        printf("\n La matrice A\n");
        printf("***************\n");

        for(i=0; i<ms; ++i)
            for(j=0; j<ms; ++j)
                M_A[i][j] =rand() % 10;
        for(i=0; i<ms; ++i)
        {
            for(j=0; j<ms; ++j)
                printf("%3d" , M_A[i][j]);
            printf("\n");
        }
        printf("\n La matrice B\n");
        printf("***************\n");
        for(x=0; x<ms; ++x)
            for(c=0; c<ms; ++c)
                M_B[x][c] = rand() % 10;
        for(x=0; x<ms; ++x)
        {
            for(c=0; c<ms; ++c)
                printf("%3d" , M_B[x][c]);
            printf("\n");
        }
    }
    MPI_Recv(M_A, ms*NRPE, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    starttime = MPI_Wtime();
    for(k=0; k<ms; k++)
    for(i=0; i<ms; i++){
        M_C[i][k] = 0;
        for(j=0; j<ms; j++)
            M_C[i][k] = M_C[i][k] + M_A[i][j] * M_B[j][k];
        }
        endtime =MPI_Wtime();
    MPI_Send(&M_C[i][k], ms*ms, MPI_INT, 0, 0, MPI_COMM_WORLD);
    if(rank == 0)
    {
        printf("\n Le Resultat de la multiplication de deux Matrices C :: \n");
        printf("\n");
            for(i=0; i<ms; i++)
            {
            printf("\n");
            for(k=0; k<ms; k++)
                printf("%3d" , M_C[i][k]);
            }
            printf("\n\n Le temps parallele est de :: %f seconds\n",endtime-starttime);
    }
    printf("***************\n");
    	return 0;
    for(i=0; i<ms; i++)
    {
        MPI_Bcast(M_B[i], ms*ms, MPI_INT, 0, MPI_COMM_WORLD);
    }
    printf("\n La matrice B PAR LE PROCESUS: %d\n",rank);
    for(x=0; x<ms; ++x)
    {
        for(c=0; c<ms; ++c)
            printf("%3d",M_B[x][c]);
        printf("\n");
    }
    for(i=0; i<p; i++)
    {
        for(j=0; j<ms; j++)
        {
            MPI_Send(&M_B[j], ms*NRPE,MPI_INT,i,0,MPI_COMM_WORLD);
            NRPE++;
        }
    }
    
       MPI_Finalize();
}
