#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>


#define MAX_PRODUTOS 5
#define MAX_NOME 53
#define VALOR_MINIMO_CAIXA 200
#define ID_LIMPEZA 1
#define ID_ALIMENTOS 2
#define ID_PADARIA 3
#define ID_OUTROS 4
#define NOME_ARQUIVO "produtos.txt"

typedef struct
{
    char Nome[MAX_NOME];
    int Id;
    float preco;
    int quantidade;
    int id_categoria;
} PRODUTO;


// Função que escreve uma mensagem de log no arquivo "sistema.log"
void escrever_log(const char *mensagem, ...)
{
    // Obtém o tempo atual em segundos desde 1970
    time_t agora = time(NULL);

    // Converte o tempo em uma estrutura com data/hora local
    struct tm *tempo = localtime(&agora);
    // Declaração da lista de argumentos variáveis
    va_list args;
    // Abre (ou cria) o arquivo "sistema.log" no modo de adição ("a" = append)
    FILE *arquivo = fopen("sistema.log", "a");
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo de log"); // Mostra erro no terminal
        return; // Encerra a função em caso de erro
    }
    // Escreve a data e hora formatadas no início da linha de log
    fprintf(arquivo, "[%02d/%02d/%04d %02d:%02d:%02d] ",
            tempo->tm_mday,         // Dia (2 dígitos)
            tempo->tm_mon + 1,      // Mês (ajustado de 0–11 para 1–12)
            tempo->tm_year + 1900,  // Ano (ajustado de anos desde 1900)
            tempo->tm_hour,         // Hora
            tempo->tm_min,          // Minutos
            tempo->tm_sec);         // Segundos
    // Inicia a captura dos argumentos variáveis passados após a mensagem
    va_start(args, mensagem);
    // Escreve a mensagem formatada no arquivo usando os argumentos capturados
    vfprintf(arquivo, mensagem, args);
    // Encerra o uso da lista de argumentos variáveis
    va_end(args);
    // Adiciona uma quebra de linha ao final do log
    fprintf(arquivo, "\n");
    // Fecha o arquivo para garantir que tudo foi gravado corretamente
    fclose(arquivo);
}



int proximoId() // Função para pegar o próximo ID, por meio de leitura do arquivo
{
    FILE *arquivo = fopen(NOME_ARQUIVO, "r");
    if (arquivo == NULL) return 1; // Se o arquivo não existe, começa do 1

    int ultimoId = 0;
    PRODUTO temp;

    while (fscanf(arquivo, "%d;%49[^;];%f;%d;%d\n", &temp.Id, temp.Nome, &temp.preco, &temp.quantidade, &temp.id_categoria) == 5)
    {
        if (temp.Id > ultimoId)
        {
            ultimoId = temp.Id;
        }
    }
    fclose(arquivo);
    return ultimoId + 1;
}

void salvarProduto(PRODUTO produto)
{
    FILE *arquivo = fopen(NOME_ARQUIVO, "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%d;%s;%.2f;%d;%d\n", produto.Id, produto.Nome, produto.preco, produto.quantidade, produto.id_categoria);
    fclose(arquivo);
    printf("Produto salvo com sucesso!\n");
    sleep(2);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------//

float lerFloat(float *numero)
{
    int resultado;

    do
    {
        resultado = scanf("%f", numero);

        if (resultado != 1)
        {
            while (getchar() != '\n'); // limpa buffer
            return 0;
        }
    }
    while (resultado != 1);
    return 1;
}
int verifica_int(int *numero)
{
    int resultado = 0;
    do
    {
        resultado = scanf("%d", numero); // Tenta ler um número inteiro

        if (resultado != 1)   // Se o usuário digitou algo inválido (ex: letra, símbolo, etc)
        {
            // Limpa o buffer do teclado (remove os caracteres errados)
            while (getchar() != '\n');
            return 0;
        }
    }
    while (resultado != 1);   // Repete o processo até o usuário digitar um número válido
    return 1;
}

//-----------------------------------------------------------------------Função para limpar o buffer de entrada-----------------------------------------------------------------------------------------------//

typedef void (*flush)();
void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int verificastring(char nome[MAX_NOME])
{
    for (int i = 0; nome[i] != '\0' ; i++)
    {
        if ((!isalpha(nome[i])) && nome[i] != ' ')
        {
            return 0;
        }
    }
    return 1;
}

//----------------------------------------------------------------------------Função para cadastrar produtos-----------------------------------------------------------------------------------------//

void cadastrarProduto(PRODUTO **produtos, int *contador) {
    escrever_log("Iniciando cadastro de novo produto");
    int escolha = 0;

    // Realoca espaço para mais um produto
    PRODUTO *temp = realloc(*produtos, (*contador + 1) * sizeof(PRODUTO));
    if (temp == NULL) {
        escrever_log("Erro de alocação de memória");
        printf("Erro ao alocar memória para novo produto.\n");
        sleep(2);
        return;
    }
    *produtos = temp; // Atualiza o ponteiro

    limparBuffer();

    // Captura nome
    while (1) {
        printf("Nome do produto: ");
        fgets((*produtos)[*contador].Nome, MAX_NOME, stdin);
        (*produtos)[*contador].Nome[strcspn((*produtos)[*contador].Nome, "\n")] = '\0';

        if (!verificastring((*produtos)[*contador].Nome)) {
            escrever_log("Nome inválido: %s", (*produtos)[*contador].Nome);
            printf("Nome inválido! Tente novamente.\n");
            sleep(1);
            system("cls");
            continue;
        }
        escrever_log("Nome validado: %s", (*produtos)[*contador].Nome);
        break;
    }

    // Captura preço
    while (1) {
        printf("Preço: ");
        if (!lerFloat(&(*produtos)[*contador].preco)) {
            escrever_log("Erro no preço - valor inválido");
            (*produtos)[*contador].preco = 0;
            system("cls");
            printf("Preço inválido.\n");
            sleep(2);
            system("cls");
            continue;
        }

        if ((*produtos)[*contador].preco <= 0) {
            escrever_log("Alerta: preço zero ou negativo");
            printf("Cadastrar com preço R$ 0,00?\n1. Sim\n2. Não\nEscolha: ");
            scanf("%d", &escolha);
            if (escolha == 1) break;
            else if (escolha == 2) continue;
            else {
                printf("Opção inválida.\n");
                sleep(2);
            }
        }
        escrever_log("Preço cadastrado: R$%.2f", (*produtos)[*contador].preco);
        break;
    }

    // Captura quantidade
    while (1) {
        printf("Quantidade: ");
        if (!verifica_int(&(*produtos)[*contador].quantidade)) {
            escrever_log("Quantidade inválida");
            printf("Quantidade inválida! Digite números.\n");
            sleep(1);
            system("cls");
            continue;
        }

        if ((*produtos)[*contador].quantidade <= 0) {
            escrever_log("Quantidade zero ou negativa");
            system("cls");
            printf("Quantidade precisa ser maior que 0.\n");
            sleep(2);
            continue;
        }

        escrever_log("Quantidade cadastrada: %d", (*produtos)[*contador].quantidade);

        (*produtos)[*contador].Id = proximoId();
        salvarProduto((*produtos)[*contador]);
        escrever_log("Produto cadastrado - ID: %d, Nome: %s, Preço: %.2f, Qtd: %d",
            (*produtos)[*contador].Id, (*produtos)[*contador].Nome,
            (*produtos)[*contador].preco, (*produtos)[*contador].quantidade);

        (*contador)++; // incrementa só no final
        printf("Produto cadastrado com sucesso!\n\n");
        sleep(1);
        system("cls");
        break;
    }
}

//----------------------------------------------------------------------Função para exibir produtos------------------------------------------------------------------------------------------------//

void exibirProdutos(const PRODUTO *produtos,const int id_categoria,int contador){
    int i;
    int opc_exibir_produtos;
    const char* const titulos[] = {"MATERIAL DE LIMPEZA", "ALIMENTO", "PADARIA", "OUTROS"};
    const char* const titulo = titulos[id_categoria-1];

    printf("=== %s === \n", titulo);
    if (contador == 0){
        printf("Nenhum produto cadastrado.\n");
        return;}
    int produtos_exibidos = 0; // Contador para produtos exibidos
    for (int i = 0; i < contador; i++){
        if (produtos[i + 1].id_categoria == id_categoria){
            printf("%d. %s - R$%.2f - %d unidades\n", produtos[i].Id, produtos[i].Nome, produtos[i].preco, produtos[i].quantidade);
            produtos_exibidos++;}
    }
    if (produtos_exibidos == 0){
        printf("Nenhum produto cadastrado na categoria %s.\n", titulo);}
}

void abertura_caixa(float *valor_total_caixa, float *valor_inicial_caixa)
{
    escrever_log("Iniciando abertura de caixa");
    int escolha = 0;

    do
    {
        if (*valor_total_caixa > 0)
        {
            system("cls");
            printf("Você já tem %.2fR$ em caixa, deseja continuar com esse valor ou acrescentar um valor novo?\n", *valor_total_caixa);
            printf("1. Continuar e sair\n");
            printf("2. Acrescentar novo valor\n");

            if (!verifica_int(&escolha))
            {
                printf("Opção inválida.");
                sleep(1);
                continue;
            }

            if (escolha == 1)
            {
                return;
            }
            else
            {
                *valor_total_caixa = 0;
                abertura_caixa(valor_total_caixa, valor_inicial_caixa);
                return;
            }
        }

        system("cls");
        printf("Digite o valor para iniciar o caixa: R$");
        if (!lerFloat(valor_total_caixa))  // Passa o ponteiro direto
        {
            printf("Você não pode começar com isso, por favor digite novamente!\n");
            sleep(1);
            continue;
        }

        *valor_inicial_caixa = *valor_total_caixa;

        if (*valor_total_caixa <= 0)
        {
            printf("Você precisa iniciar o dia ao menos com algum valor maior que 0!\n");
            sleep(1);
            continue;
        }

        if (*valor_total_caixa < VALOR_MINIMO_CAIXA)
        {
            printf("Aviso: iniciar com menos de R$200 pode causar dificuldades.\n");
            printf("Deseja continuar?\n1. Sim\n2. Digitar novamente\nEscolha: ");
            if (!verifica_int(&escolha))
            {
                printf("Escolha inválida!\n");
                sleep(1);
                continue;
            }

            if (escolha == 1)
            {
                escrever_log("Alerta: Valor inicial do caixa (R$%.2f) abaixo do mínimo recomendado", &valor_total_caixa);
                break;
            }
            else
            {
                *valor_total_caixa = 0;
                continue;
            }
        }
        else
        {
            break;
        }
    }
    while (1);

    do
    {
        system("cls");
        printf("Você iniciará o dia com R$%.2f\nConfirmar?\n1. Sim\n2. Não\nEscolha: ", *valor_total_caixa);

        if (!verifica_int(&escolha))
        {
            printf("Digite uma resposta válida\n");
            sleep(1);
            continue;
        }

        if (escolha == 1)
        {
            printf("Caixa aberto com sucesso! você irá começar com R$%.2f\n", *valor_total_caixa);
            sleep(2);
            break;
        }
        else if (escolha == 2)
        {
            *valor_total_caixa = 0;
            abertura_caixa(valor_total_caixa, valor_inicial_caixa);
            return;
        }
        else
        {
            printf("Opção inválida!\n");
            sleep(1);
        }
    }
    while (escolha != 1);
    escrever_log("Caixa aberto com sucesso - Valor inicial: R$%.2f", &valor_total_caixa);
}

int Adicionar_Carrinho(float *valor_total_compra, float *valor_total_limpeza, float *valor_total_alimentos, float *valor_total_Padaria, float *valor_total_Outros, float *valor_caixa, float *valor_inicial_caixa, PRODUTO produtos[MAX_PRODUTOS], int *contador)
{
    int continuar = 0;
    int indice_produto = -1;
    float subtotal = 0;
    int escolha_id = 0, qtd = 0;

    if (*valor_caixa <= 0)
    {
        escrever_log("Tentativa de venda sem caixa aberto");
        system("cls");
        printf("Por favor, primeiro inicie o dia com algum valor no caixa!\n");
        sleep(2);
        system("cls");
        return 0;
    }

    if (*contador == 0)
    {
        printf("Nenhum produto cadastrado, por favor cadastre um produto!");
        sleep(2);
        return 0;
    }

    while (1)
    {
        system("cls");
        printf("\n\n========= Carrinho ===========\n\n");
        exibirProdutos(produtos, ID_LIMPEZA, *contador);
        exibirProdutos(produtos, ID_ALIMENTOS, *contador);
        exibirProdutos(produtos, ID_PADARIA, *contador);
        exibirProdutos(produtos, ID_OUTROS, *contador);

        printf("\n\nDigite apenas o ID do produto: ");
        if (!verifica_int(&escolha_id))
        {
            printf("Digite uma opção válida\n");
            sleep(1);
            continue;
        }

        for (int i = 0; i < *contador; i++)
        {
            if (escolha_id == produtos[i].Id)
            {
                escrever_log("Produto ID %d selecionado", escolha_id);
                indice_produto = i;
                break;
            }
        }

        if (indice_produto == -1)
        {
            printf("ID não encontrado...\n");
            sleep(2);
            continue;
        }

        printf("Agora digite a quantidade que deseja descontar desse produto no estoque: ");
        if (!verifica_int(&qtd) || qtd <= 0)
        {
            printf("Valor inválido, digite um valor válido maior que 0.\n");
            sleep(1);
            continue;
        }

        if (produtos[indice_produto].quantidade < qtd)
        {
            printf("Quantidade insuficiente em estoque! Estoque atual: %d\n", produtos[indice_produto].quantidade);
            sleep(2);
            continue;
        }

        // Atualiza estoque e valores
        produtos[indice_produto].quantidade -= qtd;
        printf("Produto %s Adicionado ao carrinho!\n", produtos[indice_produto].Nome);

        subtotal = qtd * produtos[indice_produto].preco;

        switch (produtos[indice_produto].id_categoria)
        {
        case ID_LIMPEZA:
            *valor_total_limpeza += subtotal;
            break;
        case ID_ALIMENTOS:
            *valor_total_alimentos += subtotal;
            break;
        case ID_PADARIA:
            *valor_total_Padaria += subtotal;
            break;
        case ID_OUTROS:
            *valor_total_Outros += subtotal;
            break;
        }
        *valor_total_compra += subtotal;

        if (produtos[indice_produto].quantidade == 0)
        {
            printf("O estoque do produto acabou!\n");
            memset(&produtos[indice_produto], 0, sizeof(PRODUTO));
            (*contador)--;
        }
        sleep(2);
        limparBuffer();
        pagar(valor_total_compra,valor_caixa);
        return 1;
    }
    while(1)
    {

        printf("Deseja continuar?\n1. Sim\n2. Não\nEscolha: ");

        if(!lerNumero(&continuar))
        {

            printf("Digite uma opção válida\n");
            sleep(1);
            continue;

        }
        switch(continuar)
        {
        case 1:
            Adicionar_Carrinho(&valor_total_compra,&valor_total_limpeza,&valor_total_alimentos,&valor_total_Padaria,&valor_total_Outros,&valor_caixa,&valor_inicial_caixa,produtos,&contador);
            break;
        case 2:
            return;
        default:
            printf("Opção inválida\n");
        }

    }


}

void pagar(float *vlr_tt_compra,float *valor_caixa)
{
    int metodo_pagamento = 0, confirma_pagamento = 0, percentual_desconto = 0,confirma_valor_pago = 0;
    float valor_pago = 0, desconto = 0, total_com_desconto = 0;
    float troco = 0,falta_pagar = 0;


    if (*vlr_tt_compra <= 0)
    {
        printf("Você não pode pagar uma compra com o valor de 0 reais");
        sleep(2);
        system("cls");
        return;
    }


    do
    {
        system("cls");
        printf("============ Pagamento ==========\n");
        printf("Valor total da compra: R$%.2f\n", *vlr_tt_compra);
        printf("Escolha o método de pagamento:\n");
        printf("1. Dinheiro/Pix\n2. Cartão de crédito/Cartão de debito\n3. Acrescentar mais produtos ao carrinho(retornar ao menu)\n");
        printf("Escolha: ");

        if (!verifica_int(&metodo_pagamento))
        {
            printf("Digite uma opção válida\n");
            sleep(1);
            pagar(&vlr_tt_compra,&valor_caixa);
        }

        switch(metodo_pagamento)
        {
        case 1:
            system("cls");


            if (*vlr_tt_compra >= 200.00)
            {
                printf("Compra acima de R$ 200.00. Aplicar desconto customizado.\n");
                do
                {
                    printf("Digite o percentual de desconto (0-100): ");
                    if(!verifica_int(&percentual_desconto))
                    {
                        printf("Valor inválido, tente novamente!");
                        sleep(2);
                        continue;

                    }

                    if (percentual_desconto < 0 && percentual_desconto > 100)   // Checa para que o desconto nao seja menor que 0 ou maior que 100
                    {
                        printf("Percentual inválido. Tente novamente.\n");
                    }

                }
                while (percentual_desconto < 0 && percentual_desconto > 100);   // Repete até que o desconto seja válido
                desconto = *vlr_tt_compra * (percentual_desconto / 100.0); // Calcula o desconto

            }
            else if (*vlr_tt_compra > 50.00 && *vlr_tt_compra < 200)     // Desconto de 50.01 até 199.99
            {
                desconto = *vlr_tt_compra * 0.10; // 10% de desconto
                printf("Desconto de 10%% aplicado.\n");

            }
            else if (*vlr_tt_compra <= 50.00)     // Desconto para até exatamente 50.00
            {
                desconto = *vlr_tt_compra * 0.05; // 5% de desconto
                printf("Desconto de 5%% aplicado.\n");
            }

            if (desconto > 0)
            {
                total_com_desconto = *vlr_tt_compra - desconto; // Calcula o total com desconto
                printf("Valor do desconto: R$ %.2f\n", desconto); // Exibe o valor do desconto
                printf("Novo total com desconto: R$ %.2f\n", total_com_desconto); // Exibe o total com desconto
            }

            while (1)
            {
                printf("Digite o valor que o cliente pagou em R$\nEscolha: ");
                if (!lerFloat(&valor_pago))
                {
                    printf("Valor inválido, tente novamente!");
                    sleep(2);
                    continue;
                }
                if (valor_pago > total_com_desconto)
                {
                    troco = valor_pago - total_com_desconto;
                    *valor_caixa -= troco;
                    printf("\nRetorne a ele %.2f de troco\n", troco);
                    *valor_caixa += (valor_pago - troco);
                    system("pause");
                    system("cls");
                    printf("Você tem %.2f em caixa", *valor_caixa);
                    sleep(1);
                    return;
                }
                else if (valor_pago < total_com_desconto)
                {
                    falta_pagar = total_com_desconto - valor_pago;
                    printf("\nFalta pagar %.2f\n", falta_pagar);
                    printf("Esse valor foi pago?\n1.SIM\n2.NÃO\n");
                    if(!verifica_int(&confirma_pagamento))
                    {
                        printf("Digite um valor válido");
                        continue;
                    }
                    if(confirma_pagamento == 1)
                    {
                        break;
                    }
                    else if (confirma_pagamento == 2)
                    {
                        printf("Digite novamente!");
                        sleep(1);
                        continue;
                    }
                    else
                    {
                        printf("Digite um valor entre apenas se sim' ou 'não'");
                        sleep(1);
                        continue;
                    }

                }

                printf("Pagamento de R$ %.2f realizado com sucesso via Dinheiro!\n", total_com_desconto);
                system("pause");
                return;
            }

        case 2:
            system("cls");
            printf("Valor total da compra: R$%.2f\n", *vlr_tt_compra);
            printf("insira ou aproxime o cartão!\n pressione qualquer tecla...\n");
            getchar();
            getchar();
            printf("===== Confirmação de forma de pagamento =======\n");
            printf("1. Pagamento confirmado \n0. Ocorreu um erro no pagamento. Digitar outra forma de pagamento\n");
            if(!verifica_int(&confirma_pagamento))
            {
                printf("Digite uma opção válida!");
                sleep(1);
            }

            if (confirma_pagamento == 1)
            {
                printf("Pagamento de R$ %.2f realizado com sucesso no Cartão!\n", *vlr_tt_compra);
                sleep(1);
                return;
            }
            else if (confirma_pagamento == 0)
            {
                pagar(vlr_tt_compra,valor_caixa);
                break;
            }
            else
            {
                printf("opção inválida, digite novamente!");
                continue;
            }


        case 3:
            printf("Retornando ao Menu...");
            sleep(1);
            system("cls");
            break;


        default:
            printf("opção inválida!");
            sleep(1);
        }



    }
    while(metodo_pagamento != 3);

}

void fechar_caixa(float valor_inicial_caixa,float vlr_tt_compra,float vlr_tt_limpeza,float vlr_tt_alimentos,float vlr_tt_padaria,float vlr_tt_outros)
{
    escrever_log("Resumo do dia - Abertura: R$%.2f, Vendas: R$%.2f",
                 valor_inicial_caixa, vlr_tt_compra);

    escrever_log("Vendas por categoria - Alimentos: R$%.2f, Limpeza: R$%.2f, Padaria: R$%.2f, Outros: R$%.2f",
                 vlr_tt_alimentos, vlr_tt_limpeza,
                 vlr_tt_padaria, vlr_tt_outros);

    escrever_log("Iniciando fechamento do caixa");
    printf("========= Fechamento do Caixa =========\n");
    printf("1. Valor (R$) de Abertura: R$%.2f\n", valor_inicial_caixa);
    printf("2. Valor (R$) de Vendas: R$%.2f\n", vlr_tt_compra);
    printf("Total em cada categoria:\n");
    printf("====== Alimentos ======\nR$%.2f\n", vlr_tt_alimentos);
    printf("====== Limpeza ======\nR$%.2f\n", vlr_tt_limpeza);
    printf("====== Padaria ======\nR$%.2f\n", vlr_tt_padaria);
    printf("====== Outros ======\nR$%.2f\n", vlr_tt_outros);
    printf("=======================================\n");
    system("pause");
}

//------------------------------------------------------------------------------Função para deletar produtos--------------------------------------------------------------//

void deletar_produto() {
    FILE *arquivo = fopen(NOME_ARQUIVO, "r"); // Abre o arquivo para leitura
    if (arquivo == NULL) { // Se o arquivo não puder ser aberto ele retorna
        escrever_log("Erro: Falha ao abrir arquivo de produtos");
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w"); // Abre um arquivo temporário para escrita
    if (temp == NULL) {
        escrever_log("Erro: Falha ao criar arquivo temporário");
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    PRODUTO produto; // Estrutura para armazenar os produtos
    int id_produto; // ID do produto a ser deletado
    int encontrado = 0; // Flag para verificar se o produto foi encontrado

    printf("Digite o ID do produto a ser deletado: "); // Pede o ID do produto
    if (!verifica_int(&id_produto)) { // Verifica se a entrada é válida
        escrever_log("Erro: ID inválido fornecido");
        printf("ID inválido!\n");
        fclose(arquivo);
        fclose(temp);
        remove("temp.txt");
        return;
    }

    escrever_log("Tentativa de deletar produto ID: %d", id_produto);

    while (fscanf(arquivo, "%d;%49[^;];%f;%d;%d\n", // Lê os produtos do arquivo
           &produto.Id, produto.Nome, &produto.preco,
           &produto.quantidade, &produto.id_categoria) == 5) {
        
        if (produto.Id == id_produto) {
            encontrado = 1;
            escrever_log("Produto encontrado para deleção: %s (ID: %d)", 
                        produto.Nome, produto.Id);
            continue;
        }

        fprintf(temp, "%d;%s;%.2f;%d;%d\n", 
                produto.Id, produto.Nome, produto.preco, 
                produto.quantidade, produto.id_categoria);
    }

    fclose(arquivo);
    fclose(temp);

    if (!encontrado) { // Se o produto não foi encontrado
        escrever_log("Erro: Produto ID %d não encontrado", id_produto);
        printf("Produto não encontrado!\n");
        remove("temp.txt");
        return;
    }

    if (remove(NOME_ARQUIVO) != 0) { // Remove o arquivo original
        escrever_log("Erro: Falha ao remover arquivo original");
        printf("Erro ao deletar o produto.\n");
        remove("temp.txt");
        return;
    }

    if (rename("temp.txt", NOME_ARQUIVO) != 0) { // Renomeia o arquivo temporário
        escrever_log("Erro: Falha ao renomear arquivo temporário");
        printf("Erro ao deletar o produto.\n");
        return;
    }

    escrever_log("Produto ID %d deletado com sucesso", id_produto);
    printf("Produto deletado com sucesso!\n");
    sleep(2);
    return;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int main()
{

    int opcao = 0,categoria = 0,opc_exibir_produtos = 0,contador = 0,numero = 0,escolha = 0,escolha_acrescenta_produtos = 0;
    float valor_inicial_caixa = 0,valor_total_caixa = 0;
    float vlr_tt_compra = 0, vlr_tt_limpeza = 0, vlr_tt_alimentos = 0, vlr_tt_padaria = 0, vlr_tt_outros = 0;
    PRODUTO *produtos = NULL; // Ponteiro para uso com realloc

    setlocale(LC_ALL, "Portuguese");
    system("cls");

    escrever_log("Programa iniciado");

    do
    {
        system("cls");
        printf("\n===== MENU MERCADINHO =====\n");
        printf("1. Cadastrar Produto\n2. Exibir Produtos\n3. Abrir ao caixa\n4. Pagamento\n5. Fechar caixa\n7. Deletar produto\n6. Sair\n");

        if (!verifica_int(&opcao)) {}

        if (opcao == 1)
        {
            do
            {
                printf("Qual a categoria que você deseja acrescentar o produto:\n1. Limpeza\n2. Alimentos\n3. Padaria\n4. Outros\nEscolha: ");
                if (!verifica_int(&escolha_acrescenta_produtos))
                {
                    printf("Entrada inválida! Tente novamente.\n");
                    continue; // Volta para o início do loop se a entrada for inválida
                }

                switch (escolha_acrescenta_produtos)
                {
                case 1:
                    escrever_log("Opção selecionada: %d", escolha_acrescenta_produtos);
                    cadastrarProduto(&produtos, &contador);
                    produtos[contador - 1].id_categoria = ID_LIMPEZA; // ou outro ID
                    break;
                case 2:
                    escrever_log("Opção selecionada: %d", escolha_acrescenta_produtos);
                     cadastrarProduto(&produtos, &contador);
                    produtos[contador - 1].id_categoria = ID_ALIMENTOS;
                    break;
                case 3:
                    escrever_log("Opção selecionada: %d", escolha_acrescenta_produtos);
                     cadastrarProduto(&produtos, &contador);
                    produtos[contador - 1].id_categoria = ID_PADARIA;
                    break;
                case 4:
                    escrever_log("Opção selecionada: %d", escolha_acrescenta_produtos);
                     cadastrarProduto(&produtos, &contador);
                    produtos[contador - 1].id_categoria = ID_OUTROS;
                    break;
                default:
                    escrever_log("Erro: Opção inválida na categoria de cadastro - %d", escolha_acrescenta_produtos);
                    printf("Opção inválida! Tente novamente.\n");
                    continue;
                }
            }
            while (escolha_acrescenta_produtos < 1 || escolha_acrescenta_produtos > 4);    // Continua até uma opção válida
        }
        else if (opcao == 2)
        {

            system("cls");
            printf("Qual a categoria que você deseja Visualizar?\n");
            printf("1. Produtos de limpeza\n");
            printf("2. Alimentos\n");
            printf("3. Padaria\n");
            printf("4. Outros\n");

            if(!verifica_int(&opc_exibir_produtos))
            {
                printf("digite um valor válido");
                sleep(2);
                continue;
            }
            switch(opc_exibir_produtos)
            {
            case 1:
                escrever_log("Opção selecionada: %d", opc_exibir_produtos);
                system("cls");
                exibirProdutos(produtos, ID_LIMPEZA, contador);
                system("pause");
                break;
            case 2:
                escrever_log("Opção selecionada: %d", opc_exibir_produtos);
                system("cls");
                exibirProdutos(produtos,ID_ALIMENTOS, contador);
                system("pause");
                break;
            case 3:
                escrever_log("Opção selecionada: %d", opc_exibir_produtos);
                system("cls");
                exibirProdutos(produtos,ID_PADARIA, contador);
                system("pause");
                break;
            case 4:
                escrever_log("Opção selecionada: %d", opc_exibir_produtos);
                system("cls");
                exibirProdutos(produtos,ID_OUTROS, contador);
                system("pause");
                break;

            default:
                escrever_log("Erro: Opção inválida na exibição de produtos - %d", opc_exibir_produtos);
                printf("Categoria inválida!\n");
                sleep(2);
                break;
            }

        }
        else if (opcao == 3)
        {
            escrever_log("Opção selecionada: %d", opcao);
            system("cls");
            abertura_caixa(&valor_total_caixa,&valor_inicial_caixa);
        }
        else if (opcao == 4)
        {
            escrever_log("Opção selecionada: %d", opcao);
            system("cls");
            Adicionar_Carrinho(&vlr_tt_compra, &vlr_tt_limpeza, &vlr_tt_alimentos, &vlr_tt_padaria, &vlr_tt_outros,&valor_total_caixa,&valor_inicial_caixa,produtos,&contador);
        }
        else if (opcao == 5)
        {
            escrever_log("Opção selecionada: %d", opcao);
            system("cls");
            fechar_caixa(valor_inicial_caixa, vlr_tt_compra, vlr_tt_limpeza, vlr_tt_alimentos, vlr_tt_padaria, vlr_tt_outros);
        }
        else if (opcao == 6)
{
    escrever_log("Opção selecionada: %d", opcao);
    int escolha_deletar = 0;
    do {
        system("cls");
        printf("\n===== DELETAR PRODUTOS =====\n");
        printf("1. Visualizar todos os produtos\n");
        printf("2. Deletar produto por ID\n");
        printf("3. Voltar ao menu principal\n");
        printf("Escolha: ");

        if (!verifica_int(&escolha_deletar)) {
            printf("Digite uma opção válida!\n");
            sleep(1);
            continue;
        }

        switch(escolha_deletar) {
            case 1:
                escrever_log("Visualizando produtos antes da deleção");
                system("cls");
                printf("\n=== PRODUTOS CADASTRADOS ===\n");
                exibirProdutos(produtos, ID_LIMPEZA, contador);
                exibirProdutos(produtos, ID_ALIMENTOS, contador);
                exibirProdutos(produtos, ID_PADARIA, contador);
                exibirProdutos(produtos, ID_OUTROS, contador);
                printf("\nPressione Enter para continuar...");
                getchar();
                getchar();
                break;

            case 2:
                escrever_log("Iniciando processo de deleção");
                system("cls");
                deletar_produto();
                break;

            case 3:
                escrever_log("Retornando ao menu principal");
                printf("Retornando ao menu principal...\n");
                sleep(1);
                break;

            default:
                escrever_log("Opção inválida selecionada: %d", escolha_deletar);
                printf("Opção inválida! Tente novamente.\n");
                sleep(1);
                break;
        }
    } while (escolha_deletar != 3);
    }
    else if (opcao == 7)
    {
        escrever_log("Opção selecionada: %d", opcao);
        system("cls");
        printf("Saindo do programa...\n");
        sleep(1);
        break;
    }

    }
    while (opcao != 7);
    escrever_log("Programa encerrado normalmente");
    printf("Programa encerrado.\n");
    return 0;
}
