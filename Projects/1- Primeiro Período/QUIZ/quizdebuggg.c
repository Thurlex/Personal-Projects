#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <unistd.h>

int main() {
    int menu_principal;

    // Configura o terminal para usar UTF-8
    // Permite que o sistema leia letras com acento e outras como cedilha
    
    // SetConsoleOutputCP(CP_UTF8); // Não é necessário

    while(1) {
        

        // Lembrete: system("cls") limpa a tela
        system("cls");
        system("chcp 1252");

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
                // function
                break;
            case 2:
                // function
                break;
            case 3:
                // function
                break;
            case 4:
                // function
            default:
                // function
        }
    }
}