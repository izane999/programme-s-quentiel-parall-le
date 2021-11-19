#include <stdio.h>
#include <stdlib.h>

main()
{
    int A[40][40];
    int B[40][40];
    int C[40][40];
    int N, M, P;
    int I, J, K;
    printf("****** Matrice A ******\n");
   
    printf("nombre des lignes A (max.40) :");
    scanf("%d", &N);
    printf("nombre des colonnes A (max.40) :");
    scanf("%d", &M);
    for(I =0; I<N; I++)
        for(J=0; J<M; J++)
            {
            printf("Element [%d][%d] :",I,J);
            scanf("%d", &A[I][J]);
            }
    
    printf("****** matrice B ******\n");
    printf(" Le nombre des lignes  B :%d\n", M);
    printf(" nombre des colonnes de la Matrice B (max.40) :");
    scanf("%d", &P);
    for(I =0; I<M; I++)
        for(J=0; J<P; J++)
            {
            printf("Element [%d][%d] :",I,J);
            scanf("%d", &B[I][J]);
            }
    printf(" La Matrice actuelle donne A:\n");
    for(I=0; I<N; I++)
        {
        for(J=0; J<M; J++)
            printf("%7d", A[I][J]);
        printf("\n");
        }
    printf(" La Matrice actuelle donne B:\n");
    for(I=0; I<M; I++)
        {
        for(J=0; J<P; J++)
            printf("%7d",B[I][J]);
        printf("\n");
        }
    for(I=0; I<N; I++)
        for(J=0; J<P; J++)
            {
            C[I][J] += A[I][K]*B[K][J];
            }
    printf("La Matrice Finale  Matrice C:\n");
    for(I=0; I<N; I++)
        {
        for(J=0; J<P; J++)
            printf("%7d",C[I][J]);
        printf("\n");
        }
    return 0;
}
