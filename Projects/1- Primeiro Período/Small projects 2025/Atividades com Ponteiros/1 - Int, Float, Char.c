#include <stdio.h>

// Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. 

int main() {
    int a = 5;
    float b = 3.14;
    char c = 'A';

    int *ptr_a = &a;
    float *ptr_b = &b;
    char *ptr_c = &c;

    printf("Valor de a: %d\n", *ptr_a);
    printf("Valor de b: %.2f\n", *ptr_b);
    printf("Valor de c: %c\n", *ptr_c);

    a = *ptr_a + b;
    b = *ptr_b * 4.0;
    c = 'B';

    printf("\nNovo valor de a: %d\n", *ptr_a);
    printf("Novo valor de b: %.2f\n", *ptr_b);
    printf("Novo valor de c: %c\n", *ptr_c);

    return 0;
}