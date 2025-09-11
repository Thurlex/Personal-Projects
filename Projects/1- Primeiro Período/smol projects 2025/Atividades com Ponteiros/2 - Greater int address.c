#include <stdio.h>

// 2. Escreva um programa que contenha duas variáveis inteiras. Compare seus endereços e exiba o maior endereço.

int main() {
    int vA = 5;
    int vB = 10;

    printf("Endereço de vA: %p\n", (void*)&vA); // Usando %p para imprimir endereços de memória
    printf("Endereço de vB: %p\n", (void*)&vB); // Usando %p para imprimir endereços de memória

    if (&vA > &vB) {
        printf("O endereço de vA (%p) é maior que o endereço de vB (%p)\n", &vA, &vB);
    } else if (&vA < &vB) {
        printf("O endereço de vA (%p) é menor que o endereço de vB (%p)\n", &vA, &vB);
    } else {
        printf("Os endereços de vA e vB são iguais\n");
    }

    return 0;
}