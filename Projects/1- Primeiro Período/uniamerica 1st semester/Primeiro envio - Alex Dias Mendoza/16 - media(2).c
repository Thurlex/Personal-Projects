#include <stdio.h>
int main() {
    
    int n1, n2, n3;

    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);

    printf("Digite o segundo numero: ");
    scanf("%d", &n2);

    printf("Digite o terceiro numero: ");
    scanf("%d", &n3);

    float average = (n1 + n2 + n3) / 3.0;

    printf("Sua media eh: %.2f\n", average);
}