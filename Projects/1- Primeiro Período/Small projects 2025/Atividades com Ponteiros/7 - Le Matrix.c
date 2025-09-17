#include <stdio.h>

// 7. Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
// Imprima o endereço de cada posição dessa matriz.

int main() {
    // Definindo a matriz 3x3
    int matriz[3][3] = {
        {3, 1, 56},
        {6, 21, 8},
        {4, 10, 32}
    };

    // Imprimindo o endereço de cada posição da matriz
    printf("Os valores em coluna sao: \n");
    printf("%d, %d, %d\n", matriz[0][0], matriz[0][1], matriz[2][2]);
    printf("%d, %d, %d\n", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf("%d, %d, %d\n", matriz[2][0], matriz[2][1], matriz[2][2]);

    return 0;
}