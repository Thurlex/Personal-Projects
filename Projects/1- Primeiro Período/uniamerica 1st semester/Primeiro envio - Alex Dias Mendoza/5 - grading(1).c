#include <stdio.h>
int main() {
    
    int grade1, grade2, grade3;

    printf("Digite a primeira nota: ");
    scanf("%d", &grade1);

    printf("Digite a segunda nota: ");
    scanf("%d", &grade2);

    printf("Digite a terceira nota: ");
    scanf("%d", &grade3);

    float average = (grade1 + grade2 + grade3) / 3.0;

    printf("Sua media eh: %.2f\n", average);
}