#include <stdio.h>
int main() {

    int i;
    
    printf("Digite um numero: ");
    scanf("%d", &i);

    for (int j = 0; i >= 0; i--) {
        printf("%d\n", i);
    }
    return 0;
}