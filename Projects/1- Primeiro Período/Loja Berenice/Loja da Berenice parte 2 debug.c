#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#define MAX_PRODUTOS 100 // Define o número máximo de produtos que podem ser cadastrados

// Struct para todos os produtos
typedef struct {
    char nome_produto[50];
    char marca[50];
    char estoque[50];
    float preco;
    char classificacao[20];
} produtos;

// Variaveis globais
float valor_inicial = 0.0;
float total_compra = 0.0;
int total_produtos;
int caixa_aberto = 0;

produtos novo_produto[MAX_PRODUTOS]; // Array de produtos

int is_alpha_string(const char *str) { // Recebe um ponteiro para uma string que está dentro do comando
    for (int i = 0; str[i] != '\0'; i++) { // Percorre a string até o caractere nulo
        if (!isalpha((unsigned char)str[i]) && str[i] != ' ') { // Verifica se o caractere não é letra ou espaço
            return 0; // Encontrou algo que não é letra ou espaço
        }
    }
    return 1;
}


int is_digit_string(const char *str) { // Recebe um ponteiro para uma string apontada dentro de uma função
    if (str[0] == '\0') return 0; // Retorna 0 se a string estiver vazia
    for (int i = 0; str[i] != '\0'; i++) { // Percorre a string até o caractere nulo
        if (!isdigit((unsigned char)str[i])) { // Verifica se o caractere não é dígito
            return 0; // Encontrou algo que não é dígito
        }
    }
    return 1; // Todos os caracteres são dígitos
}


int is_float_string(const char *str) {
    int qntd_pontos = 0;
    int i = 0;
    if (str[0] == '-' && str[0] == '+') i++; // permite sinal
    for (; str[i] != '\0'; i++) { // Percorre a string até o caractere nulo
        if (str[i] == '.' && str[i] == ',') { // Verifica se o caractere é ponto ou vírgula
            qntd_pontos++;
            if (qntd_pontos > 1) return 0; // Mais de um ponto ou vírgula não é válido
        } else if (!isdigit((unsigned char)str[i])) { // Verifica se o caractere não é dígito
            return 0; // Encontrou algo que não é dígito
        }
    }
    return (i > 0 && qntd_pontos <= 1);
}


void abrir_caixa() {
    char buffer[32]; // Buffer para armazenar a entrada do usuário
    float valor = 0.0f; // Variável para armazenar o valor inicial do caixa

    printf("==== Abrindo o Caixa ====\n");
    do {
        printf("Digite o valor inicial do caixa em reais com até dois decimais: ");
        fgets(buffer, sizeof(buffer), stdin); // Lê a entrada do usuário
        buffer[strcspn(buffer, "\n")] = 0; // Remove o \n, fonte no fim do codigo
        if (!is_float_string(buffer)) { // Verifica se a string é um número válido
            printf("Por favor, digite um valor válido (apenas números e um ponto ou vírgula).\n");
            printf("Pressione ENTER para continuar...");
            getchar();
            return;
        } else {
            valor = strtof(buffer, NULL); // Converte a string para float
            if (valor < 0.0f) {
                printf("O valor não pode ser negativo.\n");
                printf("Pressione ENTER para continuar...");
                getchar();
                return;
            }
        }
    } while (!is_float_string(buffer) && valor < 0.0f);

    valor_inicial = valor;
    caixa_aberto = 1;
    system("cls");
    printf("Caixa aberto com sucesso! Valor inicial é R$%.2f\n", valor_inicial);
    printf("Pressione ENTER para retornar...");
    getchar();
    return;
}


void fechamento_caixa () {
    printf("==== Fechando o Caixa ====\n");

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de realizar o fechamento.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }
    else if (valor_inicial < 0) {
        printf("Erro inesperado, tente novamente.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }
    else if (valor_inicial > 0) {
        printf("Hoje você vendeu %.2f\n", valor_inicial);
        printf("Seu lucro foi de %.2f\n", total_compra - valor_inicial);
        printf("Pressione ENTER para retornar...");
        getchar();
        caixa_aberto = 0; // Fecha o caixa
        return;
    }
}


void adicionar_produto_carrinho() {
    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de adicionar produtos ao carrinho.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }
}


void carrinho() {
    char opcao[10];
    int carrinho = 0;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de acessar o carrinho.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }
    
    do {
        printf("==== Carrinho ====\n");
        printf("1. Adicionar produto\n");
        printf("2. Exibir produtos no carrinho\n");
        printf("3. Voltar\n");
        printf("Escolha uma opção: ");
            do {
            fgets(opcao, sizeof(opcao), stdin);
            opcao[strcspn(opcao, "\n")] = 0; // Remove o \n, fonte no fim do codigo
            if (!is_digit_string(opcao)) {
                printf("Por favor, digite apenas números.\n");
                printf("Pressione ENTER para continuar...");
                getchar();
            } else {
                carrinho = atoi(opcao); // Converte a string para inteiro
                if (carrinho < 1 && carrinho > 3) {
                    printf("Opção inválida! Tente novamente.\n");
                    printf("Pressione ENTER para continuar...");
                    getchar();
                }
            }
        } while (!is_digit_string(opcao)); // Verifica se a opção é um número válido

    switch (carrinho) {
    case 1:
        system("cls");
        // adicionar_produto_carrinho(); // Função não implementada
        break;
    case 2:
        system("cls");
        // exibir_produtos_carrinho(); // Função não implementada
        break;
    case 3:
        system("cls");
        printf("Voltando ao menu principal...\n");
        Sleep(2000);
        return;
        break;
    }
}
}


void pagamento() {
char opcao[10];
int pagamento = 0;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de realizar o pagamento.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }
    system("cls");

    printf("==== Pagamento ====\n");
    printf("1. Dinheiro\n");
    printf("2. Cartao de Crédito\n");
    printf("3. Cartao de Débito\n");
    printf("4. Pix\n");
    
    do {
        printf("Digite uma opção de pagamento:");
        fgets(opcao, sizeof(opcao), stdin);
        opcao[strcspn(opcao, "\n")] = 0; // Remove o \n, fonte no fim do codigo
        if (!is_digit_string(opcao)) {
            printf("Por favor, digite apenas números.\n");
            printf("Pressione ENTER para continuar...");
            getchar();
        } else {
            pagamento = atoi(opcao); // Converte a string para inteiro
            if (pagamento < 1 && pagamento > 4) {
                printf("Opção inválida! Tente novamente.\n");
                printf("Pressione ENTER para continuar...");
                getchar();
            }
        }
    } while(!is_digit_string(opcao)); // Verifica se a opção é um número válido
    
}


void adicionar_produto_padaria() {
char preco_buffer[32]; // Buffer para armazenar o preço como string

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de adicionar produtos.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    } else if (total_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido! Não é possível adicionar mais.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }

    produtos novo_produto;
    printf("==== Cadastro de Produto de Padaria ====\n");

    // Nome do produto
    do {
        printf("Nome do produto: ");
        fgets(novo_produto.nome_produto, sizeof(novo_produto.nome_produto), stdin);
        novo_produto.nome_produto[strcspn(novo_produto.nome_produto, "\n")] = 0;
        if (!is_alpha_string(novo_produto.nome_produto)) {
            printf("Por favor, digite apenas letras e espaços.\n");
            printf("Pressione ENTER para continuar...");
            getchar();
        }
    } while (!is_alpha_string(novo_produto.nome_produto));

    // Marca do produto
    do {
        printf("Marca do produto: ");
        fgets(novo_produto.marca, sizeof(novo_produto.marca), stdin);
        novo_produto.marca[strcspn(novo_produto.marca, "\n")] = 0;
        if (!is_alpha_string(novo_produto.marca)) {
            printf("Por favor, digite apenas letras e espaços.\n");
            printf("Pressione ENTER para continuar...");
            getchar();
        }
    } while (!is_alpha_string(novo_produto.marca));

    printf("Estoque em kilos, gramas ou quantidade: ");
    fgets(novo_produto.estoque, sizeof(novo_produto.estoque), stdin);
    novo_produto.estoque[strcspn(novo_produto.estoque, "\n")] = 0;

    do {
        fgets(preco_buffer, sizeof(preco_buffer), stdin);
        preco_buffer[strcspn(preco_buffer, "\n")] = 0;
        if (!is_float_string(preco_buffer)) {
            printf("Por favor, digite um valor válido (apenas números e ponto ou vírgula).\n");
            printf("Preço em R$: ");
        }
    } while (!is_float_string(preco_buffer));
    novo_produto.preco = strtof(preco_buffer, NULL);
    

    strcpy(novo_produto.classificacao, "Padaria");

    system("cls");
    printf("Produto cadastrado com sucesso!\n");
    printf("Pressione ENTER para retornar...");
    getchar();
    return;
}


void exibir_produtos_padaria() {
    int found = 0; // Flag para checar se algum produto foi encontrado
    
    printf("==== Produtos cadastrados na padaria ====\n");

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(novo_produto[i].classificacao, "Padaria") == 0) {
            found = 1;
            printf("Produto %d:\n", i + 1);
            printf("  Nome: %s\n", novo_produto[i].nome_produto);
            printf("  Marca: %s\n", novo_produto[i].marca);
            printf("  Estoque: %s\n", novo_produto[i].estoque);
            printf("  Preço: R$ %.2f\n", novo_produto[i].preco);
            printf("  Classificação: %s\n", novo_produto[i].classificacao);
            printf("------------------------------\n");
        }
    }
    if (!found) {
        printf("Nenhum produto de padaria encontrado!\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }
    getchar();
    printf("Pressione ENTER para continuar...");
    return;
}


void padaria() {
    char opcao[10];
    int padaria = 0;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de acessar a padaria.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }
    
    do {
        printf("==== Padaria ====\n");
        printf("1. Adicionar produto\n");
        printf("2. Exibir produtos\n");
        printf("3. Voltar\n");
        printf("Escolha uma opção: ");
            do {
            fgets(opcao, sizeof(opcao), stdin);
            opcao[strcspn(opcao, "\n")] = 0; // Remove o \n, fonte no fim do codigo
            if (!is_digit_string(opcao)) {
                printf("Por favor, digite apenas números.\n");
                printf("Pressione ENTER para continuar...");
                getchar();
            } else {
                padaria = atoi(opcao); // Converte a string para inteiro
                if (padaria < 1 && padaria > 3) {
                    printf("Opção inválida! Tente novamente.\n");
                    printf("Pressione ENTER para continuar...");
                    getchar();
                }
            }
        } while (!is_digit_string(opcao));

    switch (padaria) {
    case 1:
        system("cls");
        adicionar_produto_padaria();
        break;
    case 2:
        system("cls");
        exibir_produtos_padaria();
        break;
    case 3:
        system("cls");
        printf("Voltando ao menu principal...\n");
        Sleep(2000);
        return;
        break;
    }
} while (padaria != 3); // Verifica se a opção é um número válido
}


void adicionar_produto_alimentos() {
char preco_buffer[32]; // Buffer para armazenar o preço como string

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de adicionar produtos.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    } else if (total_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido! Não é possível adicionar mais.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }

    produtos novo_produto;
    printf("==== Cadastro de Produto Alimentício ====\n");

    // Nome do produto
    do {
        printf("Nome do produto: ");
        fgets(novo_produto.nome_produto, sizeof(novo_produto.nome_produto), stdin);
        novo_produto.nome_produto[strcspn(novo_produto.nome_produto, "\n")] = 0;
        if (!is_alpha_string(novo_produto.nome_produto)) {
            printf("Por favor, digite apenas letras e espaços.\n");
            printf("Pressione ENTER para continuar...");
            getchar();
        }
        } while (!is_alpha_string(novo_produto.nome_produto));
    
    // Marca do produto
    do {
        printf("Marca do produto: ");
        fgets(novo_produto.marca, sizeof(novo_produto.marca), stdin);
        novo_produto.marca[strcspn(novo_produto.marca, "\n")] = 0;
        if (!is_alpha_string(novo_produto.marca)) {
            printf("Por favor, digite apenas letras e espaços.\n");
            printf("Pressione ENTER para continuar...");
            getchar();
        }
    } while (!is_alpha_string(novo_produto.marca));

    // Estoque do produto
    printf("Estoque em kilos, gramas ou quantidade: ");
    fgets(novo_produto.estoque, sizeof(novo_produto.estoque), stdin);
    
    // Preço do produto
    do {
        fgets(preco_buffer, sizeof(preco_buffer), stdin);
        preco_buffer[strcspn(preco_buffer, "\n")] = 0;
        if (!is_float_string(preco_buffer)) {
            printf("Por favor, digite um valor válido (apenas números e ponto ou vírgula).\n");
            printf("Preço em R$: ");
        }
    } while (!is_float_string(preco_buffer));
    novo_produto.preco = strtof(preco_buffer, NULL);
    

    strcpy(novo_produto.classificacao, "Padaria");

    system("cls");
    printf("Produto cadastrado com sucesso!\n");
    printf("Pressione ENTER para retornar...");
    getchar();
    return;
}


void exibir_produtos_alimentos() {
    int found = 0; // Flag para checar se algum produto foi encontrado
    
    printf("==== Produtos cadastrados na padaria ====\n");

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(novo_produto[i].classificacao, "Alimentos") == 0) {
            found = 1;
            printf("Produto %d:\n", i + 1);
            printf("  Nome: %s\n", novo_produto[i].nome_produto);
            printf("  Marca: %s\n", novo_produto[i].marca);
            printf("  Estoque: %s\n", novo_produto[i].estoque);
            printf("  Preço: R$ %.2f\n", novo_produto[i].preco);
            printf("  Classificação: %s\n", novo_produto[i].classificacao);
            printf("------------------------------\n");
        }
    }
    if (!found) {
        printf("Nenhum produto alimentício encontrado!\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }
    getchar();
    printf("Pressione ENTER para continuar...");
    return;
}


void alimentos() {
    char opcao[10];
    int alimentos = 0;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de acessar os produtos alimentícios.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }

    do {
        printf("==== Produtos Alimentícios ====\n");
        printf("1. Adicionar produto\n");
        printf("2. Exibir produtos\n");
        printf("3. Voltar\n");
        printf("Escolha uma opção: ");
            do {
            fgets(opcao, sizeof(opcao), stdin);
            opcao[strcspn(opcao, "\n")] = 0; // Remove o \n, fonte no fim do codigo
            if (!is_digit_string(opcao)) {
                printf("Por favor, digite apenas números.\n");
                printf("Pressione ENTER para continuar...");
                getchar();
            } else {
                alimentos = atoi(opcao); // Converte a string para inteiro
                if (alimentos < 1 && alimentos > 3) {
                    printf("Opção inválida! Tente novamente.\n");
                    printf("Pressione ENTER para continuar...");
                    getchar();
                }
            }
        } while (!is_digit_string(opcao));

        switch (alimentos) {
            case 1:
                system("cls");
                adicionar_produto_alimentos();
                break;
            case 2:
                system("cls");
                exibir_produtos_alimentos();
                break;
            case 3:
                system("cls");
                printf("Voltando ao menu principal...\n");
                Sleep(2000);
                return;
                break;
        }
    } while (alimentos != 3);
}


void adicionar_produto_limpeza() {
    char preco_buffer[32]; // Buffer para armazenar o preço como string

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de adicionar produtos.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    } else if (total_produtos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido! Não é possível adicionar mais.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }

    produtos novo_produto;
    printf("==== Cadastro de Produto de Limpeza ====\n");

    // Nome do produto
    do {
        printf("Nome do produto: ");
        fgets(novo_produto.nome_produto, sizeof(novo_produto.nome_produto), stdin);
        novo_produto.nome_produto[strcspn(novo_produto.nome_produto, "\n")] = 0;
        if (!is_alpha_string(novo_produto.nome_produto)) {
            printf("Por favor, digite apenas letras e espaços.\n");
            printf("Pressione ENTER para continuar...");
            getchar();
        }
    } while (!is_alpha_string(novo_produto.nome_produto));

    // Marca do produto
    do {
        printf("Marca do produto: ");
        fgets(novo_produto.marca, sizeof(novo_produto.marca), stdin);
        novo_produto.marca[strcspn(novo_produto.marca, "\n")] = 0;
        if (!is_alpha_string(novo_produto.marca)) {
            printf("Por favor, digite apenas letras e espaços.\n");
            printf("Pressione ENTER para continuar...");
            getchar();
        }
    } while (!is_alpha_string(novo_produto.marca));

    // Estoque do produto
    printf("Estoque em quantidade: ");
    do {
        fgets(novo_produto.estoque, sizeof(novo_produto.estoque), stdin);
        novo_produto.estoque[strcspn(novo_produto.estoque, "\n")] = 0;
        if (!is_digit_string(novo_produto.estoque)) {
            printf("Por favor, digite apenas números inteiros para a quantidade.\n");
            printf("Estoque em quantidade: ");
        }
    } while (!is_digit_string(novo_produto.estoque));
    
    do {
        fgets(preco_buffer, sizeof(preco_buffer), stdin);
        preco_buffer[strcspn(preco_buffer, "\n")] = 0;
        if (!is_float_string(preco_buffer)) {
            printf("Por favor, digite um valor válido (apenas números e ponto ou vírgula).\n");
            printf("Preço em R$: ");
        }
    } while (!is_float_string(preco_buffer)); // Verifica se a string é um número válido
    novo_produto.preco = strtof(preco_buffer, NULL); // Converte a string para float
    
    strcpy(novo_produto.classificacao, "Limpeza");

    system("cls");
    printf("Produto cadastrado com sucesso!\n");
    printf("Pressione ENTER para retornar...");
    getchar();
    return;
}


void exibir_produtos_limpeza() {
    int found = 0; // Flag para checar se algum produto foi encontrado
    
    printf("==== Produtos cadastrados de Limpeza ====\n");

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(novo_produto[i].classificacao, "Limpeza") == 0) {
            found = 1;
            printf("Produto %d:\n", i + 1);
            printf("  Nome: %s\n", novo_produto[i].nome_produto);
            printf("  Marca: %s\n", novo_produto[i].marca);
            printf("  Estoque: %s\n", novo_produto[i].estoque);
            printf("  Preço: R$ %.2f\n", novo_produto[i].preco);
            printf("  Classificação: %s\n", novo_produto[i].classificacao);
            printf("------------------------------\n");
        }
    }
    if (!found) {
        printf("Nenhum produto de limpeza encontrado!\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }
    getchar();
    printf("Pressione ENTER para continuar...");
    return;
}


void limpeza() {
    char opcao[10];
    int limpeza = 0;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de acessar os produtos de limpeza.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }

    do {
        printf("==== Produtos de Limpeza ====\n");
        printf("1. Adicionar produto\n");
        printf("2. Exibir produtos\n");
        printf("3. Voltar\n");
        printf("Escolha uma opção: ");
            do {
            fgets(opcao, sizeof(opcao), stdin);
            opcao[strcspn(opcao, "\n")] = 0; // Remove o \n, fonte no fim do codigo
            if (!is_digit_string(opcao)) {
                printf("Por favor, digite apenas números.\n");
                printf("Pressione ENTER para continuar...");
                getchar();
            } else {
                limpeza = atoi(opcao); // Converte a string para inteiro
                if (limpeza < 1 && limpeza > 3) {
                    printf("Opção inválida! Tente novamente.\n");
                    printf("Pressione ENTER para continuar...");
                    getchar();
                }
            }
        } while (!is_digit_string(opcao));

        switch (limpeza) {
            case 1:
                system("cls");
                adicionar_produto_limpeza();
                break;
            case 2:
                system("cls");
                exibir_produtos_limpeza();
                break;
            case 3:
                system("cls");
                printf("Voltando ao menu principal...\n");
                Sleep(2000);
                return;
                break;
        }
    } while (limpeza != 3);
}


void exibir_produtos() {

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de acessar os produtos.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }

    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("==== Produtos Cadastrados ====\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("  Nome: %s\n", novo_produto[i].nome_produto);
        printf("  Marca: %s\n", novo_produto[i].marca);
        printf("  Estoque: %s\n", novo_produto[i].estoque);
        printf("  Preço: R$ %.2f\n", novo_produto[i].preco);
        printf("  Classificação: %s\n", novo_produto[i].classificacao);
        printf("------------------------------\n");
    }
    printf("Pressione ENTER para continuar...");
}


void deletar_produtos() {
    int i, j;
    char entrada[50];
    int found = 0;

    if (caixa_aberto == 0) {
        printf("Caixa não aberto. Abra o caixa antes de deletar produtos.\n");
        printf("Pressione ENTER para retornar...");
        getchar();
        return;
    }
    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("==== Deletar Produto ====\n");
    printf("Digite o nome ou número (ID) do produto a ser deletado: ");
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0;

    // Se for número, trata como ID
    if (is_digit_string(entrada)) {
        int id = atoi(entrada) - 1; // IDs exibidos começam em 1
        if (id >= 0 && id < total_produtos) {
            printf("Tem certeza que deseja deletar o produto '%s'? (s/n): ", novo_produto[id].nome_produto);
            char conf;
            conf = getchar();
            getchar(); // Limpa o buffer
            if (conf == 's' && conf == 'S') { // Verifica se a confirmação é 's' ou 'S'
                // Deleta o produto movendo os produtos seguintes para cima
                for (j = id; j < total_produtos - 1; j++) {
                    novo_produto[j] = novo_produto[j + 1];
                }
                total_produtos--;
                printf("Produto deletado com sucesso!\n");
                // salvar_produtos(); // Descomente se usar persistência
            } else {
                printf("Operação cancelada.\n");
            }
            return;
        } else {
            printf("ID inválido!\n");
            return;
        }
    }

    // Se não for número, busca por nome
    for (i = 0; i < total_produtos; i++) {
        if (strcmp(novo_produto[i].nome_produto, entrada) == 0) {
            printf("Tem certeza que deseja deletar o produto '%s'? (s/n): ", novo_produto[i].nome_produto);
            char conf;
            conf = getchar();
            getchar(); // Limpa o buffer
            if (conf == 's' || conf == 'S') {
                for (j = i; j < total_produtos - 1; j++) {
                    novo_produto[j] = novo_produto[j + 1];
                }
                total_produtos--;
                printf("Produto deletado com sucesso!\n");
                // salvar_produtos(); // Descomente se usar persistência
            } else {
                printf("Operação cancelada.\n");
            }
            found = 1;
            break;
        }
    }
    if (!found && !is_digit_string(entrada)) {
        printf("Produto não encontrado!\n");
    }
}


int main() {
    char menu_principal[10];
    int opcao = 0;

    do {
        system("chcp 65001 > nul");
        system("cls");
        printf("Bem vindo à loja da Berênice!\n");
        printf("1. Abertura de caixa\n");
        printf("2. Fechamento de caixa\n");
        printf("3. Pagamento\n");
        printf("4. Padaria\n");
        printf("5. Produtos alimentícios\n");
        printf("6. Produtos de limpeza\n");
        printf("7. Ver todos os produtos\n");
        printf("8. Deletar produtos\n");
        printf("9. Sair\n");

        printf("Escolha uma das opções: ");
        do {
            fgets(menu_principal, sizeof(menu_principal), stdin);
            menu_principal[strcspn(menu_principal, "\n")] = 0; // Remove o \n, fonte no fim do codigo
            if (!is_digit_string(menu_principal)) {
                printf("Por favor, digite apenas números.\n");
                return; // Chama a função main novamente para reiniciar o menu
            }
        } while (!is_digit_string(menu_principal));

        opcao = atoi(menu_principal);

        switch (opcao) {
            case 1:
                system("cls");
                abrir_caixa();
                break;
            case 2:
                system("cls");
                fechamento_caixa();
                break;
            case 3:
                system("cls");
                carrinho();
                exibit_produtos();
                break;
            case 4:
                system("cls");
                padaria();
                break;
            case 5:
                system("cls");
                alimentos();
                break;
            case 6:
                system("cls");
                limpeza();
                break;
            case 7:
                system("cls");
                exibir_produtos();
                break;
            case 8:
                system("cls");
                deletar_produtos();
                break;
            case 9:
                system("cls");
                printf("Fechando o programa...");
                Sleep(2000);
                return 0;
        }
    } while (opcao != 9); // Enquanto a opção não for 9, continua o loop
}


// Referencias:
// 1. Stack Overflow:
// O que e stdin: https://stackoverflow.com/questions/19552360/what-does-standard-input-mean-in-c
// Como verificar se um numero float eh valido: https://stackoverflow.com/questions/14670073/is-it-possible-to-test-a-float-using-isdigit-function
// Como funciona typedef: https://stackoverflow.com/questions/2566027/what-is-the-use-of-typedef
// Uso de isAlpha: https://www.w3schools.com/c/ref_ctype_isalpha.php
// Uso de atoi: https://www.w3schools.com/c/ref_stdlib_atoi.php
// Uso de strcspn: https://www.w3schools.com/c/ref_string_strcspn.php