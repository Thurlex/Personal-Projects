#include <stdio.h>

// 8. Crie um programa que contenha um vetor de inteiros contendo 5 elementos. Utilizando
// apenas aritmética de ponteiros, leia esse vetor do teclado e imprima o dobro de cada 
// valor lido.

int main() {
    int vetor[5];
    int *ptr = vetor; // Ponteiro para o início do vetor
    int i = 0;

    // Leitura dos valores do vetor
    printf("Digite 5 numeros inteiros:\n");
    for (i = 0; i < 5; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", ptr + i);
    }

    // Impressão do dobro de cada valor lido
    printf("O dobro dos numeros digitados sao:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i) * 2);
    }

    return 0;
}