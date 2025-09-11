// Elabore um programa que leia do usuário o tamanho de um vetor a ser lido. Em seguida,
// faça a alocação dinâmica (malloc e calloc) desse vetor. Por fim, leia o vetor do usuário e o imprima.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VETOR 100 // Define o tamanho máximo do vetor

int main() {
    system("chcp 65001 > nul"); 
    int n, i;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Alocação dinâmica do vetor
    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        free(vetor); // Libera a memória alocada antes de sair
        return 1;

    } else if (n <= 0 || n > MAX_VETOR) {
        printf("Tamanho inválido. O tamanho deve ser maior que 0 e menor ou igual a %d.\n", MAX_VETOR);
        free(vetor); // Libera a memória alocada antes de sair
        return 1;
    }

    vetor = (int *)malloc(n * sizeof(int)); // Alocação de memória para o vetor, feita apos a verifica

    // Leitura do vetor
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Impressão do vetor
    printf("Os elementos do vetor são:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Liberação da memória alocada
    free(vetor);

    return 0;
}