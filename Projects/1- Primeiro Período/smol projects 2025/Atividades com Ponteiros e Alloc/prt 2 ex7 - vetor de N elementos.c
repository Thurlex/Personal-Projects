// Faça  uma  função que retorne o ponteiro para um vetor de N elementos inteiros alocados
// dinamicamente. O vetor deve ser preenchido com valores de 0 a N − 1.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VETOR 100 // Define o tamanho máximo do vetor

int* criarVetor(int n) {
    int* vetor = (int*)malloc(n * sizeof(int));
    if (vetor == NULL) {
        return NULL; // Retorna NULL se alocação falhar
    }
    for (int i = 0; i < n; i++) {
        vetor[i] = i; // Preenche com valores de 0 a N-1
    }
    return vetor;
}

int main() {
    int n = 0;
    printf("Digite o tamanho do vetor (N): ");
    scanf("%d", &n);

    while (n < 0 || n > MAX_VETOR) {
        printf("Valor inválido. Digite um valor não negativo e menor que %d: ", MAX_VETOR);
        scanf("%d", &n);
    }

    int* vetor = criarVetor(n);
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Os elementos do vetor são:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);
    return 0;
}