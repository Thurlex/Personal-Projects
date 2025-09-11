#include <stdio.h>
int main() {

    float n;

    printf("Digite um numero: ");
    scanf("%f", &n);

    n = n / 3;

    printf("O resultado da divisao por 3 eh: %.2f", n);
    return 0;
}