// Escreva  uma  função  que  receba  um  valor  inteiro  positivo  N  por  parâmetro  e  retorne  o 
// ponteiro para um vetor de tamanho N alocado dinamicamente.
// Se N for negativo ou igual a zero, um ponteiro nulo deverá ser retornado.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VETOR 100 // Define o tamanho máximo do vetor

int* criarVetor(int n) {
    if (n <= 0) {
        return NULL; // Retorna NULL para N inválido
    }
    int* vetor = (int*)malloc(n * sizeof(int));
    return vetor; // Retorna ponteiro para vetor alocado
}

int main() {
    system("chcp 65001 > nul");

    int n = 0;
    int *vetor;

    system("cls");
    printf("Digite o tamanho do vetor (N): ");
    scanf("%d", &n);
    while (n <= 0 || n > MAX_VETOR) { // Verifica se N é positivo
        printf("Valor inválido. Digite um valor positivo e menor que %d: ", MAX_VETOR);
        scanf("%d", &n);
    }

    vetor = criarVetor(n); // Chamada da função

    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Leitura do vetor
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Exibição do vetor
    printf("\nVetor lido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Liberação da memória
    free(vetor);
    return 0;
}