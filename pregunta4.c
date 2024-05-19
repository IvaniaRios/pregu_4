#include <stdio.h>
#include <omp.h>

void multiMatPorVEctor(int N, int matriz[N][N], int vector[N], int resultado[N]) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        resultado[i] = 0;
        for (int j = 0; j < N; j++) {
            resultado[i] += matriz[i][j] * vector[j];
        }
    }
}

int main() {
    int N;

    printf("Ingrese el tamanio de N: ");
    scanf("%d", &N);

    int matriz[N][N];
    int vector[N];
    int resultado[N];

    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("mat[%d][%d]= ",i,j);
            scanf("%d", &matriz[i][j]);
        }
    }
    printf("Ingrese los elementos del vector:\n");
    for (int i = 0; i < N; i++) {
        printf("vect[%d]= ",i);
        scanf("%d", &vector[i]);
    }
    
    multiMatPorVEctor(N, matriz, vector, resultado);
     printf("MAtriz ingresada\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ",matriz[i][j]);
        }
        puts("");
    }
        printf("Vector ingresado\n");
    for (int i = 0; i < N; i++) {
        printf("%d ",vector[i]);
    }
    printf("\nResultado de la multiplicacion:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");
    return 0;
}
