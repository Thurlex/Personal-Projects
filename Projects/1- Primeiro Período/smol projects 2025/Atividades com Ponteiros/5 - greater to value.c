#include <stdio.h>

// 5. Faça um programa que leia dois valores inteiros e chame uma função que receba estes 
// 2 valores de entrada e retorne o maior valor na primeira variável e o menor valor na 
// segunda variável. Escreva o conteúdo das 2 variáveis na tela. Use ponteiros na solução.

void valor_maior_menor(int *ptr_A, int *ptr_B) {
int grd_A = *ptr_A; // Ponteiro para guardar o primeiro valor de A
int grd_B = *ptr_B; // Ponteiro para guardar o primeiro valor de B

    if (*ptr_A > *ptr_B) {
        printf("\n\nO valor de vA eh: %d", *ptr_A);
        printf("\nO valor de vB eh: %d", *ptr_B);
    } else if (*ptr_A < *ptr_B) {
        *ptr_A = grd_B;
        *ptr_B = grd_A;

        printf("\n\nO valor de vA eh: %d", *ptr_A);
        printf("\nO valor de vB eh: %d", *ptr_B);
    }

}

int main() {
    int vA = 0;
    int vB = 0;
    
    printf("Digite o valor de vA: ");
    scanf("%d", &vA);
    printf("\nDigite o valor de vB: ");
    scanf("%d", &vB);

    valor_maior_menor(&vA, &vB); // Passando os endereços de vA e vB para a função, ambos devem estar na mesma posição que ptr_A e ptr_B respectivamente.
}