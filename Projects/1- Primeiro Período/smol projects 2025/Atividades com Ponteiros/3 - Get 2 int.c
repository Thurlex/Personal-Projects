#include <stdio.h>

// 3. Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis do teclado. 

void troca(int *ptr_A, int *ptr_B) {
    *ptr_A = *ptr_B;
    *ptr_B = *ptr_B * 2;

    printf("O valor de vA eh: %d", *ptr_A);
    printf("\nO valor de vB eh: %d", *ptr_B);
}

int main() {
    int vA;
    int vB;

    printf("Digite o valor de vA: ");
    scanf("%d", &vA);
    printf("\nDigite o valor de vB: ");
    scanf("%d", &vB);
    
    troca(&vA, &vB);
}