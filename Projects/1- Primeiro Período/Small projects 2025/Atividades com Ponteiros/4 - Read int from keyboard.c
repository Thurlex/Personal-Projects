#include <stdio.h>

// Faça um programa que leia 2 valores inteiros e chame uma função que
// receba estas 2 variáveis e troque o seu conteúdo, ou seja,
// esta função é chamada passando duas variáveis A e B como ponteiros.

int vB;
int vA;
int *ptr_A = &vA;
int *ptr_B = &vB;

int main() {

    printf("Digite o valor de vA: ");
    scanf("%d", &vA);
    printf("\nDigite o valor de vB: ");
    scanf("%d", &vB);

    int *ptr_A = &vA;
    int *ptr_B = &vB;

    if (ptr_A > ptr_B) {
        printf("O maior valor de endereco eh vA (%p): %d\n", vA, *ptr_A);
    } else if (ptr_A < ptr_B) {
        printf("O maior valor de endereco eh vB: %d\n", *ptr_B);
    } else {
        printf("Os valores sao iguais: %d\n", &vA);
    }

    return 0;
}