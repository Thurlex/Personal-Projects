#include <stdio.h>
int main() {
    
    int age;

    printf("Digite sua idade: ");
    scanf("%d", &age);

    if (age >= 18) {
        printf("Voce eh um adulto\n");
    } else {
        printf("Voce eh de menor\n");
    }
    return 0;
}