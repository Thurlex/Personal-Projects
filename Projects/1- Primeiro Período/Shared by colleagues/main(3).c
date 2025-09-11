#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_ANIMAIS 20



int scanint(int min, int max)
{
    int sr; // guarda o retorno do scanf
    int op; // guarda o valor digitado pelo usuario

    do   // esse loop eh executado ateh que o usuario digite um valor valido
    {
        sr = scanf("%d", &op); // sr sera zero se usuario digitar uma letra
        if ((sr == 0) || (op < min) || (op > max))
        {
            printf("Opção inválida - por favor entre com um valor entre %d e %d!\n", min, max);
            if (sr == 0)
                while (getchar() != '\n'); // Limpa ENTER anteriores do buffer de entrada;
        }
    }
    while ((sr == 0) || (op < min) || (op > max));

    return op;
}

int main()
{
    int tipo_animal[MAX_ANIMAIS];
    int soma = 0;
    int contador_bipedes = 0,contador_quadrupedes = 0;


    setlocale(LC_ALL,"Portuguese_Brazil");
     for (int i = 0; i < MAX_ANIMAIS; i++)
    {

        printf("Please, let me know:\n1. Bípede\n2. Quadrúpedes\n");
        tipo_animal[i] = scanint(1,2);

        if (tipo_animal[i] == 1)
        {
            contador_bipedes ++;
        }
        else if (tipo_animal[i] == 2)
        {
            contador_quadrupedes++;
        }

    }

    printf("it have:%d Bipedes\nAnd:%d Quadrupedes\n\n", contador_bipedes,contador_quadrupedes);

    system("pause");
    contador_bipedes *= 2;
    contador_quadrupedes *= 4;

    system("cls");
    printf("You had %d bipedes paws in your farm\n\n", contador_bipedes);

    printf("You had %d bipedes paws in your farm\n\n", contador_quadrupedes);


    system("pause");
    system("cls");

    soma = contador_bipedes + contador_quadrupedes;
    printf("the sum of all paws in your farm (including yours) is: %d \n\n", soma + 2);
    system("pause");

    system("cls");
    printf("bye...\n\n");

}



