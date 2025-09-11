#include <stdio.h>
int main() {
    
    float weight, height, bmi;

    printf("Digite seu peso (kg): ");
    scanf("%f", &weight);

    printf("Digite sua altura (m): ");
    scanf("%f", &height);

    bmi = weight / (height * height);

    if (bmi < 18.5) {
        printf("Seu indice de massa corporal eh %.2f, voce esta abaixo do peso saudavel\n", bmi);
    }
    else if (bmi >= 18.5 && bmi < 24.9) {
        printf("Seu indice de massa corporal eh %.2f, voce esta saudavel\n", bmi);
    }
    else if (bmi >= 25 && bmi < 29.9) {
        printf("Seu indice de massa corporal eh %.2f, voce esta em sobrepeso\n", bmi);
    }
    else {
        printf("Seu indice de massa corporal eh %.2f, voce eh obeso\n", bmi);
    }
}