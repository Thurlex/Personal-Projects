// Crie uma estrutura chamada Cadastro. Essa estrutura deve conter o nome, a idade
// e o endereço de uma pessoa. Aloque dinamicamente (alloc/calloc) a memória e receber vários cadastros.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_CADASTROS 100 // Define o número máximo de cadastros que podem ser feitos
#define MAX_ENDERECO 100 // Define o tamanho máximo do endereço
#define MAX_NOME 50 // Define o tamanho máximo do nome

// Variáveis globais
int numero_de_cadastros = 0; // Variável para o número de cadastros

typedef struct {
    char nome[MAX_NOME];
    int idade;
    char endereco[MAX_ENDERECO];
} Cadastro;

Cadastro *cadastro[MAX_CADASTROS]; // Ponteiro para a estrutura Cadastro

void mostrar_cadastros() {
    int i = 0; // Variável de controle do loop
    system("cls"); // Limpa a tela
    
    if (numero_de_cadastros <= 0) { // Verifica se não há cadastros
        printf("Nenhum cadastro encontrado.\n");
        return; // Retorna ao menu principal
    }

    printf("\n=== Cadastros ===\n");
    for (int i = 0; i < numero_de_cadastros; i++) {
        printf("Cadastro %d:\n", i + 1);
        printf("Nome: %s\n", cadastro[i]->nome); // Acessa o nome do cadastro
        printf("Idade: %d\n", cadastro[i]->idade); // Acessa a idade do cadastro
        printf("Endereço: %s\n", cadastro[i]->endereco); // Acessa o endereço do cadastro
        printf("-------------------------\n");
    }

    printf("Pressione ENTER para continuar...\n");
    getchar(); // Limpa o buffer de entrada
    getchar(); // Espera o usuário pressionar ENTER

    return; // Retorna ao menu principal
}

void novo_cadastro() {
    Cadastro *novo = (Cadastro *)malloc(sizeof(Cadastro));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    printf("Digite o nome: ");
    getchar();
    fgets(novo->nome, sizeof(novo->nome), stdin);
    printf("\nDigite a idade: ");
    scanf("%d", &novo->idade);
    printf("\nDigite o endereço: ");
    getchar();
    fgets(novo->endereco, sizeof(novo->endereco), stdin);

    // Salva o ponteiro no array global
    cadastro[numero_de_cadastros] = novo;
    numero_de_cadastros++;

    printf("\nCadastro realizado com sucesso!\n");
    printf("Pressione ENTER para continuar...\n");
    getchar();
}

int main() {
    int menu = 0; // Variáveis para o loop e número de cadastros

    do {
        system("cls"); // Limpa a tela
        printf("Digite \n1 para novo cadastro\n2 para mostrar cadastros\n0 para sair: \n");
        scanf("%d", &menu); // Lê a opção do usuário

        switch (menu)
        {
        case 1:
            novo_cadastro(); // Chama a função para novo cadastro
            break;

        case 2:
            mostrar_cadastros(); // Chama a função para mostrar cadastros
            break;
        
        default:
            break;
        }
    } while (menu != 0); // Continua o loop até que o usuário digite 0
}