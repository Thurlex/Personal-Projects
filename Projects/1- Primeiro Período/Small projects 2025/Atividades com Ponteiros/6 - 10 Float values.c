#include <stdio.h>

// 6. Crie um programa que contenha um vetor de float contendo 10 elementos. Imprima o
// endereço de cada posição desse vetor. 

int main() {
    float real[10] = {2.31, 4.213, 3.120, 4.249, 5.129, 6.746, 7.327, 8.162, 9.307, 10.639};
    int i;
    float *ptr_real = real;

    // Imprimindo o endereço de cada posição do vetor
    printf("O valor de cada numero em float real eh: ");
        do {
            printf("\n%f, ", *ptr_real);
            ptr_real++;
            i++;
        } while (i < 11);

    return 0;
}