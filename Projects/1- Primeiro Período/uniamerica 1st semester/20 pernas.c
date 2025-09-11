#include <stdio.h>
#include <windows.h>

void calculo_pernas();
int bipedes, quadrupedes, hexapodes, octopodes;
int total_pernas = 0; // Variável global para armazenar o total de pernas

void calculo_pernas() {
    // Vetores para armazenar os dados
    int quantidade_animais[4]; // Quantidade de cada tipo de animal
    int pernas_por_animal[4] = {2, 4, 6, 8}; // Número de pernas por tipo de animal
    const char* tipos_animais[4] = {"bípedes", "quadrúpedes", "hexápodes", "octópodes"}; // Tipos de animais
    int total_pernas = 0;
    int total_pernas_por_tipo[4] = {0}; // Vetor para armazenar o total de pernas por tipo de animal

    printf("=== Cálculo de Pernas ===\n");

    // Solicita ao usuário a quantidade de cada tipo de animal
    for (int i = 0; i < 4; i++) {
        printf("Digite a quantidade de animais %s: ", tipos_animais[i]);
        scanf("%d", &quantidade_animais[i]);
    }

    // Calcula o total de pernas por tipo e o total geral
    for (int i = 0; i < 4; i++) {
        total_pernas_por_tipo[i] = quantidade_animais[i] * pernas_por_animal[i];
        total_pernas += total_pernas_por_tipo[i];
    }

    // Exibe o total de pernas por tipo
    printf("\n=== Resultado ===\n");
    for (int i = 0; i < 4; i++) {
        printf("Total de pernas de %s: %d\n", tipos_animais[i], total_pernas_por_tipo[i]);
    }

    // Exibe o total geral de pernas
    printf("O total geral de pernas é: %d\n", total_pernas);
    printf("Pressione Enter para retornar ao menu principal...\n");
    getchar(); // Limpa o buffer de entrada
    getchar(); // Aguarda o usuário pressionar Enter
}

int main() {
    char input[10]; // Buffer para entrada do usuário
    int menu_principal;
    int valid = 0; // Flag para verificar se a entrada é válida

    system("chcp 65001 > nul"); // Configura o console para UTF-8
    do{
        valid = 0;
        system("cls"); // Limpa a tela antes de exibir o menu
        // Menu principal
        printf("=== Menu Principal ===\n");
        printf("1. Calcular total de pernas\n");
        printf("2. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%s", input); // Lê a entrada como string
        sscanf(input, "%d", &menu_principal); // Converte a entrada para inteiro
        if (menu_principal < 1 || menu_principal > 2) {
            printf("Opção inválida! Digite um número entre 1 e 2.\n");
            Sleep(1500);
        } else {
            valid = 1; // Entrada válida
        }

        if (valid) {
            switch (menu_principal) {
                case 1:
                    system("cls"); // Limpa a tela antes de chamar a função
                    calculo_pernas(); // Chama a função para calcular pernas
                    break;
                case 2:
                    printf("Saindo...\n");
                    Sleep(1500);
                    return 0; // Encerra o programa
                default:
                    printf("Opção inválida!\n");
                    break;
            }
        }
    } while (1); // Loop infinito para manter o menu principal ativo
}