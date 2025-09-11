#include <stdio.h>
int main() {

    int a, b, x, y;

    printf("Digite o valor de A: ");
    scanf("%d", &a);

    printf("Digite o valor de B: ");
    scanf("%d", &b);

    printf("Digite o valor de X: ");
    scanf("%d", &x);
    
    y = a * x + b;

    printf("O resultado de A * X + B eh: %d", y);
    return 0;
}