#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// Programa para um pequeno quiz de perguntas e respostas.
// Feito por Alessandra Rodrigues da Silva; 
// Alex Dias Mendoza;
// Christopher Adam;
// Pedro Henrique Fernandes Kleinhans;
// Victor Luiz Ribeiro de Miranda.

int acertos = 0, erros = 0; // Contadores de acertos e erros, necessários para
// contar a pontuação do usuário pelo quiz e para mostrar os resultados

int res1, res2, res3, res4, res5;

// Isso são chamados de protótipo de função, eles são necessários para que o compilador
// saiba que a função existe antes de ser chamada. Isso é necessário porque o C é uma
// linguagem de programação de compilação única, o que significa que o código é compilado
// de cima para baixo e, portanto, o compilador precisa saber que a função existe antes
// de ser chamada.
void iniciar_quiz();
void questao_1();
void questao_2();
void questao_3();
void questao_4();
void questao_5();
void mostrar_resultados();


int main() {
    char input[10]; // Buffer para entrada do usuário
    int menu_principal;
    int valid;

    // Configura o terminal para usar caracteres especiais
    setlocale(LC_ALL, "Portuguese_Brazil");
    system("chcp 1252");

    do{
        valid = 0;
        system("cls");

        // Menu principal
        printf("\n\n-------------------------------------------------------------\n");
        printf("\tDigite o número correspondente a sua escolha:\n");
        printf("-------------------------------------------------------------\n");
        printf("\t1. Iniciar o quiz\n");
        printf("\t2. Mostrar o resultado\n");
        printf("\t3. Limpar respostas\n");
        printf("\t4. Sair\n");
        printf("-------------------------------------------------------------\n");
        
        while (!valid) {
            printf("\tEscolha uma das opções: ");
            scanf("%s", input);
            
            if (sscanf(input, "%d", &menu_principal) == 1 && menu_principal >= 1 && menu_principal <= 4) {
                valid = 1;
            } else {
                printf("\n\tOpção inválida! Digite um número entre 1 e 4.\n");
                Sleep(1500);
                system("cls");
                // Reimprime o menu
                printf("\n\n-------------------------------------------------------------\n");
                printf("\tDigite o número correspondente a sua escolha:\n");
                printf("-------------------------------------------------------------\n");
                printf("\t1. Iniciar o quiz\n");
                printf("\t2. Mostrar o resultado\n");
                printf("\t3. Limpar respostas\n");
                printf("\t4. Sair\n");
                printf("-------------------------------------------------------------\n");
            }
        }

        // Switch case para o menu principal
        switch(menu_principal) {
        case 1:
            iniciar_quiz();
            break;
        case 2:
            mostrar_resultados();
            break;
        case 3:
            if(acertos == 0 && erros == 0) {
                system("cls");
                printf("\n\n\t===========================================");
                printf("\n\t|\tVocê ainda não fez o quiz!      |\n");
                printf("\t===========================================");
                Sleep(1500);
                system("cls");

            }else{
                system("cls");
                acertos = 0, erros = 0;
                res1 = 0, res2 = 0, res3 = 0, res4 = 0, res5 = 0;
                printf("\n\n\t============================================");
                printf("\n\t\t\tRespostas Limpas!\n");
                printf("\t============================================");
                Sleep(800);
                system("cls");
            }
        case 4:
            system("cls");
            printf("\n\n==========================================");
            printf("\n\t\tSaindo...\n");
            printf("==========================================\n\n");
            break;
        default:
            printf("\n\n\tOpção inválida, tente novamente!\n");
            Sleep(700);
            break;
        }
    }while(menu_principal != 4);

    return 0;
}

void iniciar_quiz() {

    if(acertos > 0) {

        printf("\t");
        Sleep(2000);
        system("cls");
                printf("\n\n================================================================================");
                printf("\n\tVocê precisa limpar os resultados, para iniciar o quiz novamente!");
                printf("\n\n================================================================================");
                Sleep(1500);
                system("cls");
    
    } else if(erros > 0) {

        printf("\t");
        Sleep(2000);
        system("cls");
                printf("\n\n================================================================================");
                printf("\n\tVocê precisa limpar os resultados, para iniciar o quiz novamente!");
                printf("\n\n================================================================================");
                Sleep(1500);
                system("cls");
    } else {

        system("cls");
        Sleep(200);
        questao_1();
        Sleep(200);
        questao_2();
        Sleep(200);
        questao_3();
        Sleep(200);
        questao_4();
        Sleep(200);
        questao_5();
        system("cls");
        printf("\n\n======================================================================");
        printf("\n\n\t\tParabéns, você completou o Quiz. \n\tVeja seu resultado digitando '2' na tela a seguir");
        printf("\n\n======================================================================");

        Sleep(2000);
    }
}

void questao_1() {
    char input[10]; // Buffer para armazenar a entrada do usuário
    int valid = 0; // Flag para verificar se a entrada é válida

    Sleep(200);
    system("cls");

    printf("\n\n-------------------------------------------------------------------------------------------\n");
    printf("\t1) O comando char() armazena uma unidade de qualquer um dos 256 caracteres.\n");
    printf("\n\t1. Verdadeiro\n");
    printf("\t2. Falso\n");
    printf("-------------------------------------------------------------------------------------------\n");
    
    // Loop para verificar se a entrada é válida
    while (!valid) {
        printf("\tEscolha uma opção: ");
        scanf("%s", input); // Lê a entrada como string

        // Verifica se a entrada é um número inteiro e se está entre 1 e 2
        if (sscanf(input, "%d", &res1) == 1 && res1 >= 1 && res1 <= 2) {
            valid = 1; // Entrada válida
        } else {
            printf("\n\n\tResposta inválida, por favor, me diga se é Verdadeiro ou Falso!\n");
            Sleep(2000);
            system("cls");
            // Reimprime o menu
            printf("\n\n-------------------------------------------------------------------------------------------\n");
            printf("\t1) O comando char() armazena uma unidade de qualquer um dos 256 caracteres.\n");
            printf("\n\t1. Verdadeiro\n");
            printf("\t2. Falso\n");
            printf("-------------------------------------------------------------------------------------------\n");
        }
    }

    if (res1 == 1) {
        acertos++;
    } else {
        erros++;
    }
}

void questao_2() {
    char input[10]; // Buffer para armazenar a entrada do usuário
    int valid = 0; // Flag para verificar se a entrada é válida

    Sleep(200);
    system("cls");

    printf("\n\n-------------------------------------------------------------------------------------------\n");
    printf("\t2) Para inserir um comentário em um programa C é utilizado \\.\n");
    printf("\n\t1. Verdadeiro\n");
    printf("\t2. Falso\n");
    printf("-------------------------------------------------------------------------------------------\n");

    while (!valid) {
        printf("\tEscolha uma opção: ");
        scanf("%s", input); // Lê a entrada como string

        // Verifica se a entrada é um número inteiro e se está entre 1 e 2
        if (sscanf(input, "%d", &res2) == 1 && res2 >= 1 && res2 <= 2) {
            valid = 1; // Entrada válida
        } else {
            printf("\n\n\tResposta inválida, por favor, me diga se é Verdadeiro ou Falso!\n");
            Sleep(2000);
            // Reimprime o menu
            system("cls");
            printf("\n\n-------------------------------------------------------------------------------------------\n");
            printf("\t2) Para inserir um comentário em um programa C é utilizado \\.\n");
            printf("\n\t1. Verdadeiro\n");
            printf("\t2. Falso\n");
            printf("-------------------------------------------------------------------------------------------\n");
        }
    }

    if (res2 == 2) {
        acertos++;
    } else {
        erros++;
    }
}

void questao_3() {
    char input[10]; // Buffer para armazenar a entrada do usuário
    int valid = 0; // Flag para verificar se a entrada é válida

    Sleep(200);
    system("cls");

    printf("\n\n-------------------------------------------------------------------------------------------\n");
    printf("\t3) O comando float é utilizado necessariamente para números inteiros.\n");
    printf("\n\t1. Verdadeiro\n");
    printf("\t2. Falso\n");
    printf("-------------------------------------------------------------------------------------------\n");

    while (!valid) {
        printf("\tEscolha uma opção: ");
        scanf("%s", input); // Lê a entrada como string

        // Verifica se a entrada é um número inteiro e se está entre 1 e 2
        if (sscanf(input, "%d", &res3) == 1 && res3 >= 1 && res3 <= 2) {
            valid = 1; // Entrada válida
        } else {
            printf("\n\n\tResposta inválida, por favor, me diga se é Verdadeiro ou Falso!\n");
            Sleep(2000);
            system("cls");
            // Reimprime o menu
            printf("\n\n-------------------------------------------------------------------------------------------\n");
            printf("\t3) O comando float é utilizado necessariamente para números inteiros.\n");
            printf("\n\t1. Verdadeiro\n");
            printf("\t2. Falso\n");
            printf("-------------------------------------------------------------------------------------------\n");
        }
    }

    if (res3 == 2) {
        acertos++;
    } else {
        erros++;
    }
}

void questao_4() {
    char input[10]; // Buffer para armazenar a entrada do usuário
    int valid = 0; // Flag para verificar se a entrada é válida

    Sleep(200);
    system("cls");

    printf("\n\n-------------------------------------------------------------------------------------------\n");
    printf("\t4) A função scanf é utilizada para receber um valor do usuário. \n");
    printf("\n\t1. Verdadeiro\n");
    printf("\t2. Falso\n");
    printf("-------------------------------------------------------------------------------------------\n");

    while (!valid) {
        printf("\tEscolha uma opção: ");
        scanf("%s", input); // Lê a entrada como string

        // Verifica se a entrada é um número inteiro e se está entre 1 e 2
        if (sscanf(input, "%d", &res4) == 1 && res4 >= 1 && res4 <= 2) {
            valid = 1; // Entrada válida
        } else {
            printf("\n\n\tResposta inválida, por favor, me diga se é Verdadeiro ou Falso!\n");
            Sleep(2000);
            system("cls");
            // Reimprime o menu
            printf("\n\n-------------------------------------------------------------------------------------------\n");
            printf("\t4) A função scanf é utilizada para receber um valor do usuário. \n");
            printf("\n\t1. Verdadeiro\n");
            printf("\t2. Falso\n");
            printf("-------------------------------------------------------------------------------------------\n");
        }
    }

    if (res4 == 1) {
        acertos++;
    } else {
        erros++;
    }
}

void questao_5() {
    char input[10]; // Buffer para armazenar a entrada do usuário
    int valid = 0; // Flag para verificar se a entrada é válida

    Sleep(200);
    system("cls");

    printf("\n\n-------------------------------------------------------------------------------------------\n");
    printf("\t5) Em C, é possível retornar um valor de uma função usando a instrução \n\t   return mesmo em funções declaradas como void.\n");
    printf("\n\t1. Verdadeiro\n");
    printf("\t2. Falso\n");
    printf("-------------------------------------------------------------------------------------------\n");

    while (!valid) {
        printf("\tEscolha uma opção: ");
        scanf("%s", input); // Lê a entrada como string

        // Verifica se a entrada é um número inteiro e se está entre 1 e 2
        if (sscanf(input, "%d", &res5) == 1 && res5 >= 1 && res5 <= 2) {
            valid = 1; // Entrada válida
        } else {
            printf("\n\n\tResposta inválida, por favor, me diga se é Verdadeiro ou Falso!\n");
            Sleep(2000);
            system("cls");
            // Reimprime o menu
            printf("\n\n-------------------------------------------------------------------------------------------\n");
            printf("\t5) Em C, é possível retornar um valor de uma função usando a instrução \n\t   return mesmo em funções declaradas como void.\n");
            printf("\n\t1. Verdadeiro\n");
            printf("\t2. Falso\n");
            printf("-------------------------------------------------------------------------------------------\n");
        }
    }

    if (res5 == 2) {
        acertos++;
    } else {
        erros++;
    }
}

void mostrar_resultados() {

    system("cls");

    // Impede o usuário de acessar os resultados antes de fazer o quiz
    if(acertos == 0 && erros == 0)
    {
            system("cls");
                printf("\n\n\t============================================");
                printf("\n\t|\tVocê ainda não fez o quiz!       |\n");
                printf("\t============================================");
                Sleep(1500);
                system("cls");
        // Mostra os resultados de fato
    }
    else
    {
        getchar();
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf("\t1: O comando char() armazena uma unidade de qualquer um dos 256 caracteres Unicode.\n");
        printf("\n\tResposta: verdadeira\n");
        if(res1 == 1)
        {
            printf("\tVocê acertou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\tVocê errou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        getchar();

        system("cls");
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf("\t2: Para inserir um comentário em um programa C é utilizado \\.\n");
        printf("\n\tResposta: Falso \n");
        if(res2 == 2)
        {
            printf("\tVocê acertou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\tVocê errou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        getchar(); // O primeiro getchar lê o \n que ainda está no buffer

        system("cls");
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf("\t3: O comando float é utilizado necessariamente para números inteiros.\n");
        printf("\n\tResposta: Falso \n");

        if(res3 == 2)
        {
            printf("\tVocê acertou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\tVocê errou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        getchar(); // O primeiro getchar lê o \n que ainda está no buffer
        system("cls");
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf("\t4: A funcao scanf é utilizada para receber uma variavel do usuário.\n");
        printf("\n\tResposta: Verdadeira\n");
        if(res4 == 1)
        {
            printf("\tVocê acertou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\tVocê errou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        getchar();
        system("cls");
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf("\t5: Em C, é possível retornar um valor de uma função usando a instrução\n\t return mesmo em funções declaradas como void.\n");
        printf("\n\tResposta: Falso \n");
        if(res5 == 2)
        {
            printf("\tVocê acertou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\tVocê errou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        getchar(); // O primeiro getchar lê o \n que ainda está no buffer
        system("cls");

        printf("\n\n\t==========================================\n");
        printf("\n\t\t    Obrigado por jogar!\n");
        printf("\t\tVocê acertou: %d questões\n", acertos);
        printf("\t\tVocê errou: %d questões", erros);
        printf("\n\n\t==========================================");
        printf("\n\t     Pressione enter para continuar...\n");
        printf("\t==========================================");
        getchar(); // Este getchar espera até o usuário clicar no enter
        system("cls");
    }
}


