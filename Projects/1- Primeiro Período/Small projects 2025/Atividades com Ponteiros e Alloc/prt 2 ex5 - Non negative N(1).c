// Faça um programa que leia um valor inteiro N não negativo. Se o valor de N for inválido, o 
// usuário deverá digitar outro até que ele seja válido (ou seja, positivo).  
// Em  seguida,  leia  um  vetor  V  contendo  N  posições  de  inteiros,  em que cada valor deverá ser 
// maior ou igual a 2. Esse vetor deverá ser alocado dinamicamente. 

#include <stdio.h>
#include <stdlib.h>

#define MAX_VETOR 100 // Define o tamanho máximo do vetor

int main() {
    system("chcp 65001 > nul");

    int n = 0, i = 0;
    int *vetor;
    int valido = 0; // Variável para verificar se o valor de N é válido
    
    system("cls"); // Limpa a tela

    printf("Digite o tamanho do vetor (N): ");
    scanf("%d", &n);

    while (n < 0 || n > 100) { // Verifica se N é não negativo
        printf("Valor inválido. Digite um valor não negativo e menor que 100: ");
        scanf("%d", &n);
    }
    
    vetor = (int *)malloc(n * sizeof(int)); // Alocação de memória para o vetor

    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Leitura do vetor
    printf("Digite os elementos do vetor (maior ou igual a 2):\n");
    for (i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
        while (vetor[i] < 2) { // Verifica se o valor é maior ou igual a 2
            printf("Valor inválido. Digite um valor maior ou igual a 2: ");
            scanf("%d", &vetor[i]);
        }
    }

    printf("Os elementos do vetor são:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
}