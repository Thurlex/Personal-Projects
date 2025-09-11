#include <stdio.h>
int main() {
    
    int n1, n2, resto;

    printf("Digite dois numeros: ");
    scanf("%d %d", &n1, &n2);

    resto = n1 / n2;

    printf("O resto da divisao eh: %d", resto);
    
    return 0;
}