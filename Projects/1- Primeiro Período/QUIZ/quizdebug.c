#include <stdio.h>
#include <unistd.h>

// Variaveis globais
int acertos = 0, erros = 0;

// Limitar a escolha do usuario entre 1 e 3
int limitar_1a3() {
    int choice;
    while (1) {
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3) {
            return choice;
        } else {
            printf("Opcao invalida, tente novamente: ");
        }
    }
}

void iniciar_quiz() {
    system("cls");
    int res1, res2, res3, res4, res5;

        printf("1) Qual eh a funcao do comando char?\n");
            printf("1. Cria um caracter aleatoriamente\n");
            printf("2. Pode armazenar um unico caractere do alfabeto\n");
            printf("3. Armazena uma unidade de qualquer um dos 256 caracteres comuns\n");
    
            res1 = limitar_1a3();
            if(res1 == 3) {
                acertos ++;
            } else {
                    erros ++;
                }
        system("cls");
        printf("2) Como se insere um comentario em um programa escrito em C?\n");
            printf("1. Utilizando uma barra para tras \\\n");
            printf("2. Utilizando duas barras para frente //\n");
            printf("3. Utilizando uma barra para frente /\n");
    
            res2 = limitar_1a3();
            if(res2 == 2) {
                acertos ++;
            } else {
                    erros ++;
                }
        system("cls");
        printf("3) Qual eh a funcao do comando float?\n");
            printf("1. Armazena um numero inteiro\n");
            printf("2. Armazena um numero decimal\n");
            printf("3. Armazena um numero negativo\n");
    
            res3 = limitar_1a3();
            if(res3 == 2) {
                acertos ++;
            } else {
                    erros ++;
                }

        system("cls");
        printf("4) Como se usa a função scanf() para obter uma informacao do usuário?\n");
            printf("1. scanf(&variavel);\n");
            printf("2. scanf(variavel);\n");
            printf("3. scanf(&&variavel);\n");
    
            res4 = limitar_1a3();
            if(res4 == 1) {
                acertos ++;
            } else {
                    erros ++;
                }
        system("cls");
        printf("5) O que eh uma funcao em C?\n");
            printf("1. Uma funcao eh um bloco de codigo que executa uma tarefa especifica\n");
            printf("2. Uma funcao eh um bloco de codigo que executa uma tarefa geral\n");
            printf("3. Uma funcao eh um bloco de codigo que executa uma tarefa aleatoria\n");
    
            res5 = limitar_1a3();
            if(res5 == 1) {
                acertos ++;
            } else {
                    erros ++;
                }
}

void mostrar_resultados() {
    system("cls");
    if(acertos == 0 && erros == 0) { 
        printf("Voce ainda nao fez o quiz!\n");
        printf("\n");
        sleep(1.7);
        system("cls");
    } else {
        printf("Voce acertou: %d questoes\n", acertos);
        printf("Voce errou: %d questoes\n", erros);
        printf("\n");
        printf("A resposta correta da questao 1 eh a alternativa 3\n");
        printf("A resposta correta da questao 2 eh a alternativa 2\n");
        printf("A resposta correta da questao 3 eh a alternativa 2\n");
        printf("A resposta correta da questao 4 eh a alternativa 1\n");
        printf("A resposta correta da questao 5 eh a alternativa 1\n");
        printf("\n");
        printf("Obrigado por jogar!\n");
    }
}

void limpar_respostas() {
    system("cls");
    acertos = 0;
    erros = 0;
    printf("Respostas limpas!\n");
    printf("\n");
    sleep(1.7);
    system("cls");
}

int main() {
    system("cls");
    int menu_principal;

    while(1) {
        // Menu principal
        printf("Digite o numero correspondente a sua escolha:\n");
        printf("1. Iniciar o quiz\n");
        printf("2. Mostrar o resultado\n");
        printf("3. Limpar respostas\n");
        printf("4. Sair\n");
            printf("\n");
        printf("Escolha uma das opcoes: ");
        scanf("%d", &menu_principal);

        // Switch case para o menu principal
        switch(menu_principal) {
            case 1:
                iniciar_quiz();
                break;
            case 2:
                mostrar_resultados();
                break;
            case 3:
                limpar_respostas();
                break;
            case 4:
            system("cls");
                sleep(2);
                printf("Saindo...\n");
                exit(0);
            default:
            system("cls");
                printf("Opcao invalida, tente novamente!\n");
                break;
        }
    }
}