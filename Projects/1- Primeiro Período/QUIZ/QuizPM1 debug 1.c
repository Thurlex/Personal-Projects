#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>


int acertos = 0, erros = 0; // Contadores de acertos e erros, necess�rios para
// contar a pontua��o do usu�rio pelo quiz e para mostrar os resultados

int res1, res2, res3, res4, res5;

// Function prototypes
void iniciar_quiz();
void questao_1();
void questao_2();
void questao_3();
void questao_4();
void questao_5();
void mostrar_resultados();


int main(){

    int menu_principal;

    // Configura o terminal para usar UTF-8
    setlocale(LC_ALL, "Portuguese_Brazil");
    system("chcp 1252");

    do{
        // Permite que o sistema leia letras com acento e outras como cedilha
        setlocale(LC_ALL, "Portuguese_Brazil");

        // Lembrete: system("cls") limpa a tela
        system("cls");

        // Menu principal
        printf("\n\n-------------------------------------------------------------\n");
        printf("\tDigite o numero correspondente a sua escolha:\n");
        printf("-------------------------------------------------------------\n");
        printf("\t1. Iniciar o quiz\n");
        printf("\t2. Mostrar o resultado\n");
        printf("\t3. Limpar respostas\n");
        printf("\t4. Sair\n");
        printf("-------------------------------------------------------------\n");
        printf("\tEscolha uma das op��es: ");
        scanf("%d", &menu_principal);

        // Switch case para o menu principal
        switch(menu_principal){
        case 1:
            iniciar_quiz();
            break;
        case 2:
            mostrar_resultados();
            break;
        case 3:
            if(acertos == 0 && erros == 0){

                system("cls");
                printf("\n\n\t==========================================");
                printf("\n\t|\tVoc� ainda n�o fez o quiz!       |\n");
                printf("\t==========================================");
                Sleep(1500);
                system("cls");

            }else{
               system("cls");
                printf("\n\n\t==========================================");
                printf("\n\t\t\tRespostas Limpas!\n");
                printf("\t==========================================");
                Sleep(800);
                system("cls");
            }
		case 4:
            system("cls");
            printf("\n\n==========================================");
            printf("\n\t\tSaindo...\n");
            printf("=========================================\n\n");
            break;
        default:
            printf("\n\n\tOp��o invalida, tente novamente!\n");
            Sleep(700);
            break;
        }
    }while(menu_principal != 4);

    return 0;
}


void iniciar_quiz(){

    if(acertos > 0 && erros > 0){

        printf("\t");
        Sleep(2);
        system("cls");
                printf("\n\n================================================================================");
                printf("\n\tVoc� precisa limpar os resultados, para iniciar o quiz novamente!");
                printf("\n\n================================================================================");
                Sleep(1500);
                system("cls");
    }else{

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
        printf("\n\n=====================================================================");
        printf("\n\n\t\tParab�ns, voc� completou o Quiz. \n\tVeja seu resultado digitando '2' na tela a seguir");
        printf("\n\n======================================================================");

        Sleep(2000);
    }
}

void questao_1() {

    Sleep(200);
    system("cls");

    printf("\n\n-------------------------------------------------------------------------------------------\n");
    printf("\t1) O comando char() armazena uma unidade de qualquer um dos 256 caracteres.\n");
    printf("\n\t1. Verdadeiro\n");
    printf("\t2. Falso\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("\tEscolha uma op��o: ");
    scanf("%d", &res1);
    if(res1 <= 2 && res1 > 0){
        if (res1 == 1){
            acertos ++;
        }else if (res1 == 2){
            erros ++;
        }
    }else{
        Sleep(500);
        printf("\n\n\tResposta inv�lida, por favor, me diga se � Verdadeiro ou Falso!");
        Sleep(2000);
        questao_1();
    }
}

void questao_2() {

    Sleep(200);
    system("cls");

    printf("\n\n-------------------------------------------------------------------------------------------\n");
    printf("\t2) Para inserir um comentario em um programa C � utilizado \\.\n");
    printf("\n\t1. Verdadeiro\n");
    printf("\t2. Falso\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("\tEscolha uma op��o: ");
    scanf("%d", &res2);
    if(res2 <= 3 && res2 > 0){
        if (res2 == 2 ){
            acertos ++;
        }
        else if (res2 == 1){
            erros ++;
        }
    }else{
        Sleep(500);
        printf("\n\n\tResposta inv�lida, por favor, me diga se � Verdadeiro ou Falso!");
        sleep(2);
        questao_2();
    }
}

void questao_3() {

    Sleep(200);
    system("cls");

    printf("\n\n-------------------------------------------------------------------------------------------\n");
    printf("\t3) O comando float � utilizado necessariamente para numeros inteiros.\n");
    printf("\n\t1. Verdadeiro\n");
    printf("\t2. Falso\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("\tEscolha uma op��o: ");
    scanf("%d", &res3);
    if(res3 <= 2 && res3 > 0){
        if (res3 == 2){
            acertos ++;
        }else if (res3 == 1){
            erros ++;
        }
    }else{
        Sleep(500);
        printf("\n\n\tResposta inv�lida, por favor, me diga se � Verdadeiro ou Falso!");
        sleep(2);
        questao_3();
    }
}

void questao_4() {

    Sleep(200);
    system("cls");

    printf("\n\n-------------------------------------------------------------------------------------------\n");
    printf("\t4) A funcao scanf � utilizada para receber uma valor do usuario. \n");
    printf("\n\t1. Verdadeiro\n");
    printf("\t2. Falso\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("\tEscolha uma op��o: ");
    scanf("%d", &res4);
    if(res4 <= 2 && res4 > 0){
        if (res4 == 1){
            acertos ++;
        }else if (res4 == 2){
            erros ++;
        }
    }else{
        Sleep(500);
        printf("\n\n\tResposta inv�lida, por favor, me diga se � Verdadeiro ou Falso!");
        sleep(2);
        questao_4();
    }

}

void questao_5() {

    Sleep(200);
    system("cls");

    printf("\n\n-------------------------------------------------------------------------------------------\n");
    printf("\t5) Em C, � poss�vel retornar um valor de uma fun��o usando a instru��o \n\t   return mesmo em fun��es declaradas como void.\n");
    printf("\n\t1. Verdadeiro\n");
    printf("\t2. Falso\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("\tEscolha uma op��o: ");
    scanf("%d", &res5);
    if(res5 <= 2 && res5 > 0){
        if (res5 == 2){
            acertos ++;
        }else if (res5 == 1){
            erros ++;
        }
    }else{
        Sleep(500);
        printf("\n\n\tResposta inv�lida, por favor, me diga se � Verdadeiro ou Falso!");
        sleep(2);
        questao_5();
    }
}

void mostrar_resultados() {

    system("cls");

    // Impede o usu�rio de acessar os resultados antes de fazer o quiz
    if(acertos == 0 && erros == 0)
    {
            system("cls");
                printf("\n\n\t==========================================");
                printf("\n\t|\tVoc� ainda n�o fez o quiz!       |\n");
                printf("\t==========================================");
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
            printf("\tVoc� acertou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\tVoc� errou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        getchar();

        system("cls");
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf("\t2: Para inserir um comentario em um programa C � utilizado \\.\n");
        printf("\n\tResposta: Falso \n");
        if(res2 == 2)
        {
            printf("\tVoc� acertou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\tVoc� errou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        getchar(); // O primeiro getchar l� o \n que ainda est� no buffer

        system("cls");
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf("\t3: O comando float � utilizado necessariamente para numeros inteiros.\n");
        printf("\n\tResposta: Falso \n");

        if(res3 == 2)
        {
            printf("\tVoc� acertou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\tVoc� errou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        getchar(); // O primeiro getchar l� o \n que ainda est� no buffer
        system("cls");
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf("\t4: A funcao scanf � utilizada para receber uma variavel do usuario.\n");
        printf("\n\tResposta: Verdadeira\n");
        if(res4 == 1)
        {
            printf("\tVoc� acertou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\tVoc� errou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        getchar();
        system("cls");
        printf("\n---------------------------------------------------------------------------------------------------\n");
        printf("\t5: Em C, � poss�vel retornar um valor de uma fun��o usando a instru��o\n\t return mesmo em fun��es declaradas como void.\n");
        printf("\n\tResposta: Falso \n");
        if(res5 == 2)
        {
            printf("\tVoc� acertou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\tVoc� errou!\n");
            printf("---------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\tPressione enter para continuar...\n");
            printf("\n---------------------------------------------------------------------------------------------------\n");
        }
        getchar(); // O primeiro getchar l� o \n que ainda est� no buffer
        system("cls");

        printf("\n\n\t==========================================\n");
        printf("\n\t\t    Obrigado por jogar!\n");
        printf("\t\tVoc� acertou: %d quest�es\n", acertos);
        printf("\t\tVoc� errou: %d quest�es", erros);
        printf("\n\n\t==========================================");
        printf("\n\t     Pressione enter para continuar...\n");
        printf("\t==========================================");
        getchar(); // Este getchar espera at� o usu�rio clicar no enter
        system("cls");


    }
}


