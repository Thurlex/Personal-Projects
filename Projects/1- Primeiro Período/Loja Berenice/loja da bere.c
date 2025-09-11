#include <stdio.h>
#include <windows.h>
#include <string.h>

#define MAX_PRODUTOS 100 // Define o número máximo de produtos que podem ser cadastrados

typedef struct {
    char nome[50];
    char tipo[50];
    char marca[50];
    char estoque[50];
    float preco;
    char classificacao[20]; // Para classificação de produtos (ex.: "Limpeza" ou "Alimentos")
} Produto;

Produto produtos[MAX_PRODUTOS]; // Array para armazenar os produtos cadastrados

// Variáveis globais
int total_produtos = 0; // Variável global para contar o total de produtos cadastrados
float total_compra = 0.0; // Variável global para armazenar o total da compra
float valor_inicial_caixa;
int caixa_aberto = 0;


void adicionar_produto_limpeza() {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido! Não é possível adicionar mais.\n");
        return;
    }

    Produto novo_produto;

    printf("=== Cadastro de Produto de Limpeza ===\n");
    printf("Nome do produto: ");
    scanf(" %49[^\n]", novo_produto.nome); // Esta linha de código usa a função scanf em C para ler 
                                           // uma string de entrada do usuário e armazená-la no campo 
                                           // nome da estrutura novo_produto.
    printf("Tipo do produto: ");
    scanf(" %49[^\n]", novo_produto.tipo); // Segue a mesma lógica da linha anterior, mas para o campo 
                                           // tipo. 
                                           // O %49[^\n] significa que ele vai ler até 49 caracteres 
                                           // ou até encontrar uma nova linha (\n).
    printf("Marca: ");
    scanf(" %49[^\n]", novo_produto.marca);
    printf("Quantidade: ");
    scanf(" %49[^\n]", novo_produto.estoque);
    printf("Preço: R$ ");
    scanf("%f", &novo_produto.preco);

    strcpy(novo_produto.classificacao, "Limpeza"); // Set classificação para "Limpeza"

    produtos[total_produtos] = novo_produto;
    total_produtos++;

    printf("Produto de limpeza cadastrado com sucesso!\n");
    printf("\nPressione ENTER para continuar...");
    getchar(); // Limpa o buffer de entrada
    getchar(); // Aguarda o usuário pressionar ENTER
    system("cls"); // Limpa a tela após o cadastro
    return; // Volta ao menu principal
}


void exibir_produtos_limpeza() {
    int found = 0; // Flag para checar se algum produto foi encontrado

    printf("=== Produtos de Limpeza Cadastrados ===\n");
    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(produtos[i].classificacao, "Limpeza") == 0) {
            found = 1;
            printf("Produto %d:\n", i + 1);
            printf("  Nome: %s\n", produtos[i].nome);
            printf("  Tipo: %s\n", produtos[i].tipo);
            printf("  Marca: %s\n", produtos[i].marca);
            printf("  Estoque: %s\n", produtos[i].estoque);
            printf("  Preço: R$ %.2f\n", produtos[i].preco);
            printf("  Classificação: %s\n", produtos[i].classificacao); // Exibe a classificação do produto
            printf("-------------------------\n");
            
            getchar();
            getchar();
        }
    }

    if (!found) {
        printf("Nenhum produto de limpeza cadastrado.\n");
    }
}


void limpeza() {
    char input[2];
    int escolha_limpeza;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de acessar os produtos de limpeza.\n");
        printf("Pressione ENTER para retornar...\n");
        getchar(); // Limpa o buffer de entrada
        getchar(); // Aguarda o usuário pressionar ENTER
        return;
    }
    
    printf("=== Menu Produtos de Limpeza ===\n");
        printf("1. Adicionar novo item\n");
        printf("2. Exibir itens cadastrados\n");
        printf("3. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%s", input);
        system("cls");
        
        if(sscanf(input, "%d", &escolha_limpeza) == 1 && escolha_limpeza >= 1 && escolha_limpeza <= 3) {
            switch (escolha_limpeza) {
                case 1:
                    adicionar_produto_limpeza();
                    break;
                case 2:
                    exibir_produtos_limpeza();
                    break;
                case 3:
                    return; // Volta ao menu principal
                default:
                    printf("Opção inválida!\n");
            }
        } else {
            printf("Opção inválida!\n");
        }
}


void adicionar_produto_alimentos() {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido! Não é possível adicionar mais.\n");
        return;
    }

    Produto novo_produto;

    printf("=== Cadastro de Produto Alimentício ===\n");
    printf("Nome do produto: ");
    scanf(" %49[^\n]", novo_produto.nome);
    printf("Tipo do produto: ");
    scanf(" %49[^\n]", novo_produto.tipo);
    printf("Marca: ");
    scanf(" %49[^\n]", novo_produto.marca);
    printf("Quantidade: ");
    scanf(" %49[^\n]", novo_produto.estoque);
    printf("Preço: R$ ");
    scanf("%f", &novo_produto.preco);

    strcpy(novo_produto.classificacao, "Alimento"); // Set classificação para "Alimentos"

    produtos[total_produtos] = novo_produto;
    total_produtos++;

    printf("Produto alimentício cadastrado com sucesso!\n");
    printf("\nPressione ENTER para continuar...");
    getchar(); // Limpa o buffer de entrada
    getchar(); // Aguarda o usuário pressionar ENTER
    system("cls"); // Limpa a tela após o cadastro
    return; // Volta ao menu principal
}


void exibir_produtos_alimentos() {
    int found = 0; // Flag para checar se algum produto foi encontrado

    printf("=== Produtos Alimentícios Cadastrados ===\n");

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(produtos[i].classificacao, "Alimentos") == 0) {
            found = 1;
            printf("Produto %d:\n", i + 1);
            printf("  Nome: %s\n", produtos[i].nome);  // Aponta para o nome do produto guardado em produtos[i]
                                                       // produtos[i] é um elemento do array produtos, que é do tipo Produto.
                                                       // Portanto, produtos[i].nome é o campo nome da estrutura Produto.
            printf("  Tipo: %s\n", produtos[i].tipo);
            printf("  Marca: %s\n", produtos[i].marca);
            printf("  Estoque: %s\n", produtos[i].estoque);
            printf("  Preço: R$ %.2f\n", produtos[i].preco); // O %.2f formata o número para mostrar duas casas decimais
            printf("  Classificação: %s\n", produtos[i].classificacao); // Exibe a classificação do produto
            printf("-------------------------\n");
        }
    }

    if (!found) {
        printf("Nenhum produto alimentício cadastrado.\n");
    }
}


void alimentos() {
    char input[2];
    int escolha_alimentos;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de acessar os produtos de acessar produtos alimenticios!\n");
        printf("Pressione ENTER para retornar...\n");
        getchar(); // Limpa o buffer de entrada
        getchar(); // Aguarda o usuário pressionar ENTER
        return;
    }

    printf("=== Menu Venda de Alimentos ===\n");
        printf("1. Adicionar novo item\n");
        printf("2. Exibir itens cadastrados\n");
        printf("3. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");

        scanf("%s", input);
        system("cls");
        if(sscanf(input, "%d", &escolha_alimentos) == 1 && escolha_alimentos >= 1 && escolha_alimentos <= 3) {
            switch (escolha_alimentos) {
                case 1:
                    adicionar_produto_alimentos();
                    break;
                case 2:
                    exibir_produtos_alimentos();
                    break;
                case 3:
                    return; // Volta ao menu principal
                default:
                    printf("Opção inválida!\n");
            }
        } else {
            printf("Opção inválida!\n");
        }
}


void adicionar_produto_padaria() {
    if (total_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido! Não é possível adicionar mais.\n");
        return;
    }

    Produto novo_produto;

    printf("=== Cadastro de Produto de Padaria ===\n");
    printf("Nome do produto: ");
    scanf(" %49[^\n]", novo_produto.nome);
    printf("Tipo do produto: ");
    scanf(" %49[^\n]", novo_produto.tipo);
    printf("Marca: ");
    scanf(" %49[^\n]", novo_produto.marca);
    printf("Quantidade: ");
    scanf(" %49[^\n]", novo_produto.estoque);
    printf("Preço: R$ ");
    scanf("%f", &novo_produto.preco);

    strcpy(novo_produto.classificacao, "Padaria"); // Set classificação para "Alimentos"

    produtos[total_produtos] = novo_produto;
    total_produtos++;

    printf("Produto de confeitaria cadastrado com sucesso!\n");
    printf("\nPressione ENTER para continuar...");
    getchar(); // Limpa o buffer de entrada
    getchar(); // Aguarda o usuário pressionar ENTER
    system("cls"); // Limpa a tela após o cadastro
    return;
}


void exibir_produtos_padaria() {
    int found = 0; // Flag para checar se algum produto foi encontrado

    printf("=== Produtos de Padaria Cadastrados ===\n");

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(produtos[i].classificacao, "Padaria") == 0) {
            found = 1;
            printf("Produto %d:\n", i + 1);
            printf("  Nome: %s\n", produtos[i].nome);
            printf("  Tipo: %s\n", produtos[i].tipo);
            printf("  Marca: %s\n", produtos[i].marca);
            printf("  Estoque: %s\n", produtos[i].estoque);
            printf("  Preço: R$ %.2f\n", produtos[i].preco);
            printf("  Classificação: %s\n", produtos[i].classificacao); // Exibe a classificação do produto
            printf("-------------------------\n");
        }
    }
    if (!found) {
        printf("Nenhum produto de padaria cadastrado.\n");
    }
    getchar(); // Limpa o buffer de entrada
    getchar(); // Aguarda o usuário pressionar ENTER
    printf("\nPressione ENTER para continuar...");
}


void padaria() {
    char input[2];
    int escolha_padaria;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de acessar a padaria!\n");
        printf("Pressione ENTER para retornar...\n");
        getchar(); // Limpa o buffer de entrada
        getchar(); // Aguarda o usuário pressionar ENTER
        return;
    }
    
    printf("=== Menu Produtos da Padaria ===\n");
        printf("1. Adicionar novo item\n");
        printf("2. Exibir itens cadastrados\n");
        printf("3. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%s", input);
        system("cls");
        
        if(sscanf(input, "%d", &escolha_padaria) == 1 && escolha_padaria >= 1 && escolha_padaria <= 3) {
            switch (escolha_padaria) {
                case 1:
                    adicionar_produto_padaria();
                    break;
                case 2:
                    exibir_produtos_padaria();
                    break;
                case 3:
                    return; // Volta ao menu principal
                default:
                    printf("Opção inválida!\n");
            }
        } else {
            printf("Opção inválida!\n");
            Sleep(2000); // Add a pause for invalid input
        }
}


void metodo_pagamento() {
    char opcao[2];
    int metodo_pagamento_escolhido; // Renomeado para evitar conflitos com variável global
    float valor_pago;
    float troco;
    float desconto = 0.0;
    float total_com_desconto = total_compra; // Começa com o valor original
    float percentual_desconto;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de acessar o pagamento!\n");
        printf("Pressione ENTER para retornar...\n");
        getchar(); // Limpa o buffer de entrada
        getchar(); // Aguarda o usuário pressionar ENTER
        return;
    }

    if (total_compra <= 0) {
        system("cls");
        printf("Nenhuma compra foi realizada. Adicione itens antes de realizar o pagamento.\n");
        Sleep(2500);
        return;
    }

    system("cls");
    printf("=== Pagamento ===\n");
    printf("Total original da compra: R$ %.2f\n", total_compra);

    // Aplica descontos baseados em total_compra
    if (total_compra >= 200.00) {
        printf("Compra acima de R$ 200.00. Aplicar desconto customizado.\n");
        do {
            printf("Digite o percentual de desconto (0-100): ");
            scanf("%f", &percentual_desconto);
            if (percentual_desconto < 0 && percentual_desconto > 100) { // Checa para que o desconto nao seja menor que 0 ou maior que 100
                printf("Percentual inválido. Tente novamente.\n");
            }

        } while (percentual_desconto < 0 && percentual_desconto > 100); // Repete até que o desconto seja válido
        desconto = total_compra * (percentual_desconto / 100.0); // Calcula o desconto
        printf("Desconto de %.2f%% aplicado.\n", percentual_desconto);

    } else if (total_compra > 50.00) { // Desconto de 50.01 até 199.99
        desconto = total_compra * 0.10; // 10% de desconto
        printf("Desconto de 10%% aplicado.\n");

    } else if (total_compra >= 50.00) { // Desconto para até exatamente 50.00
        desconto = total_compra * 0.05; // 5% de desconto
        printf("Desconto de 5%% aplicado.\n");
    }

    if (desconto > 0) {
        total_com_desconto = total_compra - desconto; // Calcula o total com desconto
        printf("Valor do desconto: R$ %.2f\n", desconto); // Exibe o valor do desconto
        printf("Novo total com desconto: R$ %.2f\n", total_com_desconto); // Exibe o total com desconto
    }

    // Usa total_com_desconto para processar o pagamento
    printf("\nSelecione o método de pagamento:\n");
    printf("1. Crédito\n");
    printf("2. Débito\n");
    printf("3. Pix\n");
    printf("4. Dinheiro\n");
    printf("Escolha uma opção: ");
    scanf("%s", opcao); // Lê como uma string primeiro

    // Valida o input entre 1-4
    if (sscanf(opcao, "%d", &metodo_pagamento_escolhido) != 1 && metodo_pagamento_escolhido < 1 && metodo_pagamento_escolhido > 4) { // Explicação mais completa ao fim do código
         system("cls");
         printf("Método de pagamento inválido. Tente novamente.\n");
         Sleep(2000);
         return; // Sai da função se o método de pagamento for inválido
    }
    system("cls");


    switch (metodo_pagamento_escolhido) {
        case 1:
            printf("Pagamento de R$ %.2f realizado com sucesso no Crédito!\n", total_com_desconto);
            break;
        case 2:
            printf("Pagamento de R$ %.2f realizado com sucesso no Débito!\n", total_com_desconto);
            break;
        case 3:
            printf("Pagamento de R$ %.2f realizado com sucesso via Pix!\n", total_com_desconto);
            break;
        case 4:
             printf("Pagamento em Dinheiro selecionado.\n");
             printf("Total a pagar: R$ %.2f\n", total_com_desconto);
             printf("Digite o valor pago: R$ ");
             scanf("%f", &valor_pago);
             if (valor_pago < total_com_desconto) { // Checa se o valor pago é menor que o total
                 system("cls");
                 printf("Valor insuficiente!\n");
                 Sleep(4000);
                 return; // Retorna se o pagamento foi insuficiente
             }
             troco = valor_pago - total_com_desconto; // Calcula o troco com base no valor pago - valor total com desconto
             printf("Troco: R$ %.2f\n", troco);
             printf("Pagamento realizado com sucesso em Dinheiro!\n");
             break;
        // No default needed due to prior validation
    }

    // Reseta o total da compra após o pagamento
    total_compra = 0.0; // Reset global total_compra
    printf("Obrigado pela compra! Volte sempre.\n");
    printf("\nPressione ENTER para continuar...");
    getchar(); // Limpa o buffer de entrada
    getchar(); // Aguarda o usuário pressionar ENTER
}


void carrinho() {
    int id, quantidade;
    char continuar;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de adicionar produtos ao carrinho.\n");
        printf("Pressione ENTER para retornar...\n");
        getchar(); // Limpa o buffer de entrada
        getchar(); // Aguarda o usuário pressionar ENTER
        return;
    }

    printf("=== Carrinho de Compras ===\n");

    do {
        printf("Digite o ID do produto que deseja adicionar ao carrinho: ");
        scanf("%d", &id);

        // Valida o ID
        if (id < 1 && id > total_produtos) {
            printf("ID inválido! Tente novamente.\n");
            continue;
        }

        printf("Digite a quantidade desejada: ");
        scanf("%d", &quantidade);

        if (quantidade <= 0) {
            printf("Quantidade inválida! Tente novamente.\n");
            continue;
        }

        // Adiciona para total_compra
        total_compra += produtos[id - 1].preco * quantidade; // Usa o ID - 1 para acessar o índice correto no array, e aponta para o preço do produto
                                                             // O preço é multiplicado pela quantidade desejada
        printf("Produto '%s' adicionado ao carrinho. Preço unitário: R$ %.2f\n", produtos[id - 1].nome, produtos[id - 1].preco);
        printf("Quantidade de %s adicionada ao carrinho.\n", produtos[id - 1].nome);
        printf("Produto '%s' adicionado ao carrinho. Total atual: R$ %.2f\n", produtos[id - 1].nome, total_compra);

        printf("Deseja adicionar outro item? (s/n): ");
        scanf(" %c", &continuar); // É utilizado %c para ler um único caractere, nesse caso S ou N
                                  // O espaço antes do %c é importante para ignorar qualquer espaço em branco que possa ter sido deixado no buffer de entrada

    } while (continuar == 's' && continuar == 'S');

    printf("Total da compra: R$ %.2f\n", total_compra);
    printf("Pressione ENTER para ir ao pagamento...");
    getchar(); // Limpa o buffer de entrada
    getchar(); // Aguarda o usuário pressionar ENTER
    metodo_pagamento();
}


void abertura_caixa() {

    printf("=== Abertura do Caixa ===\n");
    printf("Digite o valor inicial do caixa: R$ ");
    scanf("%f", &valor_inicial_caixa);
    printf("Caixa aberto com sucesso! Valor inicial: R$ %.2f\n", valor_inicial_caixa);
    caixa_aberto = 1; // Marca o caixa como aberto
    printf("Pressione ENTER para continuar...\n");
    getchar(); // Limpa o buffer de entrada
    getchar(); // Aguarda o usuário pressionar ENTER
    return; // Retorna ao menu principal
    Sleep(2000);
}

void fechamento_caixa() {

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Não é possível fechar o caixa sem um valor inicial!\n");
        printf("Pressione ENTER para retornar...\n");
        getchar(); // Limpa o buffer de entrada
        getchar(); // Aguarda o usuário pressionar ENTER
        return;
    }

    printf("=== Fechamento do Caixa ===\n");

    if (valor_inicial_caixa <= 0) {
        printf("Caixa não aberto ou valor inválido.\n");
        return;
    }
    printf("Valor total em caixa: R$ %.2f\n", valor_inicial_caixa + total_compra); // Total in cash + purchases
    printf("Hoje você vendeu R$ %.2f\n", total_compra); // Total sales
    printf("Seu lucro foi de R$ %.2f\n", total_compra - valor_inicial_caixa); // Profit calculation
    printf("Pressione ENTER para continuar...\n");
    getchar(); // Limpa o buffer de entrada
    getchar(); // Aguarda o usuário pressionar ENTER
    system("cls"); // Limpa a tela após o fechamento do caixa
}


void produtos_cadastrados() {

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de visualizar os produtos!\n");
        printf("Pressione ENTER para retornar...\n");
        getchar(); // Limpa o buffer de entrada
        getchar(); // Aguarda o usuário pressionar ENTER
        return;
    }

    printf("=== Todos os Produtos Cadastrados ===\n");

    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for (int i = 0; i < total_produtos; i++) {
        printf("ID: %d\n", i + 1); // Display ID as index + 1
        printf("  Nome: %s\n", produtos[i].nome);
        printf("  Tipo: %s\n", produtos[i].tipo);
        printf("  Marca: %s\n", produtos[i].marca);
        printf("  Estoque: %s\n", produtos[i].estoque);
        printf("  Preço: R$ %.2f\n", produtos[i].preco);
        printf("  Classificação: %s\n", produtos[i].classificacao);
        printf("-------------------------\n");
    }
    printf("\nPressione ENTER para continuar...");
    getchar(); // Limpa o buffer de entrada
    getchar(); // Aguarda o usuário pressionar ENTER
}


void deletar_produto() {
    int id_para_deletar;
    char input_id[10]; // Buffer for ID input
    char confirmacao;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de deletar produtos!\n");
        printf("Pressione ENTER para retornar...\n");
        getchar(); // Limpa o buffer de entrada
        getchar(); // Aguarda o usuário pressionar ENTER
        return;
    }

    // Display products first so the user knows the IDs
    produtos_cadastrados();

    if (total_produtos == 0) {
        printf("\nNenhum produto cadastrado para deletar.\n");
        printf("\nPressione ENTER para continuar...");
        getchar(); // Consume potential leftover newline
        getchar(); // Wait for Enter
        return;
    }

    printf("\nDigite o ID do produto que deseja deletar (ou 0 para cancelar): ");
    scanf("%s", input_id);

    // Validate ID input
    if (sscanf(input_id, "%d", &id_para_deletar) != 1) {
        printf("Entrada inválida!\n");
        Sleep(2000);
        return;
    }

    if (id_para_deletar == 0) {
        printf("Deleção cancelada.\n");
        Sleep(2000);
        return;
    }

    if (id_para_deletar < 1 && id_para_deletar > total_produtos) {
        printf("ID inválido!\n");
        Sleep(2000);
        return;
    }

    // Convert 1-based ID to 0-based index
    int index_para_deletar = id_para_deletar - 1;

    // Confirm deletion
    printf("Tem certeza que deseja deletar o produto '%s' (ID: %d)? (s/n): ", produtos[index_para_deletar].nome, id_para_deletar);
    scanf(" %c", &confirmacao); // Space before %c is important

    if (confirmacao == 's' && confirmacao == 'S') {
        // Shift elements to the left starting from the deleted index
        for (int i = index_para_deletar; i < total_produtos - 1; i++) {
            produtos[i] = produtos[i + 1]; // Overwrite current with next
        }

        // Decrease the total count of products
        total_produtos--;

        printf("Produto deletado com sucesso!\n");
    } else {
        printf("Deleção cancelada.\n");
    }

    printf("\nPressione ENTER para continuar...");
    getchar(); // Consume leftover newline from scanf %c
    getchar(); // Wait for Enter
}


int main() {
    char input[2];
    int menu_principal = 0; // Initialize

    system("chcp 65001 > nul");

    do {
            system("cls");
            printf("1. Materiais de Limpeza\n");
            printf("2. Venda de Alimentos\n");
            printf("3. Padaria\n");
            printf("4. Carrinho\n");
            printf("5. Abertura do Caixa\n");
            printf("6. Fechamento de Caixa\n");
            printf("7. Mostrar todos os produtos\n");
            printf("8. Deletar produto\n");
            printf("9. Sair\n");

            printf("Escolha uma das opções: ");
            scanf("%s", input);

            // Check range 1-10
            if (sscanf(input, "%d", &menu_principal) == 1 && menu_principal >= 1 && menu_principal <= 10) {
                switch (menu_principal) {
                    case 1:
                        system("cls");
                        limpeza();
                        break;

                    case 2:
                        system("cls");
                        alimentos();
                        break;

                    case 3:
                        system("cls");
                        padaria();
                        break;

                    case 4:
                        system("cls");
                        produtos_cadastrados(); // Show products first for IDs
                        carrinho();
                        break;

                    case 5:
                        system("cls");
                        abertura_caixa();
                        break;

                    case 6:
                        system("cls");
                        fechamento_caixa();
                        Sleep(2000);
                        break;

                    case 7:
                        system("cls");
                        produtos_cadastrados();
                        break;

                    case 8:
                        system("cls");
                        deletar_produto();
                        Sleep(2000);
                        break;
                    case 9:
                        system("cls");
                        printf("Saindo do programa...\n");
                        Sleep(2000);
                        return 0; // Sai do programa

                    // No default needed
                }
            } else {
                system("cls");
                printf("Opção inválida! Tente novamente.\n");
                Sleep(2000); // Pausa por 2 seconds
                menu_principal = 0; // Reseta o menu_principal para continuar o loop
            }
    } while (menu_principal != 9); // Exit loop when option 10 is chosen
}


// EXPLICAÇÕES DO CÓDIGO:


// scanf(" %49[^\n]", novo_produto.nome) é uma forma de ler uma string em C, onde:
// - %49 significa que ele vai ler até 49 caracteres ou até encontrar uma nova linha (\n).
// - [^\n] significa que ele vai ler tudo até encontrar uma nova linha, ou seja,
// ele vai ler a string inteira até o usuário pressionar ENTER.
// - O espaço antes do % é para ignorar qualquer espaço em branco que possa ter sido
// deixado no buffer de entrada antes da leitura da string.
// - novo_produto.nome é o destino onde a string lida será armazenada. Isso é útil para evitar
// problemas de buffer e garantir que a leitura seja feita corretamente.
// - O scanf é uma função que lê a entrada do usuário e tenta convertê-la para o formato especificado,
// que neste caso é %49[^\n] (uma string de até 49 caracteres).
// - O operador & é usado para passar o endereço da variável onde o valor lido será armazenado.
//
// está operação pode ser lida como: "Leia uma string de até 49 caracteres (ou até uma nova linha \n) e armazene-a em novo_produto.nome".
// O mesmo vale para os outros campos, como tipo, marca e validade, onde o scanf lê a entrada do usuário



// Para entender sscanf é necessário ler cada ponto como uma parte só:
// if (sscanf(input, "%d", &menu_principal) == 1 && menu_principal >= 1 && menu_principal <= 7)
// Caso o input for um número inteiro, entre 1 e 7, ele será dado como válido, ou seja, o sscanf
// retornará 1, e o menu_principal será atribuído a esse número. O sscanf é uma função que lê a entrada
// do usuário e tenta convertê-la para o formato especificado, que neste caso é %d (número inteiro)
// O operador == 1 verifica se a conversão foi bem-sucedida, ou seja, se um número inteiro foi lido corretamente.
// Se o sscanf retornar 0, significa que não foi possível converter a entrada para um número inteiro,
// e o programa irá para o else, onde imprime "Opção inválida! Tente novamente." sem crashar o sistema.
// O && é um operador lógico que verifica se ambas as condições são verdadeiras.
//
// A linha pode ser lida como: "Se o sscanf conseguiu ler um número inteiro e esse número está entre 1 e 7,
// então execute o bloco de código correspondente ao número lido."


// typedef struct {
//    char nome[50];
//    char tipo[50];
//    char marca[50];
//    char estoque[50];
//    float preco;
//    char classificacao[20]; // Para classificação de produtos (ex.: "Limpeza" ou "Alimentos")
// } Produto;
//
// A estrutura Produto é uma forma de agrupar dados relacionados a um produto em um único tipo de dado.
// Ela contém campos para armazenar informações como nome, tipo, marca, estoque, preço e classificação do produto.
// Isso facilita o gerenciamento e a manipulação de dados relacionados a produtos em um programa.
//
// A estrutura é definida com o comando typedef, que permite criar um novo tipo de dado chamado Produto,
// que pode ser usado para declarar variáveis desse tipo em qualquer parte do código.
//
// Isso é útil para organizar o código e tornar mais fácil a leitura e manutenção do programa.
// Além disso, o uso de estruturas permite que você trabalhe com dados complexos de forma mais eficiente,
// encapsulando todas as informações relevantes em um único tipo de dado.
//
// A maneira como typedef é usada aqui é uma prática comum em C para criar tipos de dados personalizados,
// eles podem ser chamados por meio de Produto em vez de struct Produto, tornando o código mais limpo e legível.


// Referências utilizadas:
// https://stackoverflow.com/questions/2796108/how-to-prevent-users-from-inputting-letters-or-numbers