// Crie uma estrutura representando um aluno de uma disciplina. Essa estrutura deve conter o
// número de matrícula do aluno, seu nome e as notas de três provas


#include <stdlib.h>
#include <stdio.h>

int main() {
    int i = 0;

    typedef struct Aluno {
        int matricula;
        char nome[50];
        float notas[3];
    } Aluno;

    Aluno aluno;

    Aluno *ptrAluno = &aluno; // Ponteiro para a estrutura Aluno

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &ptrAluno->matricula);
    printf("\nDigite o nome do aluno: ");
    scanf("%d", ptrAluno->nome);

    do {
        printf("\nDigite a nota da prova %d: ", i + 1);
        scanf("%f", &ptrAluno->notas[i]);
        i++;
    } while (i < 3);
    
    system("cls");
    printf("\nMatrícula: %d", ptrAluno->matricula);
    printf("\nNome: %s", ptrAluno->nome);
    printf("\nNotas: %.2f, %.2f, %.2f", ptrAluno->notas[0], ptrAluno->notas[1], ptrAluno->notas[2]);
}