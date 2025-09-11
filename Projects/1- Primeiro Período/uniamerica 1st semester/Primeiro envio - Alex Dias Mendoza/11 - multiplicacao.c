#include <stdio.h>
int main() {

    int n1, n2, total;

    printf("Digite dois numeros: ");
    scanf("%d %d", &n1, &n2);

    total = n1 * n2;

    printf("O resulatdo da multiplicacao eh: %d", total);
    
    return 0;
}