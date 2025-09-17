#include <stdio.h>
#include <stdlib.h> // Para alocação dinâmica, se preferir em vez de VLA

// Define a estrutura Aluno
struct Aluno {
    int matricula;
    float nota;
};

int main() {
    int quantidadeAlunos;
    int opcao;

    // Solicita a quantidade de alunos e garante que seja maior que zero
    do {
        printf("Digite a quantidade de alunos na turma: ");
        scanf("%d", &quantidadeAlunos);
        if (quantidadeAlunos <= 0) {
            printf("A quantidade de alunos deve ser maior que zero. Tente novamente.\n");
        }
    } while (quantidadeAlunos <= 0);

    // Cria um vetor do tipo Aluno com o tamanho correspondente
    // Usando VLA (Variable Length Array), que é um recurso do C99 em diante.
    // Se precisar de compatibilidade com C mais antigo, use alocação dinâmica com malloc.
    struct Aluno turma[quantidadeAlunos];

    // Preenche o vetor com a matrícula e a nota de cada aluno
    printf("\n--- Cadastro de Alunos ---\n");
    for (int i = 0; i < quantidadeAlunos; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("  Matricula: ");
        scanf("%d", &turma[i].matricula);
        printf("  Nota final: ");
        scanf("%f", &turma[i].nota);
    }

    // Menu de opções
    do {
        printf("\n--- Menu de Opcoes ---\n");
        printf("1 - Exibir matriculas e notas\n");
        printf("2 - Exibir a matricula e a nota dos alunos aprovados (nota > 7)\n");
        printf("3 - Contar os alunos aprovados (alunos com nota maior que 7)\n");
        printf("4 - Contar os alunos reprovados\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\n--- Matriculas e Notas de Todos os Alunos ---\n");
                if (quantidadeAlunos == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                } else {
                    for (int i = 0; i < quantidadeAlunos; i++) {
                        printf("Aluno %d: Matricula: %d, Nota: %.2f\n", i + 1, turma[i].matricula, turma[i].nota);
                    }
                }
                break;
            case 2:
                printf("\n--- Alunos Aprovados (Nota > 7) ---\n");
                int algumAprovado = 0;
                for (int i = 0; i < quantidadeAlunos; i++) {
                    if (turma[i].nota > 7) {
                        printf("Matricula: %d, Nota: %.2f\n", turma[i].matricula, turma[i].nota);
                        algumAprovado = 1;
                    }
                }
                if (!algumAprovado && quantidadeAlunos > 0) {
                    printf("Nenhum aluno aprovado.\n");
                } else if (quantidadeAlunos == 0) {
                    printf("Nenhum aluno cadastrado.\n");
                }
                break;
            case 3: { // Usamos chaves aqui para criar um escopo para a variável contadorAprovados
                int contadorAprovados = 0;
                for (int i = 0; i < quantidadeAlunos; i++) {
                    if (turma[i].nota > 7) {
                        contadorAprovados++;
                    }
                }
                printf("\nTotal de alunos aprovados: %d\n", contadorAprovados);
                break;
            }
            case 4: { // Usamos chaves aqui para criar um escopo para a variável contadorReprovados
                int contadorReprovados = 0;
                for (int i = 0; i < quantidadeAlunos; i++) {
                    if (turma[i].nota <= 7) { // Inclui notas iguais a 7 como reprovado, ajuste se necessário
                        contadorReprovados++;
                    }
                }
                printf("\nTotal de alunos reprovados: %d\n", contadorReprovados);
                break;
            }
            case 5:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}