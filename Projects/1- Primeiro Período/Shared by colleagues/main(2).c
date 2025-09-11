#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <windows.h>

#define TAMANHO 100
#define QTD_NOMES 4

/*
USANDO O CÓDIGO DE EXEMPLO, DESENVOLVER UM PROGRAMAA QUE RECEBA 4 NOME EM UM VETOR
E DE A POSSIBILIDADE DE UTILIZAR AS FUNÇÕES LISTADAS A BAIXO EM QUALQUER NOME QUE ESTÁ NO VETOR,
E VAI SER ESCOLHIDO ANTES DE EXECUTAR A FUNÇÃO, O RESULTADO DEVE SER INSERIDO EM UMA MATRIZ TAMBÉM
COM 4 LINHAS E O TOTAL DE COLUNAS VAI SER IGUAL AO TOTAL DE FUNÇÕES.

E-MAIL: EDRIAN.DASILVA@DESCOMPLICA.COM.BR

*/



void capturarNome(char nomes[QTD_NOMES][TAMANHO])
{
    system("cls");
    for (int i = 0; i < QTD_NOMES; i ++)
    {
        printf("Digite o %d.o nome: ", i + 1);
        {
            fgets(nomes[i], TAMANHO, stdin);
            nomes[i][strcspn(nomes[i], "\n")] = '\0';


        }
    }
}

void Mostrar_nomes(char nomes[QTD_NOMES][TAMANHO])
{
    system("cls");
    for (int i = 0; i < QTD_NOMES; i++)
    {
        printf("O %d.o nome digitado: %s", i + 1, nomes[i]);
        printf("\n");
    }




}


int contarVogais(char nomes[QTD_NOMES][TAMANHO])
{

    int contador = 0, opc = 0;
    char vogais[] = "aeiouAEIOU";


    Mostrar_nomes(nomes);


    printf("\n\nDigite de qual nome você deseja se refirir:\n1. primeiro Nome\n2. segundo Nome\n3. terceiro Nome\n4. Quarto nome\n5. Retornar\n");
    scanf("%d", &opc);


    switch(opc)
    {
    case 1:

        for (int j = 0; nomes[0][j] != '\0'; j++) // CORREÇÃO AQUI: j++
        {
            if (strchr(vogais, nomes[0][j]) != NULL)
            {
                contador++;
            }

        }
        printf("Esse nome possui: %d Vogais\n\n", contador);
        system("pause");
        system("cls");
        break;

    case 2:

        for (int j = 0; nomes[1][j] != '\0'; j++) // CORREÇÃO AQUI: j++
        {
            if (strchr(vogais, nomes[1][j]) != NULL)
            {
                contador++;
            }

        }
        printf("Esse nome possui: %d Vogais\n\n", contador);
        system("pause");
        system("cls");
        break;

    case 3:

        for (int j = 0; nomes[2][j] != '\0'; j++) // CORREÇÃO AQUI: j++
        {
            if (strchr(vogais, nomes[2][j]) != NULL)
            {
                contador++;
            }

        }
        printf("Esse nome possui: %d Vogais\n\n", contador);
        system("pause");
        system("cls");
        break;

    case 4:

        for (int j = 0; nomes[3][j] != '\0'; j++) // CORREÇÃO AQUI: j++
        {
            if (strchr(vogais, nomes[3][j]) != NULL)
            {
                contador++;
            }

        }
        printf("Esse nome possui: %d Vogais\n\n", contador);
        system("pause");
        system("cls");
        break;

    case 5:
        printf("Retornando...");
        system("cls");
        break;

    default:
        system("cls");
        printf("Por favor, me informe um Numero entre 1 a 5!");
        sleep(1);
        system("cls");

    }



    return 0;

}



void copiarString(char nomes[QTD_NOMES][TAMANHO], char *destino)
{

    int opc = 0;
    system("cls");
    Mostrar_nomes(nomes);


    printf("\n\nDigite de qual nome você deseja se refirir:\n1. primeiro Nome\n2. segundo Nome\n3. terceiro Nome\n4. Quarto nome\n5. Retornar\n");
    scanf("%d", &opc);


    switch(opc)
    {
    case 1:

        strcpy(destino, nomes[0]);
        system("cls");
        printf("String copiada: %s\n", nomes);
        system("pause");
        break;

    case 2:

        strcpy(destino, nomes[1]);
        system("cls");
        printf("String copiada: %s\n", nomes);
        system("pause");
        break;

    case 3:

        strcpy(destino, nomes[2]);
        system("cls");
        printf("String copiada: %s\n", nomes);
        system("pause");
        break;
    case 4:

        strcpy(destino, nomes[3]);
        system("cls");
        printf("String copiada: %s\n", nomes);
        system("pause");
        break;

    case 5:
        printf("Retornando...\n");
        sleep(1);
        system("cls");
        break;

    default:
        system("cls");
        printf("Por favor, me informe um Numero entre 1 a 5!");
        sleep(1);
        system("cls");

    }
}


void unirStrings(char nomes[QTD_NOMES][TAMANHO], char *resultado)
{
    int opc1 = 0;
    int opc2 = 0;
    char uniao[2 * TAMANHO];


    Mostrar_nomes(nomes);

    printf("\n\nDigite o número do primeiro nome (1-4): ");
    scanf("%d", &opc1);

    printf("Digite o número do segundo nome (1-4): ");
    scanf("%d", &opc2);


    if (opc1 >= 1 && opc1 <= 4 && opc2 >= 1 && opc2 <= 4)
    {
        strcpy(resultado, nomes[opc1 - 1]);
        strcat(resultado, " ");
        strcat(resultado, nomes[opc2 - 1]);

        printf("\nStrings unidas: %s\n", resultado);
    }
    else
    {
        printf("\nOpção inválida! Tente novamente com valores entre 1 e 4.\n");
    }

}

void converterMaiusculas(char nomes[QTD_NOMES][TAMANHO])
{
    int i, opc;

    system("cls");
    Mostrar_nomes(nomes);

    printf("\n\nDigite de qual nome você deseja se refirir:\n1. primeiro Nome\n2. segundo Nome\n3. terceiro Nome\n4. Quarto nome\n5. Retornar\n");
    scanf("%d", &opc);



    switch(opc)
    {
    case 1:

        for (i = 0; nomes[0][i] != '\0'; i++)
        {
            nomes[0][i] = toupper(nomes[0][i]);

        }
        printf("String Atualizada!\n");
        system("pause");
        system("cls");
        break;

    case 2:

        for (i = 0; nomes[1][i] != '\0'; i++)
        {
            nomes[1][i] = toupper(nomes[1][i]);

        }
        printf("String Atualizada!\n");
        system("pause");
        system("cls");
        break;

    case 3:

        for (i = 0; nomes[2][i] != '\0'; i++)
        {
            nomes[2][i] = toupper(nomes[2][i]);

        }
        printf("String Atualizada!\n");
        system("pause");
        system("cls");
        break;

    case 4:

        for (i = 0; nomes[3][i] != '\0'; i++)
        {
            nomes[3][i] = toupper(nomes[3][i]);

        }
        printf("String Atualizada!\n");
        system("pause");
        system("cls");
        break;

    case 5:
        printf("Retornando...");
        system("cls");
        break;

    default:
        system("cls");
        printf("Por favor, me informe um Numero entre 1 a 5!");
        sleep(1);
        system("cls");

    }
}


void converterMinusculas(char nomes[QTD_NOMES][TAMANHO])
{
    int i, opc;

    system("cls");
    Mostrar_nomes(nomes);

    printf("\n\nDigite de qual nome você deseja se refirir:\n1. primeiro Nome\n2. segundo Nome\n3. terceiro Nome\n4. Quarto nome\n5. Retornar\n");
    scanf("%d", &opc);



    switch(opc)
    {
    case 1:

        for (i = 0; nomes[0][i] != '\0'; i++)
        {
            nomes[0][i] = tolower(nomes[0][i]);

        }
        printf("String Atualizada!\n");
        system("pause");
        system("cls");
        break;

    case 2:

        for (i = 0; nomes[1][i] != '\0'; i++)
        {
            nomes[1][i] = tolower(nomes[1][i]);

        }
        printf("String Atualizada!\n");
        system("pause");
        system("cls");
        break;

    case 3:

        for (i = 0; nomes[2][i] != '\0'; i++)
        {
            nomes[2][i] = tolower(nomes[2][i]);

        }
        printf("String Atualizada!\n");
        system("pause");
        system("cls");
        break;

    case 4:

        for (i = 0; nomes[3][i] != '\0'; i++)
        {
            nomes[3][i] = tolower(nomes[3][i]);

        }
        printf("String Atualizada!\n");
        system("pause");
        system("cls");
        break;

    case 5:
        printf("Retornando...");
        system("cls");
        break;

    default:
        system("cls");
        printf("Por favor, me informe um Numero entre 1 a 5!");
        sleep(1);
        system("cls");

    }
}

void inverterString(char nomes[QTD_NOMES][TAMANHO])
{
    int i, opc;

    system("cls");
    Mostrar_nomes(nomes);

    printf("\n\nDigite de qual nome você deseja se refirir:\n1. primeiro Nome\n2. segundo Nome\n3. terceiro Nome\n4. Quarto nome\n5. Retornar\n");
    scanf("%d", &opc);



    switch(opc)
    {
    case 1:
        strrev(nomes);
        printf("String invertida: %s\n", nomes);
        system("pause");
        system("cls");
        break;

    case 2:

        printf("String invertida: %s\n", nomes);
        system("pause");
        system("cls");
        break;

    case 3:

        printf("String invertida: %s\n", nomes);
        system("pause");
        system("cls");
        break;

    case 4:

        printf("String invertida: %s\n", nomes);
        system("pause");
        system("cls");
        break;

    case 5:
        printf("Retornando...");
        system("cls");
        break;

    default:
        system("cls");
        printf("Por favor, me informe um Numero entre 1 a 5!");
        sleep(1);
        system("cls");

    }
}


void comparar_string(char nomes[QTD_NOMES][TAMANHO], int opc1, int opc2)
{
    int i;

    system("cls");
    Mostrar_nomes(nomes);

    printf("\n\nDigite o número do primeiro nome (1-4): ");
    scanf("%d", &opc1);

    printf("Digite o número do segundo nome (1-4): ");
    scanf("%d", &opc2);

    if (opc1 >= 1 && opc1 <= 4 && opc2 >= 1 && opc2 <= 4)
    {
        strcmp(opc1, opc2);
    }
        else
        {
            printf("\nOpção inválida! Tente novamente com valores entre 1 e 4.\n");
        }

    }


    int main()
    {

        int option,opc1 = 0,opc2 = 0;

        char nomes[QTD_NOMES][TAMANHO], copia[TAMANHO], uniao[2 * TAMANHO];


        do
        {
            system("cls");
            printf("=====================================\n");
            printf("         MENU DE STRINGS - C         \n");
            printf("=====================================\n");
            printf("1. Cadastrar nomes\n");
            printf("2. Exibir nomes\n");
            printf("3. Copiar a string em uma variavel\n");
            printf("4. Unir duas opções\n");
            printf("5. Converter nomes para maiuscula\n");
            printf("6. Converter nomes para minuscula\n");
            printf("7. contar vogais\n");
            printf("8. Inverter Nome\n");
            printf("9. Comparar Nome\n");
            printf("10. Sair...\n>");

            scanf("%d", &option);
            getchar();


            switch(option)
            {
            case 1:
                system("cls");
                capturarNome(nomes);
                break;
            case 2:
                system("cls");
                Mostrar_nomes(nomes);
                system("pause");
                break;
            case 3:
                system("cls");
                copiarString(nomes, copia);
                break;
            case 4:
                system("cls");
                unirStrings(nomes, uniao);
                break;
            case 5:
                system("cls");
                converterMaiusculas(nomes);
                break;
            case 6:
                system("cls");
                converterMinusculas(nomes);
                break;
            case 7:
                system("cls");
                contarVogais(nomes);
                break;
            case 8:
                system("cls");
                inverterString(nomes);
                break;
            case 9:
                system("cls");
                if (comparar_string(nomes, opc1, opc2) == 0)
                {
                    printf("As strings são iguais.\n");
                }
                else
                {
                    printf("As strings são diferentes.\n");
                }
            }
            comparar_string(nomes, opc1,opc2);
            break;
        case 10:
            system("cls");
            printf("Saindo...\n\nObrigado por Rodar =)");
            break;

        default:
            printf("Por favor, me informe um numero de 1 a 10!");
            system("cls");
        }
    }
    while (option != 10);
    return 0;
}
