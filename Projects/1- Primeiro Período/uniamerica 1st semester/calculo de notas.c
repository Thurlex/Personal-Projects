#include <stdio.h>
#include <stdlib.h>

#define ALUNOS 4
#define NOTAS 5
#define MEDIA_APROVACAO 7.0

// Função para calcular e retornar a média de um aluno
float calcular_media(float notas[ALUNOS][NOTAS], int aluno) {
    float soma = 0;
    for (int j = 0; j < NOTAS; j++) {
        soma += notas[aluno][j];
    }
    return soma / NOTAS;
}

int main() {
    float notas[ALUNOS][NOTAS];  // Matriz para armazenar as notas
    int i, j;

    // Preenchendo a matriz com as notas dos alunos
    for (i = 0; i < ALUNOS; i++) {
        printf("Digite as 5 notas do aluno %d:\n", i + 1);
        for (j = 0; j < NOTAS; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    // Exibindo as notas armazenadas
    printf("\nNotas dos alunos:\n");
    for (i = 0; i < ALUNOS; i++) {
        printf("Aluno %d: ", i + 1);  // Fix: Use i + 1 instead of i++
        for (j = 0; j < NOTAS; j++) {
            printf("%.2f ", notas[i][j]);
        }
        printf("\n");
    }

    // Calculando e exibindo a média de cada aluno
    printf("\nMédias dos alunos:\n");
    for (i = 0; i < ALUNOS; i++) {
        float media = calcular_media(notas, i);
        printf("Aluno %d: Média = %.2f", i + 1, media);  // Fix: Use i + 1 instead of i++
        
        // Verificando se o aluno foi aprovado ou reprovado
        if (media >= MEDIA_APROVACAO) {
            printf(" (Aprovado)\n");
        } else {
            printf(" (Reprovado)\n");
        }
    }
    printf("\nPressione Enter para sair...\n");
    getchar();
    getchar();

    return 0;
}