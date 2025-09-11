#include <stdio.h>
#include <math.h>
int main() {

    float dias, ano, rdias;

    printf("Digite a quantidade de dias: ");
    scanf("%f", &dias);

    ano = dias / 365;
    rdias = fmod(dias, 365.0);

    printf("A quantidade de anos eh: %.0f anos e %.0f dias.", ano, rdias);
    return 0;
}