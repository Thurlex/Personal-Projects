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
#define ID_TODOS 5
#define NOME_ARQUIVO_PRODUTOS "produtos.txt"
#define NOME_ARQUIVO_LIMPEZA "produtoslimpeza.txt"
#define NOME_ARQUIVO_ALIMENTOS "produtosalimentos.txt"
#define NOME_ARQUIVO_PADARIA "produtospadaria.txt"
#define NOME_ARQUIVO_OUTROS "produtosoutros.txt"

typedef struct  // Estrutura geral de Produtos ( sem ponteiros)
{
    char Nome[MAX_NOME];
    int Id;
    float preco;
    int quantidade;
    int id_categoria;
} PRODUTO;

typedef struct outro {  //Estrutura da lista duplamente encadeada " OUTROS"
    int dado;
    struct outro* anterior;
    struct outro* proximo;
} Outro;

// ESTRUTURA PARA PADARIA
typedef struct node_padaria {
    PRODUTO produto;
    struct node_padaria* anterior;
    struct node_padaria* proximo;
} NodePadaria;


// Fun��o que escreve uma mensagem de log no arquivo "sistema.log"
void escrever_log(const char *mensagem, ...)
{
    // Obt�m o tempo atual em segundos desde 1970
    time_t agora = time(NULL);

    // Converte o tempo em uma estrutura com data/hora local
    struct tm *tempo = localtime(&agora);
    // Declara��o da lista de argumentos vari�veis
    va_list args;
    // Abre (ou cria) o arquivo "sistema.log" no modo de adi��o ("a" = append)
    FILE *arquivo = fopen("sistema.log", "a");
    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL)
    {
        perror("Erro ao abrir o arquivo de log"); // Mostra erro no terminal
        return; // Encerra a fun��o em caso de erro
    }
    // Escreve a data e hora formatadas no in�cio da linha de log
    fprintf(arquivo, "[%02d/%02d/%04d %02d:%02d:%02d] ",
            tempo->tm_mday,         // Dia (2 d�gitos)
            tempo->tm_mon + 1,      // M�s (ajustado de 0�11 para 1�12)
            tempo->tm_year + 1900,  // Ano (ajustado de anos desde 1900)
            tempo->tm_hour,         // Hora
            tempo->tm_min,          // Minutos
            tempo->tm_sec);         // Segundos
    // Inicia a captura dos argumentos vari�veis passados ap�s a mensagem
    va_start(args, mensagem);
    // Escreve a mensagem formatada no arquivo usando os argumentos capturados
    vfprintf(arquivo, mensagem, args);
    // Encerra o uso da lista de argumentos vari�veis
    va_end(args);
    // Adiciona uma quebra de linha ao final do log
    fprintf(arquivo, "\n");
    // Fecha o arquivo para garantir que tudo foi gravado corretamente
    fclose(arquivo);
}



int proximoId()
{
    FILE *arquivo = fopen(NOME_ARQUIVO_PRODUTOS, "r");
    if (arquivo == NULL) return 1; // Se o arquivo n�o existe, come�a do 1

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

void salvarProdutos(PRODUTO produto, const int *nomearquivo)
{
    FILE *arquivo = fopen(nomearquivo, "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%d;%s;%.2f;%d;%d\n", produto.Id, produto.Nome, produto.preco, produto.quantidade, produto.id_categoria);
    fclose(arquivo);
    sleep(2);
}

// Fun��o para listar todos os produtos cadastrados
void listarProdutos(const char *nomearquivo, const int id_categoria, int criterio_ordenacao) {
    FILE *arquivo = fopen(nomearquivo, "r");
    if (arquivo == NULL) {
        printf("Nenhum produto cadastrado ainda.\n");
        sleep(2);
        return;
    }

    // Contar número de produtos
    int count = 0;
    PRODUTO temp;
    while (fscanf(arquivo, "%d;%49[^;];%f;%d;%d\n", &temp.Id, temp.Nome, &temp.preco, &temp.quantidade, &temp.id_categoria) == 5) {
        count++;
    }
    rewind(arquivo);

    // Alocar memória para os produtos
    PRODUTO *produtos = malloc(count * sizeof(PRODUTO));
    if (produtos == NULL) {
        printf("Erro ao alocar memória!\n");
        fclose(arquivo);
        return;
    }

    // Ler produtos para o array
    int i = 0;
    while (fscanf(arquivo, "%d;%49[^;];%f;%d;%d\n", &produtos[i].Id, produtos[i].Nome, &produtos[i].preco, &produtos[i].quantidade, &produtos[i].id_categoria) == 5) {
        i++;
    }
    fclose(arquivo);

    // Aplicar ordenação se solicitado
    if (criterio_ordenacao != 0 && count > 0) {
        switch(criterio_ordenacao) {
            case 1: // Ordenar por ID
                quickSort(produtos, 0, count-1, compararPorId);
                break;
            case 2: // Ordenar por Nome
                quickSort(produtos, 0, count-1, compararPorNome);
                break;
            case 3: // Ordenar por Preço
                quickSort(produtos, 0, count-1, compararPorPreco);
                break;
        }
    }

    const char* const titulos[] = {"MATERIAL DE LIMPEZA", "ALIMENTO", "PADARIA", "OUTROS", "TODOS OS PRODUTOS"};
    const char* const titulo = titulos[id_categoria-1];
    printf("\n--- Lista de Produtos de %s ---\n", titulo);

    for (i = 0; i < count; i++) {
        printf("ID: %d | Nome: %s | Preço: R$ %.2f | Estoque: %d\n", 
               produtos[i].Id, produtos[i].Nome, produtos[i].preco, produtos[i].quantidade);
    }

    fclose(arquivo);
    free(produtos);
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------//
    Outro* criarOutro(int dado) { // criar um novo n� duplo
    Outro* novoOutro = (Outro*) malloc(sizeof(Outro));
    if (novoOutro == NULL) {
        perror("Erro ao alocar mem�ria para novo item da lista 'Outros'");
        exit(EXIT_FAILURE);
    }
    novoOutro->dado = dado;
    novoOutro->proximo = NULL;
    novoOutro->anterior = NULL;
    return novoOutro;
}

void inserirNoInicioOutro(Outro** inicio, int dado) { // inser��o no inicio
    Outro* novoOutro = criarOutro(dado);
    novoOutro->proximo = *inicio;
    if (*inicio != NULL) {
        (*inicio)->anterior = novoOutro;
    }
    *inicio = novoOutro;
    printf("Inserido %d no in�cio (categoria 'Outros').\n", dado);
}

void inserirNoFinalOutro(Outro** inicio, int dado) { // inser��o no final
    Outro* novoOutro = criarOutro(dado);
    if (*inicio == NULL) {
        *inicio = novoOutro;
    } else {
        Outro* atual = *inicio;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoOutro;
        novoOutro->anterior = atual;
    }
    printf("Inserido %d no final (categoria 'Outros').\n", dado);
}

// FUNÇÕES PARA MANIPULAÇÃO DA PADARIA
NodePadaria* criarNodePadaria(PRODUTO p) {
    NodePadaria* novo = (NodePadaria*)malloc(sizeof(NodePadaria));
    if (novo == NULL) {
        perror("Erro ao alocar memória para Padaria");
        exit(EXIT_FAILURE);
    }
    novo->produto = p;
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

void inserirFinalPadaria(NodePadaria** head, PRODUTO p) {
    NodePadaria* novo = criarNodePadaria(p);
    if (*head == NULL) {
        *head = novo;
    } else {
        NodePadaria* temp = *head;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
        novo->anterior = temp;
    }
}

//------------------------------------------------------------------------------------------------------


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
        resultado = scanf("%d", numero); // Tenta ler um n�mero inteiro

        if (resultado != 1)   // Se o usu�rio digitou algo inv�lido (ex: letra, s�mbolo, etc)
        {
            // Limpa o buffer do teclado (remove os caracteres errados)
            while (getchar() != '\n');
            return 0;
        }
    }
    while (resultado != 1);   // Repete o processo at� o usu�rio digitar um n�mero v�lido
    return 1;
}
//-----------------------------------------------------------------------Fun��o para limpar o buffer de entrada-----------------------------------------------------------------------------------------------//
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

//----------------------------------------------------------------------------Fun��o para cadastrar produtos-----------------------------------------------------------------------------------------//
void cadastrarProduto(PRODUTO **produtos, int *contador,int *capacidade,int categoria)
{
    // Log in�cio da fun��o
    escrever_log("Iniciando cadastro de novo produto");
    int escolha = 0;
    int continuar = 1;

    *capacidade = MAX_PRODUTOS;

// no seu c�digo
    if (*contador >= capacidade)
    {
        int nova_capacidade = (*capacidade) * 2;
        PRODUTO *temp = realloc(*produtos, nova_capacidade * sizeof(PRODUTO));
        if (temp == NULL)
        {
            printf("Erro ao realocar mem�ria!\n");
            exit(1);
        }
        *produtos = temp;
        capacidade = nova_capacidade;
    }

    limparBuffer(); // Limpa buffer antes de capturar a string

    // Captura o nome do produto
    while (1)
    {
        printf("Nome do produto: ");
        fgets((*produtos)[*contador].Nome, MAX_NOME, stdin);
        (*produtos)[*contador].Nome[strcspn((*produtos)[*contador].Nome, "\n")] = '\0'; // Remove a nova linha

        // Verifica se o nome � v�lido
        if (!verificastring((*produtos)[*contador].Nome))
        {
            escrever_log("Tentativa de cadastro com nome inv�lido: %s", (*produtos)[*contador].Nome);
            printf("Nome inv�lido! N�o use n�meros ou s�mbolos. Tente novamente.\n");
            sleep(1);
            system("cls");
            continue;
        }
        escrever_log("Nome do produto validado: %s", (*produtos)[*contador].Nome);
        break; // Sai do loop se o nome for v�lido
    }

    // Captura o pre�o do produto
    while (1)
    {
        printf("Pre�o: ");
        if (!lerFloat(&(*produtos)[*contador].preco)) // Verifica se a entrada � v�lida
        {
            escrever_log("Erro na entrada do pre�o - valor inv�lido");
            (*produtos)[*contador].preco = 0;
            system("cls");
            printf("Por favor, n�o tente digitar letras em pre�o ou outro caracter inv�lido\n");
            sleep(2);
            system("cls");
            continue;
        }

        // Verifica se o pre�o � maior que zero
        if ((*produtos)[*contador].preco <= 0)
        {
            escrever_log("Alerta: Tentativa de cadastro com pre�o zero ou negativo");
            printf("\nVoc� tem certeza que deseja cadastrar o produto com pre�o R$ 0,00?\n");
            printf("1. Sim\n");
            printf("2. N�o, quero digitar de novo\n");
            printf("Escolha: ");
            scanf("%d", &escolha);

            if (escolha == 1)
            {
                break; // Sai do loop e continua
            }
            else if (escolha == 2)
            {
                (*produtos)[*contador].preco = -1; // Zera o valor para seguran�a (n�o obrigat�rio)
                continue; // Volta pro in�cio do loop e pede o pre�o de novo
            }
            else
            {
                printf("Op��o inv�lida! Tente novamente.\n");
                sleep(2);
            }
        }
        escrever_log("Pre�o cadastrado com sucesso: R$%.2f", (*produtos)[*contador].preco);
        break; // Sai do loop se o pre�o for v�lido
    }

    // Captura a quantidade do produto
    while (1)
    {
        printf("Quantidade: ");
        if (!verifica_int(&(*produtos)[*contador].quantidade))
        {
            escrever_log("Erro na entrada da quantidade - valor inv�lido");
            printf("Quantidade inv�lida! Digite apenas n�meros\n");
            (*produtos)[*contador].quantidade = 0;
            sleep(1);
            system("cls");
            continue;
        }

        escrever_log("Quantidade cadastrada: %d", (*produtos)[*contador].quantidade);

        // Verifica se a quantidade � maior que zero
        if ((*produtos)[*contador].quantidade <= 0)
        {
            escrever_log("Erro: Tentativa de cadastro com quantidade zero ou negativa");
            system("cls");
            printf("Voc� n�o pode acrescentar quantidade 0. Por favor, tente denovo!\n\n");
            (*produtos)[*contador].quantidade = 0; // Zera a quantidade para seguran�a
            sleep(2);
            continue;
        }
        // Volta para o in�cio do

        // Atribui um ID �nico  ao produto


        (*produtos)[*contador].Id = proximoId(); // Gera novo ID
        (*produtos)[*contador].id_categoria = categoria;
        salvarProdutos((*produtos)[*contador], &NOME_ARQUIVO_PRODUTOS);    // Salva no arquivo
        if((*produtos)[*contador].id_categoria == ID_LIMPEZA)
            salvarProdutos((*produtos)[*contador], &NOME_ARQUIVO_LIMPEZA);
        if((*produtos)[*contador].id_categoria == ID_ALIMENTOS)
            salvarProdutos((*produtos)[*contador], &NOME_ARQUIVO_ALIMENTOS);
        if((*produtos)[*contador].id_categoria == ID_PADARIA)
            salvarProdutos((*produtos)[*contador], &NOME_ARQUIVO_PADARIA);
        if((*produtos)[*contador].id_categoria == ID_OUTROS)
            salvarProdutos((*produtos)[*contador], &NOME_ARQUIVO_OUTROS);

        (*contador)++;

        escrever_log("Produto cadastrado com sucesso - ID: %d, Nome: %s, Pre�o: %.2f, Quantidade: %d",
                     (*produtos)[*contador - 1].Id, (*produtos)[*contador - 1].Nome, (*produtos)[*contador - 1].preco,(*produtos)[*contador - 1].quantidade);

        printf("Produto salvo com sucesso!\n");
        sleep(1);
        system("cls");
        break; // Sai do loop principal ap�s o cadastro

    }

    // Após validar o produto:
    if (categoria == ID_PADARIA) {
        PRODUTO p;
        strcpy(p.Nome, (*produtos)[*contador].Nome);
        p.preco = (*produtos)[*contador].preco;
        p.quantidade = (*produtos)[*contador].quantidade;
        p.id_categoria = categoria;
        p.Id = proximoId();
        
        inserirFinalPadaria(&lista_padaria, p);
        salvarProdutos(p, NOME_ARQUIVO_PADARIA);
        salvarProdutos(p, NOME_ARQUIVO_PRODUTOS);
        
        escrever_log("Produto cadastrado (Padaria): ID %d - %s", p.Id, p.Nome);
        printf("Produto salvo na lista de Padaria!\n");
    }
}
//----------------------------------------------------------------------Fun��o para exibir produtos------------------------------------------------------------------------------------------------//

/*
void exibirProdutos(const PRODUTO produtos[MAX_PRODUTOS],const int id_categoria,int contador)
{
    int i;
    int opc_exibir_produtos;

    const char* const titulos[] = {"MATERIAL DE LIMPEZA", "ALIMENTO", "PADARIA", "OUTROS"};

    const char* const titulo = titulos[id_categoria-1];

    printf("=== %s === \n", titulo);
    if (contador == 0)
    {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    int produtos_exibidos = 0; // Contador para produtos exibidos
    for (int i = 0; i < contador; i++)
    {
        if (produtos[i + 1].id_categoria == id_categoria)
        {
            printf("%d. %s - R$%.2f - %d unidades\n", produtos[i].Id, produtos[i].Nome, produtos[i].preco, produtos[i].quantidade);
            produtos_exibidos++;
        }
    }

    if (produtos_exibidos == 0)
    {
        printf("Nenhum produto cadastrado na categoria %s.\n", titulo);
    }
}
*/
void abertura_caixa(float *valor_total_caixa, float *valor_inicial_caixa)
{
    escrever_log("Iniciando abertura de caixa");
    int escolha = 0;

    do
    {
        if (*valor_total_caixa > 0)
        {
            system("cls");
            printf("Voc� j� tem %.2fR$ em caixa, deseja continuar com esse valor ou acrescentar um valor novo?\n", *valor_total_caixa);
            printf("1. Continuar e sair\n");
            printf("2. Acrescentar novo valor\n");

            if (!verifica_int(&escolha))
            {
                printf("Op��o inv�lida.");
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
            printf("Voc� n�o pode come�ar com isso, por favor digite novamente!\n");
            sleep(1);
            continue;
        }

        *valor_inicial_caixa = *valor_total_caixa;

        if (*valor_total_caixa <= 0)
        {
            printf("Voc� precisa iniciar o dia ao menos com algum valor maior que 0!\n");
            sleep(1);
            continue;
        }

        if (*valor_total_caixa < VALOR_MINIMO_CAIXA)
        {
            printf("Aviso: iniciar com menos de R$200 pode causar dificuldades.\n");
            printf("Deseja continuar?\n1. Sim\n2. Digitar novamente\nEscolha: ");
            if (!verifica_int(&escolha))
            {
                printf("Escolha inv�lida!\n");
                sleep(1);
                continue;
            }

            if (escolha == 1)
            {
                escrever_log("Alerta: Valor inicial do caixa (R$%.2f) abaixo do m�nimo recomendado", &valor_total_caixa);
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
        printf("Voc� iniciar� o dia com R$%.2f\nConfirmar?\n1. Sim\n2. N�o\nEscolha: ", *valor_total_caixa);

        if (!verifica_int(&escolha))
        {
            printf("Digite uma resposta v�lida\n");
            sleep(1);
            continue;
        }

        if (escolha == 1)
        {
            printf("Caixa aberto com sucesso! voc� ir� come�ar com R$%.2f\n", *valor_total_caixa);
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
            printf("Op��o inv�lida!\n");
            sleep(1);
        }
    }
    while (escolha != 1);
    escrever_log("Caixa aberto com sucesso - Valor inicial: R$%.2f", *valor_total_caixa);
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


    if (produtos[*contador].Id == 0)
    {
        printf("Nenhum produto cadastrado, por favor cadastre um produto!");
        sleep(2);
        return 0;
    }

    while (1)
    {
        system("cls");
        printf("\n\n========= Carrinho ===========\n\n");
        listarProdutos(produtos[*contador],NOME_ARQUIVO_PRODUTOS,ID_TODOS);


        printf("\n\nDigite apenas o ID do produto: ");
        if (!verifica_int(&escolha_id))
        {
            printf("Digite uma op��o v�lida\n");
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
            printf("ID n�o encontrado...\n");
            sleep(2);
            continue;
        }

        printf("Agora digite a quantidade que deseja descontar desse produto no estoque: ");
        if (!verifica_int(&qtd) || qtd <= 0)
        {
            printf("Valor inv�lido, digite um valor v�lido maior que 0.\n");
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

        printf("Deseja continuar?\n1. Sim\n2. N�o\nEscolha: ");

        if(!lerNumero(&continuar))
        {

            printf("Digite uma op��o v�lida\n");
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
            printf("Op��o inv�lida\n");
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
        printf("Voc� n�o pode pagar uma compra com o valor de 0 reais");
        sleep(2);
        system("cls");
        return;
    }


    do
    {
        system("cls");
        printf("============ Pagamento ==========\n");
        printf("Valor total da compra: R$%.2f\n", *vlr_tt_compra);
        printf("Escolha o m�todo de pagamento:\n");
        printf("1. Dinheiro/Pix\n2. Cart�o de cr�dito/Cart�o de debito\n3. Acrescentar mais produtos ao carrinho(retornar ao menu)\n");
        printf("Escolha: ");

        if (!verifica_int(&metodo_pagamento))
        {
            printf("Digite uma op��o v�lida\n");
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
                        printf("Valor inv�lido, tente novamente!");
                        sleep(2);
                        continue;

                    }

                    if (percentual_desconto < 0 && percentual_desconto > 100)   // Checa para que o desconto nao seja menor que 0 ou maior que 100
                    {
                        printf("Percentual inv�lido. Tente novamente.\n");
                    }

                }
                while (percentual_desconto < 0 && percentual_desconto > 100);   // Repete at� que o desconto seja v�lido
                desconto = *vlr_tt_compra * (percentual_desconto / 100.0); // Calcula o desconto

            }
            else if (*vlr_tt_compra > 50.00 && *vlr_tt_compra < 200)     // Desconto de 50.01 at� 199.99
            {
                desconto = *vlr_tt_compra * 0.10; // 10% de desconto
                printf("Desconto de 10%% aplicado.\n");

            }
            else if (*vlr_tt_compra <= 50.00)     // Desconto para at� exatamente 50.00
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
                    printf("Valor inv�lido, tente novamente!");
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
                    printf("Voc� tem %.2f em caixa", *valor_caixa);
                    sleep(1);
                    return;
                }
                else if (valor_pago < total_com_desconto)
                {
                    falta_pagar = total_com_desconto - valor_pago;
                    printf("\nFalta pagar %.2f\n", falta_pagar);
                    printf("Esse valor foi pago?\n1.SIM\n2.N�O\n");
                    if(!verifica_int(&confirma_pagamento))
                    {
                        printf("Digite um valor v�lido");
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
                        printf("Digite um valor entre apenas se sim' ou 'n�o'");
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
            printf("insira ou aproxime o cart�o!\n pressione qualquer tecla...\n");
            getchar();
            getchar();
            printf("===== Confirma��o de forma de pagamento =======\n");
            printf("1. Pagamento confirmado \n0. Ocorreu um erro no pagamento. Digitar outra forma de pagamento\n");
            if(!verifica_int(&confirma_pagamento))
            {
                printf("Digite uma op��o v�lida!");
                sleep(1);
            }

            if (confirma_pagamento == 1)
            {
                printf("Pagamento de R$ %.2f realizado com sucesso no Cart�o!\n", *vlr_tt_compra);
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
                printf("op��o inv�lida, digite novamente!");
                continue;
            }


        case 3:
            printf("Retornando ao Menu...");
            sleep(1);
            system("cls");
            break;


        default:
            printf("op��o inv�lida!");
            sleep(1);
        }



    }
    while(metodo_pagamento != 3);

}

void fechar_caixa(float valor_inicial_caixa,float vlr_tt_compra,float *vlr_tt_limpeza,float *vlr_tt_alimentos,float *vlr_tt_padaria,float *vlr_tt_outros)
{
    escrever_log("Resumo do dia - Abertura: R$%.2f, Vendas: R$%.2f",
                 valor_inicial_caixa, vlr_tt_compra);

    escrever_log("Vendas por categoria - Alimentos: R$%.2f, Limpeza: R$%.2f, Padaria: R$%.2f, Outros: R$%.2f",
                 *vlr_tt_alimentos, *vlr_tt_limpeza,
                 *vlr_tt_padaria, *vlr_tt_outros);

    escrever_log("Iniciando fechamento do caixa");
    printf("========= Fechamento do Caixa =========\n");
    printf("1. Valor (R$) de Abertura: R$%.2f\n", valor_inicial_caixa);
    printf("2. Valor (R$) de Vendas: R$%.2f\n", vlr_tt_compra);
    printf("Total em cada categoria:\n");
    printf("====== Alimentos ======\nR$%.2f\n", *vlr_tt_alimentos);
    printf("====== Limpeza ======\nR$%.2f\n", *vlr_tt_limpeza);
    printf("====== Padaria ======\nR$%.2f\n", *vlr_tt_padaria);
    printf("====== Outros ======\nR$%.2f\n", *vlr_tt_outros);
    printf("=======================================\n");
    system("pause");
}


int main()
{
    Outro* inicio = NULL; // Lista come�a vazia
    NodePadaria* lista_padaria = NULL; // Inicializa lista
    int opcao = 0,categoria = 0,opc_exibir_produtos = 0,contador = 0,numero = 0,escolha = 0,escolha_acrescenta_produtos = 0;
    float valor_inicial_caixa = 0,valor_total_caixa = 0;
    float vlr_tt_compra = 0, vlr_tt_limpeza = 0, vlr_tt_alimentos = 0, vlr_tt_padaria = 0, vlr_tt_outros = 0;

    inserirNoFinalOutro(&inicio, vlr_tt_outros);

    setlocale(LC_ALL, "Portuguese"); // Para acentua��o funcionar no Windows

    system("cls"); // Limpa tela
    int capacidade = MAX_PRODUTOS;
    escrever_log("Programa iniciado");

    PRODUTO *produtos = malloc(capacidade * sizeof(PRODUTO));
    if (produtos == NULL)
    {
        escrever_log("Erro ao alocar memoria!");
        printf("Erro ao alocar mem�ria!\n");
        return 1;
    }
    escrever_log("Memoria alocada!");

    do
    {
        system("cls");
        printf("\n===== MENU MERCADINHO =====\n");
        printf("1. Cadastrar Produto\n2. Exibir Produtos\n3. Abrir ao caixa\n4. Pagamento\n5. Fechar caixa\n6. Sair\n");

        if (!verifica_int(&opcao)) {}

        if (opcao == 1)
        {
            do
            {
                printf("Qual a categoria que voc� deseja acrescentar o produto:\n1. Limpeza\n2. Alimentos\n3. Padaria\n4. Outros\nEscolha: ");
                if (!verifica_int(&escolha_acrescenta_produtos))
                {
                    printf("Entrada inv�lida! Tente novamente.\n");
                    continue; // Volta para o in�cio do loop se a entrada for inv�lida
                }



                switch (escolha_acrescenta_produtos)
                {
                case 1:
                    escrever_log("Op��o selecionada: %d", escolha_acrescenta_produtos);
                    cadastrarProduto(&produtos, &contador,&capacidade,ID_LIMPEZA);
                    break;
                case 2:
                    escrever_log("Op��o selecionada: %d", escolha_acrescenta_produtos);
                    cadastrarProduto(&produtos, &contador,&capacidade,ID_ALIMENTOS);
                    break;
                case 3:
                    escrever_log("Op��o selecionada: %d", escolha_acrescenta_produtos);
                    cadastrarProduto(&produtos, &contador,&capacidade,ID_PADARIA);
                    break;
                case 4:
                    escrever_log("Op��o selecionada: %d", escolha_acrescenta_produtos);
                    cadastrarProduto(&produtos, &contador,&capacidade,ID_OUTROS);
                    break;

                default:
                    escrever_log("Erro: Op��o inv�lida na categoria de cadastro - %d", escolha_acrescenta_produtos);
                    printf("Op��o inv�lida! Tente novamente.\n");
                    continue;
                }
            }
            while (escolha_acrescenta_produtos < 1 || escolha_acrescenta_produtos > 4);    // Continua at� uma op��o v�lida
        }
        else if (opcao == 2) {
            system("cls");
            printf("Qual a categoria que você deseja Visualizar?\n");
            printf("1. Produtos de limpeza\n");
            printf("2. Alimentos\n");
            printf("3. Padaria\n");
            printf("4. Outros\n");
            printf("5. Todos\n");

            if(!verifica_int(&opc_exibir_produtos)) {
                printf("Digite um valor válido");
                sleep(2);
                continue;
            }

            // NOVO SUBMENU DE ORDENAÇÃO
            int criterio = 0;
            if (opc_exibir_produtos >= 1 && opc_exibir_produtos <= 5) {
                printf("\nComo deseja ordenar os produtos?\n");
                printf("0. Sem ordenação\n");
                printf("1. Ordenar por ID\n");
                printf("2. Ordenar por Nome\n");
                printf("3. Ordenar por Preço\n");
                printf("Escolha: ");
                
                int opc_ordenacao;
                if (verifica_int(&opc_ordenacao) && opc_ordenacao >= 0 && opc_ordenacao <= 3) {
                    criterio = opc_ordenacao;
                }
            }

            switch(opc_exibir_produtos) {
                case 1:
                    listarProdutos(NOME_ARQUIVO_LIMPEZA, ID_LIMPEZA, criterio);
                    system("pause");
                    break;
                case 2:
                    listarProdutos(NOME_ARQUIVO_ALIMENTOS, ID_ALIMENTOS, criterio);
                    system("pause");
                    break;
                case 3:
                    listarProdutos(NOME_ARQUIVO_PADARIA, ID_PADARIA, criterio);
                    system("pause");
                    break;
                case 4:
                    listarProdutos(NOME_ARQUIVO_OUTROS, ID_OUTROS, criterio);
                    system("pause");
                    break;
                case 5:
                    listarProdutos(NOME_ARQUIVO_PRODUTOS, ID_TODOS, criterio);
                    system("pause");
                    break;
                default:
                    printf("Categoria inválida!\n");
                    sleep(2);
                    break;
            }
        }
        else if (opcao == 3)
        {
            escrever_log("Op��o selecionada: %d", opcao);
            system("cls");
            abertura_caixa(&valor_total_caixa,&valor_inicial_caixa);
        }
        else if (opcao == 4)
        {
            escrever_log("Op��o selecionada: %d", opcao);
            system("cls");
            Adicionar_Carrinho(&vlr_tt_compra, &vlr_tt_limpeza, &vlr_tt_alimentos, &vlr_tt_padaria, &vlr_tt_outros,&valor_total_caixa,&valor_inicial_caixa,produtos,&contador);
        }
        else if (opcao == 5)
        {
            escrever_log("Op��o selecionada: %d", opcao);
            system("cls");
            fechar_caixa(valor_inicial_caixa, vlr_tt_compra, &vlr_tt_limpeza, &vlr_tt_alimentos, &vlr_tt_padaria, &vlr_tt_outros);
        }
        else if (opcao  != 6)
        {
            escrever_log("Op��o selecionada: %d", opcao);
            printf("Op��o inv�lida! Tente novamente.\n");
            sleep(2);
        }
    }
    while (opcao != 6);
    escrever_log("Programa encerrado normalmente");
    printf("Programa encerrado.\n");
    free(produtos);
    return 0;
}

// ===========================================
// NOVAS FUNÇÕES PARA ORDENAÇÃO (QUICK SORT)
// ===========================================

// Compara por ID
int compararPorId(const void *a, const void *b) {
    const PRODUTO *prodA = (const PRODUTO *)a; // Faz o ponteiro void apontar para um PRODUTO
    const PRODUTO *prodB = (const PRODUTO *)b;
    return (prodA->Id - prodB->Id); // Compara os IDs dos produtos
}

// Compara por Nome
int compararPorNome(const void *a, const void *b) {
    const PRODUTO *prodA = (const PRODUTO *)a;
    const PRODUTO *prodB = (const PRODUTO *)b;
    return strcmp(prodA->Nome, prodB->Nome);
}

// Compara por Preço
int compararPorPreco(const void *a, const void *b) {
    const PRODUTO *prodA = (const PRODUTO *)a;
    const PRODUTO *prodB = (const PRODUTO *)b;
    if (prodA->preco < prodB->preco) return -1;
    if (prodA->preco > prodB->preco) return 1;
    return 0;
}

// Função Quick Sort
void quickSort(PRODUTO *produtos, int left, int right, int (*comparar)(const void*, const void*)) { // Função de ordenação para ordenar produtos
    int i = left, j = right;
    PRODUTO pivot = produtos[(left + right) / 2];
    PRODUTO temp;

    while (i <= j) {
        while (comparar(&produtos[i], &pivot) < 0) i++;
        while (comparar(&produtos[j], &pivot) > 0) j--;
        if (i <= j) {
            temp = produtos[i];
            produtos[i] = produtos[j];
            produtos[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quickSort(produtos, left, j, comparar);
    if (i < right) quickSort(produtos, i, right, comparar);
}
