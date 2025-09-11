#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include <windows.h>

// Variaveis globais
int acertos = 0, erros = 0; // Contadores de acertos e erros, necessários para
                            // contar a pontuação do usuário pelo quiz e para mostrar os resultados
                            
int res1, res2, res3, res4, res5; // Variaveis para armazenar as respostas do usuário
                                  // necessárias para indicar os acertos e erros tanto no quiz
                                  // quanto nos resultados

// Limita a escolha do usuario entre 1 e 2
int limitar_VF(const char* pergunta) {

    int resposta;
    while (1) {
        printf("%s", pergunta);
        scanf("%d", &resposta);
        if (resposta >= 1 && resposta <= 2) {
            return resposta;
        } else {
            printf("Opção invalida, tente novamente!");
            sleep(1);
            system("cls");
        }
    }
}

// Inicia o quiz
void iniciar_quiz() {

    if(acertos > 0 && erros > 0) {
        system("cls");
        printf("Você precisa limpar os resultados \n");
        printf("para iniciar o quiz novamente!");
        sleep(2);
    } else {

    system("cls");

        const char* pergunta1 = "1) O comando char() armazena uma unidade \n"
                                "de qualquer um dos 256 caracteres Unicode.\n"
                                "1. Verdadeiro\n"
                                "2. Falso\n"
                                "\n"
                                "Resposta: ";
        res1 = limitar_VF(pergunta1);
        if(res1 == 1) {
            acertos ++;
        } else {
            erros ++;
        }

        system("cls");
        const char* pergunta2 = "2) Para inserir um comentário em um \n"
                                "programa C é utilizado \\.\n"
                                "1. Verdadeiro\n"
                                "2. Falso\n"
                                "\n"
                                "Resposta: ";
        res2 = limitar_VF(pergunta2);
        if(res2 == 2) {
            acertos ++;
        } else {
            erros ++;
        }

        system("cls");
        const char* pergunta3 = "3) O comando float escreve em numeros \n"
                                "inteiros.\n"
                                "1. Verdadeiro\n"
                                "2. Falso\n"
                                "\n"
                                "Resposta: ";
        res3 = limitar_VF(pergunta3);
        if(res3 == 2) {
            acertos ++;
        } else {
            erros ++;
        }

        system("cls");
        const char* pergunta4 = "4) A funcao scanf é utilizada para \n"
                                "receber uma variavel do usuario.\n"
                                "1. Verdadeiro\n"
                                "2. Falso\n"
                                "\n"
                                "Resposta: ";
        res4 = limitar_VF(pergunta4);
        if(res4 == 1) {
            acertos ++;
        } else {
            erros ++;
        }

        system("cls");
        const char* pergunta5 = "5) Uma funcao é um bloco de codigo que\n"
                                "executa uma tarefa aleatória.\n"
                                "1. Verdadeiro\n"
                                "2. Falso\n"
                                "\n"
                                "Resposta: ";
        res5 = limitar_VF(pergunta5);
        if(res5 == 2) {
            acertos ++;
        } else {
            erros ++;
        }
    }
}

// Mostra os resultados do quiz
void mostrar_resultados() {

    system("cls");

    // Impede o usuário de acessar os resultados antes de fazer o quiz
    if(acertos == 0 && erros == 0) { 
        printf("Você ainda não fez o quiz!\n");
        printf("\n");
        sleep(1.7);
        system("cls");
    // Mostra os resultados de fato
    } else {
        printf("Você acertou: %d questões\n", acertos);
        printf("Você errou: %d questões\n", erros);
        printf("\n");

        printf("A resposta correta para a questão 1\n");
        printf("O comando char() armazena uma unidade \n");
        printf("de qualquer um dos 256 caracteres Unicode.\n");
        printf("é verdadeira\n");
        if(res1 == 1) {
            printf("Você acertou!\n");
        } else {
            printf("Você errou!\n");
        }
        printf("\n");

        printf("A resposta correta para a questão 2\n");
        printf("Para inserir um comentário em um \n");
        printf("programa C é utilizado \\.\n");
        printf("é falso pois o correto é //.\n");
        if("res2 == 2") {
            printf("Você acertou!\n");
        } else {
            printf("Você errou!\n");
        }
        printf("\n");

        printf("A resposta correta para a questão 3\n");
        printf("O comando float escreve em numeros \n");
        printf("inteiros.\n");
        printf("é falso pois o comando float escreve \n");
        printf("em numeros decimais.\n");
        if(res3 == 1) {
            printf("Você acertou!\n");
        } else {
            printf("Você errou!\n");
        }
        printf("\n");
        
        printf("A resposta correta para a questão 4\n");
        printf("A funcao scanf é utilizada para \n");
        printf("receber uma variavel do usuario.\n");
        printf("é verdadeira");
        if(res4 == 1) {
            printf("Você acertou!\n");
        } else {
            printf("Você errou!\n");
        }
        printf("\n");

        printf("A resposta correta para a questão 5\n");
        printf("Uma funcao é um bloco de codigo que\n");
        printf("executa uma tarefa aleatória.\n");
        printf("é falso pois uma função executa uma tarefa\n");
        printf("específica.\n");
        if(res5 == 2) {
            printf("Você acertou!\n");
        } else {
            printf("Você errou!\n");
        }
        printf("\n");

        printf("Obrigado por jogar!\n");
        printf("\n");
        printf("Pressione enter para continuar...\n");
    getchar(); // O primeiro getchar lê o \n que ainda está no buffer
    getchar(); // Este getchar espera até o usuário clicar no enter
    system("cls");
    }
}

// Reinicia o estado das memorias para 0
void limpar_respostas() {
    if(acertos == 0 && erros == 0) { 
        system("cls");
        printf("Você ainda não fez o quiz!\n");
        printf("\n");
        sleep(1.7);
        system("cls");
    } else {
        system("cls");
        acertos = 0, erros = 0;
        printf("Respostas limpas!");
        sleep(1.7);
    }
}

int main() {
    int menu_principal;

    // Configura o terminal para usar UTF-8
    // Permite que o sistema leia letras com acento e outras como cedilha
    setlocale(LC_ALL, "Portuguese");
    system("chcp 65001");
    SetConsoleCP(CP_UTF8);

    while(1) {
        

        // Lembrete: system("cls") limpa a tela
        system("cls");

        // Menu principal
        printf("Digite o número correspondente a sua escolha:\n");
        printf("1. Iniciar o quiz\n");
        printf("2. Mostrar o resultado\n");
        printf("3. Limpar respostas\n");
        printf("4. Sair\n");
        printf("\n");
        printf("Escolha uma das opções: ");
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
                printf("Opção invalida, tente novamente!\n");
                sleep(1.5);
                break;
        }
    }
}