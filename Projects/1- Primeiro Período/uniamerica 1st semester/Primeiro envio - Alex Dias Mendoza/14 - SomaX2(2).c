#include <stdio.h>
int main() {

    int n1, n2, soma, somax2;

    printf("Digite dois numeros: ");
    scanf("%d %d", &n1, &n2);

    soma = n1 + n2;

    printf("O resultado da soma eh: %d\n", soma);

    somax2 = soma * 2;

    printf("O resultado da soma multiplicado por 2 eh: %d\n", somax2);
    return 0;
}