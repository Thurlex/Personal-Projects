#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

#define ALUNOS 4
#define NOTAS 5
#define MEDIA_APROVACAO 7.0


/*
USANDO MATRIZ ESCREVA UM SISTEMA PARA CADASTRAR 5 NOTAS PARA 4 ALUNOS&
CRIAR UM MENU PARA
CADASTRAR NOTAS&
VER TODAS AS NOTAS DE TODOS OS ALUNOS&
CALCULAR E EXIBIR A MÉDIA DE CADA ALUNO&
MOSTRAR QUAIS ALUNOS FORAM APROVADOS E REPROVADOS
SAIR DO PROGRAMA
*/








void cadastrar_nota(float notas[ALUNOS][NOTAS])
{

    int i, j;


    for (i = 0; i < 4; i++)
    {
        printf("Digite as 5 notas do aluno %d:\n", i + 1);
        for (j = 0; j < 5; j++)
        {
            notas[i][j] = 0;
            printf("Nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
            while (notas[i][j] < 0 || notas[i][j] > 100)
            {

                printf("Digite um valor entre 0 e 100!\n");
                system("pause");
                system("cls");
                printf("Nota %d: ", j + 1);
                scanf("%f", &notas[i][j]);
            }

        }
    }
}

void exibir_nota(float notas[4][5])
{

    // Exibindo as notas armazenadas
    printf("\nNotas dos alunos:\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Aluno %d \n: ", i + 1);
        for (int j = 0; j < 5; j++)
        {
            printf("%.2f", notas[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    system("pause");


}



void media(float notas[ALUNOS][NOTAS])
{
    float soma = 0;
    int escolha = 0;
    int media[ALUNOS] = {0};


    for (int i = 0; i<ALUNOS; i++)
    {
        for (int j = 0; j<NOTAS; j++)
        {

            soma += notas[i][j];

        }
    }

    printf("A Soma de todas as notas é de: %.2f\n\n", soma);
    system("pause");
    system("cls");



    for (int i = 0; i<ALUNOS; i++)
    {
        int soma = 0;

        for (int j = 0; j<NOTAS; j++)
        {
            soma += notas[i][j];

        }
        media[i] = soma / NOTAS;
        printf("\nA Media do aluno %d é de: %d\n\n", i + 1, media[i]);
        system("pause");
        system("cls");
    }

        for (int i = 0; i<ALUNOS; i++)
        {
            if (media[i] >= MEDIA_APROVACAO)
                {
                    printf("Aluno %d: aprovado\n", i + 1);
                    system("pause");
                    system("cls");

                }
                else
                {
                    printf("Aluno %d: reprovado\n", i + 1);
                    system("pause");
                    system("cls");

                }
        }




}



int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    float notas[4][5];
    int opc;


    printf("Bem vindo ao MELHOR sistema de notas dos seus alunos!!!");
    sleep(2);
    do
    {

        system("cls");
        printf(">>>>>>>>>>>>>>>>>>>>> POR FAVOR, ME DIGA O QUE DESEJA FAZER <<<<<<<<<<<<<<<<<<<<<<<\n");
        printf("1. Cadastrar Notas dos Alunos\n");
        printf("2. notas dos alunos\n");
        printf("3. Ver soma e a media dos alunos\n");
        printf("5. Sair\n");
        scanf("%d", &opc);


        switch(opc)
        {
        case 1:
            system("cls");
            cadastrar_nota(notas);
            break;
        case 2:
            system("cls");
            exibir_nota(notas);
            break;
        case 3:
            system("cls");
            media(notas);
            break;
        case 4:
            break;
        default:
            printf("Digite uma das opções que eu pedi!");


        }



    }
    while(opc != 4);
    return 0;



}
