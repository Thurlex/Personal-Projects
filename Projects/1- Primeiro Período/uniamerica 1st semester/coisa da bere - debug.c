#include <stdio.h>
#include <windows.h>

typedef struct {
    char nome[50];
    char tipo[50];
    char marca[50];
    char validade[50];
    float preco;
} ProdutoLimpeza;

void abertura_caixa() {
    float valor_inicial;

    printf("=== Abertura do Caixa ===\n");
    printf("Digite o valor inicial do caixa: R$ ");
    scanf("%f", &valor_inicial);
    printf("Caixa aberto com sucesso! Valor inicial: R$ %.2f\n", valor_inicial);
}

void adicionar_produto_limpeza() {
    char nome[50], tipo[50], marca[50], validade[50];
    float preco;
    
    printf("=== Cadastro de Produto de Limpeza ===\n");
    printf("Nome do produto: ");
    scanf(" %[^\n]s", nome);
    printf("Tipo do produto: ");
    scanf(" %[^\n]s", tipo);
    printf("Marca: ");
    scanf(" %[^\n]s", marca);
    printf("Validade: ");
    scanf(" %[^\n]s", validade);
    printf("Preço: R$ ");
    scanf("%f", &preco);
    
    // Aqui você pode adicionar o código para salvar em arquivo ou estrutura de dados
}

void exibir_produtos_limpeza() {
    printf("=== Produtos de Limpeza Cadastrados ===\n");
    // Aqui você pode adicionar o código para ler e exibir os produtos
}

void limpeza() {
    char opcao[2];
    int escolha_limpeza;
    
    printf("=== Menu Produtos de Limpeza ===\n");
        printf("1. Adicionar novo item\n");
        printf("2. Exibir itens cadastrados\n");
        printf("3. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%s", opcao);
        system("cls");
        
        if(sscanf(opcao, "%d", &escolha_limpeza) == 1 && escolha_limpeza >= 1 && escolha_limpeza <= 3) {
            switch (escolha_limpeza) {
                case 1:
                    adicionar_produto_limpeza();
                    break;
                case 2:
                    exibir_produtos_limpeza();
                    break;
                case 3:
                    return;
                default:
                    printf("Opção inválida!\n");
            }
        } else {
            printf("Opção inválida!\n");
        }
        
        printf("\nPressione ENTER para continuar...");
        getchar();
        getchar();
        system("cls");
}

int main() {
    char input[2];  // Aumentei para 2 para ter espaço para o caractere nulo
    int menu_principal;
    int valid = 0;

    system("chcp 65001 > nul");

    do {
        printf("=== Menu do Mercadinho da Dona Berê ===\n");
        printf("1. Cadastrar produto\n");
        printf("2. Exibir produtos cadastrados\n");
        printf("3. Sair\n");
        printf("Digite um número: ");
        scanf("%s", input);
        
        if (sscanf(input, "%d", &menu_principal) == 1 && menu_principal >= 1 && menu_principal <= 3) {
            system("cls");
            printf("1. Materiais de Limpeza\n");
            printf("2. Venda de Alimentos\n");
            printf("3. Padaria\n");
            printf("4. Pagamento\n");
            printf("5. Abertura do Caixa\n");
            printf("6. Fechamento de Caixa\n");
            printf("7. Sair\n");
            
            printf("Escolha uma das opções: ");
            scanf("%s", input);
            
            if (sscanf(input, "%d", &menu_principal) == 1 && menu_principal >= 1 && menu_principal <= 7) {
                switch (menu_principal) {
                    case 1:
                        system("cls");
                        limpeza();
                        break;
                    
                case 2:
                system("cls");
                    //alimentos();
                    break;

                case 3:
                system("cls");
                    //padaria();
                    break;
                
                case 4:
                system("cls");
                    //pagamento();
                    break;

                case 5:
                system("cls");
                    //abrir_caixa();
                    break;

                case 6:
                system("cls");
                    //fechar_caixa();
                    break;

                case 7:
                    printf("Saindo...");
            Sleep(2000);
                system("exit");

                default:
                    break;
                }
            }
        } while (menu_principal != 3); // Keeps the main menu running indefinitely
    } // Closing brace for main function

// Para entender sscanf é necessário ler cada ponto como uma parte só:
// if (sscanf(input, "%d", &menu_principal) == 1 && menu_principal >= 1 && menu_principal <= 7)
// Caso o input for um número inteiro, entre 1 e 7, valid será = 1
// em termos técnicos, input é transferido para %d, já ali é um check porque %d é exclusivo para
// números inteiros. Se ele passar no %d, a variável menu_principal aceita ele, e aquela parte se torna
// verdadeira (== 1). Então, ele verifica se menu_principal é maior ou igual a 1 e menor ou igual a 7
//

// Referências utilizadas:
// https://stackoverflow.com/questions/2796108/how-to-prevent-users-from-inputting-letters-or-numbers