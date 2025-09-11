// Escreva um programa que aloque dinamicamente uma matriz de inteiros. As dimensões da 
// matriz deverão ser lidas do usuário.  
// Em  seguida,  escreva  uma  função  que  receba  um  valor  e  retorne  1,  caso  o  valor  esteja  na 
// matriz, ou retorne 0, no  caso contrário. 

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINHAS 100
#define MAX_COLUNAS 100

// Função para buscar valor na matriz
int buscar_valor(int **matriz, int linhas, int colunas, int valor) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == valor) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int linhas, colunas, valor, encontrado;
    int **matriz;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    while (linhas <= 0 || linhas > MAX_LINHAS) {
        printf("Número inválido. Digite um número de linhas entre 1 e %d: ", MAX_LINHAS);
        scanf("%d", &linhas);
    }

    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);
    while (colunas <= 0 || colunas > MAX_COLUNAS) {
        printf("Número inválido. Digite um número de colunas entre 1 e %d: ", MAX_COLUNAS);
        scanf("%d", &colunas);
    }

    // Alocação dinâmica da matriz
    matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória.\n");
            // Libera as linhas já alocadas
            for (int k = 0; k < i; k++) free(matriz[k]);
            free(matriz);
            return 1;
        }
    }

    // Leitura dos elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Digite o valor a ser buscado na matriz: ");
    scanf("%d", &valor);

    encontrado = buscar_valor(matriz, linhas, colunas, valor);

    if (encontrado)
        printf("Valor %d encontrado na matriz.\n", valor);
    else
        printf("Valor %d não encontrado na matriz.\n", valor);

    // Liberação da memória alocada
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}