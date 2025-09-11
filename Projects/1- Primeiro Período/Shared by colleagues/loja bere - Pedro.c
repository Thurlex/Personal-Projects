#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <unistd.h>



#define MAX_PRODUTOS 5
#define MAX_NOME 53
#define VALOR_MINIMO_CAIXA 200

//------------------------------------------------------------------Vetores para armazenar os produtos de cada categoria---------------------------------------------------------------------------------------------------//

int idLimpeza[MAX_PRODUTOS], idAlimentos[MAX_PRODUTOS], idPadaria[MAX_PRODUTOS], idOutros[MAX_PRODUTOS];
char nomesLimpeza[MAX_PRODUTOS][MAX_NOME], nomesAlimentos[MAX_PRODUTOS][MAX_NOME], nomesPadaria[MAX_PRODUTOS][MAX_NOME], nomesOutros[MAX_PRODUTOS][MAX_NOME];
float precosLimpeza[MAX_PRODUTOS], precosAlimentos[MAX_PRODUTOS], precosPadaria[MAX_PRODUTOS], precosOutros[MAX_PRODUTOS];
int quantidadesLimpeza[MAX_PRODUTOS], quantidadesAlimentos[MAX_PRODUTOS], quantidadesPadaria[MAX_PRODUTOS], quantidadesOutros[MAX_PRODUTOS];

int contLimpeza = 0, contAlimentos = 0, contPadaria = 0, contOutros = 0, id = 1;
float valor_caixa = 0, valor_total_compra = 0, vAlimentos = 0, vLimpeza = 0, vPadaria = 0, vOutros = 0;

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




int lerNumero(int *numero)
{

    int resultado;
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
void cadastrarProduto( int ids[], char nomes[][MAX_NOME], float precos[], int quantidades[], int *contador)
{
    int numero = 0;
    int escolha = 0;
    int continuar = 1;


    if (*contador >= MAX_PRODUTOS)
    {
        printf("Limite de produtos atingido!\n");
        sleep(2);
        return;
    }

    limparBuffer(); // Limpa buffer antes de capturar a string

    while(1)
    {
        printf("Nome do produto: ");
        fgets(nomes[*contador], MAX_NOME, stdin);
        nomes[*contador][strcspn(nomes[*contador], "\n")] = '\0';

        if (!verificastring(nomes[*contador]))
        {
            printf("Nome inválido! Não use números ou símbolos. Tente novamente.\n");
            sleep(1);
            system("cls");
            continue;
        }

        break;
    }


    while (1)
    {
        printf("Preço: ");

        if (!lerFloat(&precos[*contador]))//Verifica o retorno da função, ou seja, se ele for 0 ou falso, ele cai no if
        {
            precos[*contador] = 0;
            system("cls");
            printf("Por favor, não tente digitar letras em preço ou outro caracter inválido\n");
            sleep(2);
            system("cls");
            continue;
        }

        if (precos[*contador] <= 0)
        {
            printf("\nVocê tem certeza que deseja cadastrar o produto com preço R$ 0,00?\n");
            printf("1. Sim\n");
            printf("2. Não, quero digitar de novo\n");
            printf("Escolha: ");
            scanf("%d", &escolha);

            if (escolha == 1)
            {
                break; // Sai do loop e continua
            }
            else if (escolha == 2)
            {
                precos[*contador] = -1; // Zera o valor para segurança (não obrigatório)
                continue; // Volta pro início do loop e pede o preço de novo
            }
            else
            {
                printf("Opção inválida! Tente novamente.\n");
                sleep(2);
            }
        }
        break;
    }



    while (1)
    {
        printf("Quantidade: ");

        if (!lerNumero(&quantidades[*contador]))
        {
            printf("Quantidade inválida! Digite apenas numeros\n");
            quantidades[*contador] = 0;
            sleep(1);
            system("cls");
            continue;
        }


        break;
    }




    if (quantidades[*contador] <= 0)
    {
        system("cls");
        printf("Você não pode acrescentar quantidade 0. Por favor, tente denovo!\n\n");
        system("cls");
        quantidades[*contador] = -1;
        sleep(1);
    }


    ids[*contador] = id++;
    (*contador)++;

    printf("Produto cadastrado com sucesso!\n\n");
    sleep(2);
    system("cls");
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------//

//----------------------------------------------------------------------Função para exibir produtos------------------------------------------------------------------------------------------------//

void exibirProdutos(int ids[],char nomes[][MAX_NOME], float precos[], int quantidades[], int contador, char *titulo)
{
    int i;


    printf("=== %s === \n", titulo);
    if (contador == 0)
    {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    for (i = 0; i < contador; i++)
    {
        printf("%d. %s - R$%.2f - %d unidades\n", ids[i], nomes[i], precos[i], quantidades[i]);
    }


}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------//


void abertura_caixa(int valor_inicial_caixa)
{
    int escolha = 0;




    do
    {

        if (valor_caixa > 0)
        {
            escolha = 0;
            system("cls");
            printf("Você já tem %.2fR$ em caixa, deseja continuar com esse valor ou acrescentar um valor novo?\n", valor_caixa);
            printf("1. Continuar e sair\n");
            printf("2. Acrescentar novo valor\n");
            if (!lerNumero(&escolha))
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
                valor_caixa = 0;
                abertura_caixa(valor_inicial_caixa);
                return;
            }
            break;
        }
        valor_caixa = 0;
        system("cls");
        printf("Digite o valor para iniciar o caixa: R$");
        if (!lerFloat(&valor_caixa))
        {
            printf("Você não pode começar com isso, por favor digite novamente!\n");
            sleep(1);
            continue;
        }
        valor_inicial_caixa = valor_caixa;

        if (valor_caixa <= 0)
        {
            printf("Você precisa iniciar o dia ao menos com algum valor maior que 0!\n");
            sleep(1);
            continue;
        }

        escolha = 0;
        if (valor_caixa <  VALOR_MINIMO_CAIXA)
        {
            printf("Aviso: iniciar com menos de R$200 pode causar dificuldades.\n");
            printf("Deseja continuar?\n1. Sim\n2. Digitar novamente\nEscolha: ");
            if (!lerNumero(&escolha))
            {
                printf("Escolha inválida!\n");
                sleep(1);
                continue;
            }

            if (escolha == 1)
            {

                break;
            }
            else
            {
                valor_caixa = 0;
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
        escolha = 0;
        system("cls");
        printf("Você iniciará o dia com R$%.2f\nConfirmar?\n1. Sim\n2. Não\nEscolha: ", valor_caixa);
        if (!lerNumero(&escolha))
        {
            printf("Digite uma resposta válida\n");
            sleep(1);
            continue;
        }

        if (escolha == 1)
        {
            printf("Caixa aberto com sucesso! você irá começar com R$%.2f\n", valor_caixa);
            sleep(2);
            break;
        }
        else if (escolha == 2)
        {
            valor_caixa = 0;
            abertura_caixa(valor_caixa);
            return;
        }
        else
        {
            printf("Opção inválida!\n");
            sleep(1);
        }

    }
    while (escolha != 1);
}

//----------------------------------------------------------------Abertura de caixa--------------------------------------------------------------------------------

int Carrinho()
{
    int escolha = 0, qtd = 0, encontrado = 0, continuar = 0 ;

    if (valor_caixa <= 0)
    {
        system("cls");
        printf("Por favor, primeiro inicie o dia com algum valor no caixa!\n");
        sleep(2);
        system("cls");
        return 0;

    }

    if (id == 1)
    {
        printf("Nem um produto Cadastrado, por favor cadastre um produto!");
        sleep(2);
        return 0;
    }


    exibirProdutos(idLimpeza,nomesLimpeza, precosLimpeza, quantidadesLimpeza, contLimpeza, "Material de limpeza ");
    exibirProdutos(idAlimentos,nomesAlimentos, precosAlimentos, quantidadesAlimentos, contAlimentos, "Alimentos");
    exibirProdutos(idPadaria,nomesPadaria, precosPadaria, quantidadesPadaria, contPadaria, "Padaria");
    exibirProdutos(idOutros,nomesOutros, precosOutros, quantidadesOutros, contOutros, "Outros");
    while (1)
    {

        printf("\n\n========= Carrinho ===========\n\n");
        printf("Digite apenas o ID do produto\n");



        if (!lerNumero(&escolha))
        {
            system("cls");
            printf("Digite uma opção válida");
            continue;
        }



// Verifica se o ID existe em alguma das categorias
        for (int i = 0; i < contLimpeza; i++)
        {
            if (idLimpeza[i] == escolha)
            {
                encontrado = 1;
                printf("Produto encontrado!\n\n");
                sleep(1);
                break;
            }
        }
        for (int i = 0; i < contAlimentos && !encontrado; i++)
        {
            if (idAlimentos[i] == escolha)
            {
                encontrado = 1;
                printf("Produto encontrado!\n\n");
                sleep(1);
                break;
            }
        }
        for (int i = 0; i < contPadaria && !encontrado; i++)
        {
            if (idPadaria[i] == escolha)
            {
                encontrado = 1;
                printf("Produto encontrado!\n\n");
                sleep(1);
                break;
            }
        }
        for (int i = 0; i < contOutros && !encontrado; i++)
        {
            if (idOutros[i] == escolha)
            {
                encontrado = 1;
                printf("Produto encontrado!\n\n");
                sleep(1);
                break;
            }
        }

        if (!encontrado)
        {
            printf("Id não encontrado, verifique se esse produto está cadastrado!\n");
            sleep(1);
            continue;
        }

        while (1)
        {
            printf("Agora digite a quantidade que deseja descontar desse produto: ");
            if (!lerNumero(&qtd))
            {
                printf("Valor inválido, digite um valor válido.\n");
                sleep(1);
                continue;
            }

            if (qtd <= 0)
            {
                printf("Você não pode descontar quantidade igual ou menor que 0. Tente novamente.\n");
                sleep(1);
                continue;
            }

            encontrado = 0;

            // ================== Limpeza ===================
            for (int i = 0; i < contLimpeza; i++)
            {
                if (idLimpeza[i] == escolha)
                {
                    encontrado = 1;
                    if (quantidadesLimpeza[i] >= qtd)
                    {
                        escolha -= 1;
                        quantidadesLimpeza[i] -= qtd;
                        printf("Produto %s Adicionado ao carrinho!\n", nomesLimpeza[i]);
                        valor_total_compra += qtd * precosLimpeza[escolha];
                        sleep(1);

                        // Se zerar o estoque
                        if (quantidadesLimpeza[i] == 0)
                        {
                            escolha -= 1;
                            printf("O estoque do produto acabou!\n");
                            precosLimpeza[escolha] = 0;
                            memset(nomesLimpeza, 0, sizeof(nomesLimpeza));
                            idLimpeza[escolha] = 0;
                            sleep(1);
                            contLimpeza--;
                        }


                        sleep(2);
                        limparBuffer();
                        forma_de_pagamento();
                        return 1;
                    }
                    else
                    {
                        printf("Quantidade insuficiente em estoque! Estoque atual: %d\n", quantidadesLimpeza[i]);
                        sleep(2);
                        break;
                    }
                }
            }

            // ================== Alimentos ===================
            for (int i = 0; i < contAlimentos && !encontrado; i++)
            {
                if (idAlimentos[i] == escolha)
                {
                    encontrado = 1;
                    if (quantidadesAlimentos[i] >= qtd)
                    {
                        escolha -= 1;
                        quantidadesAlimentos[i] -= qtd;
                        printf("Produto %s Adicionado ao carrinho!\n", nomesAlimentos[i]);
                        valor_total_compra += qtd * precosAlimentos[escolha];
                        printf("%f", valor_total_compra);
                        sleep(1);

                        if (quantidadesAlimentos[i] == 0)
                        {
                            escolha -= 1;
                            printf("O estoque do produto acabou!\n");
                            precosAlimentos[escolha] = 0;
                            memset(nomesAlimentos, 0, sizeof(nomesAlimentos));
                            idAlimentos[escolha] = 0;
                            sleep(1);
                            contAlimentos--;
                        }


                    }

                    sleep(2);
                    limparBuffer();
                    forma_de_pagamento();
                    return 1;

                }
                else
                {
                    printf("Quantidade insuficiente em estoque! Estoque atual: %d\n", quantidadesAlimentos[i]);
                    sleep(2);
                    break;
                }
            }
        }

        // ================== Padaria ===================
        for (int i = 0; i < contPadaria && !encontrado; i++)
        {
            if (idPadaria[i] == escolha)
            {
                encontrado = 1;
                if (quantidadesPadaria[i] >= qtd)
                {
                    escolha -= 1;
                    quantidadesPadaria[i] -= qtd;
                    printf("Produto %s Adicionado ao carrinho!\n", nomesPadaria[i]);
                    valor_total_compra += qtd * precosPadaria[escolha];
                    printf("%f", valor_total_compra);
                    sleep(1);

                    if (quantidadesPadaria[i] == 0)
                    {

                        escolha -= 1;
                        printf("O estoque do produto acabou!\n");
                        precosPadaria[escolha] = 0;
                        memset(nomesPadaria, 0, sizeof(nomesPadaria));
                        idPadaria[escolha] = 0;
                        sleep(1);
                        contPadaria--;
                    }


                }
                sleep(2);
                limparBuffer();
                forma_de_pagamento();
                return 1;

            }

            else
            {
                printf("Quantidade insuficiente em estoque! Estoque atual: %d\n", quantidadesPadaria[i]);
                sleep(2);
                break;
            }
        }
    }



    // ================== Outros ===================
    for (int i = 0; i < contOutros && !encontrado; i++)
    {
        if (idOutros[i] == escolha)
        {
            encontrado = 1;
            if (quantidadesOutros[i] >= qtd)
            {
                escolha -= 1;
                quantidadesOutros[i] -= qtd;
                printf("Produto %s Adicionado ao carrinho!\n", nomesOutros[i]);
                valor_total_compra += qtd * precosOutros[escolha];
                printf("%f", valor_total_compra);
                sleep(1);

                if (quantidadesOutros[i] == 0)
                {
                    escolha -= 1;
                    printf("O estoque do produto acabou!\n");
                    quantidadesOutros[escolha] = 0;
                    memset(nomesOutros, 0, sizeof(nomesOutros));
                    idOutros[escolha] = 0;
                    sleep(1);
                    contOutros--;
                }


                sleep(2);
                limparBuffer();
                forma_de_pagamento();
                return 1;

            }
            else
            {
                printf("Quantidade insuficiente em estoque! Estoque atual: %d\n", quantidadesOutros[i]);
                sleep(2);
                break;
            }
        }
    }


    if (!encontrado)
    {
        printf("Produto não encontrado!\n");
        sleep(2);

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
            Carrinho();
            break;
        case 2:
            break;
        default:
            printf("Opção inválida\n");


        }

    }


}

void forma_de_pagamento()
{
    int metodo_pagamento = 0, confirma_pagamento = 0, percentual_desconto = 0;
    float valor_pago = 0, desconto = 0, total_com_desconto = 0;
    float troco = 0,falta_pagar = 0;

    if (valor_total_compra <= 0)
    {
        printf("Você não pode pagar uma compra com o valor de 0 reais");
        sleep(2);
        system("cls");
        forma_de_pagamento();
    }


    do
    {
        system("cls");
        printf("============ Pagamento ==========\n");
        printf("Valor total da compra: R$%.2f\n", valor_total_compra);
        printf("Escolha o método de pagamento:\n");
        printf("1. Dinheiro/Pix\n2. Cartão de crédito/Cartão de debito\n3. Acrescentar mais produtos ao carrinho\n");
        printf("Escolha: ");

        if (!lerNumero(&metodo_pagamento))
        {
            printf("Digite uma opção válida\n");
            sleep(1);
            forma_de_pagamento();
        }

        switch(metodo_pagamento)
        {
        case 1:
            system("cls");


            if (valor_total_compra >= 200.00)
            {
                printf("Compra acima de R$ 200.00. Aplicar desconto customizado.\n");
                do
                {
                    printf("Digite o percentual de desconto (0-100): ");
                    if(!lerNumero(&percentual_desconto))
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
                desconto = valor_total_compra * (percentual_desconto / 100.0); // Calcula o desconto
                printf("Desconto de %.2f%% aplicado.\n", percentual_desconto);

            }
            else if (valor_total_compra > 50.00 && valor_total_compra < 200)     // Desconto de 50.01 até 199.99
            {
                desconto = valor_total_compra * 0.10; // 10% de desconto
                printf("Desconto de 10%% aplicado.\n");

            }
            else if (valor_total_compra <= 50.00)     // Desconto para até exatamente 50.00
            {
                desconto = valor_total_compra * 0.05; // 5% de desconto
                printf("Desconto de 5%% aplicado.\n");
            }

            if (desconto > 0)
            {
                total_com_desconto = valor_total_compra - desconto; // Calcula o total com desconto
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
                valor_caixa -= troco;
                printf("Retorne a ele %.2f de troco\n", troco);
                system("pause");
                system("cls");
                printf("Você tem %.2f em caixa", valor_caixa);
                sleep(1);
                return;
            }
            else if (valor_pago < total_com_desconto)
            {
                falta_pagar = total_com_desconto - valor_pago;
                printf("Falta pagar %.2f", falta_pagar);
                continue;
            }

            printf("Pagamento de R$ %.2f realizado com sucesso via Dinheiro!\n", total_com_desconto);
            system("pause");
            return;
            }

        case 2:
            system("cls");
            printf("Valor total da compra: R$%.2f\n", valor_total_compra);
            printf("insira ou aproxime o cartão!\n pressione qualquer tecla...\n");
            getchar();
            getchar();
            printf("===== Confirmação de forma de pagamento =======\n");
            printf("1. Pagamento confirmado \n0. Ocorreu um erro no pagamento. Digitar outra forma de pagamento\n");
            if(!lerNumero(&confirma_pagamento))
            {
                printf("Digite uma opção válida!");
                sleep(1);
            }

            if (confirma_pagamento == 1)
            {
                printf("Pagamento de R$ %.2f realizado com sucesso no Cartão!\n", valor_total_compra);
                sleep(1);
                return;
            }
            else if (confirma_pagamento == 0)
            {
                forma_de_pagamento();
                break;
            }
            else
            {
                printf("opção inválida, digite novamente!");
                continue;
            }


        case 3:
            printf("Retornando ao carrinho...");
            sleep(1);
            system("cls");
            break;

        default:
            printf("opção inválida!");
            sleep(1);
        }



    } while(metodo_pagamento != 3);
    Carrinho();
}

void fechar_caixa(int valor_inicial_caixa)
{

    printf("1. Valor (R$) de Abertura – R$%f", valor_inicial_caixa);
    printf("\n2. Valor (R$) de Fechamento – R$%.2f", valor_caixa);
    printf("\n3. Total de vendas – R$%.2f", valor_total_compra);
    printf("\n4. Total de produtos vendidos – %d", contLimpeza + contAlimentos + contPadaria + contOutros);
    printf("\n5. Faturamento total – R$%.2f", valor_caixa - valor_inicial_caixa);
    printf("\n\n ---------------- Faturamento por Categoria ----------------\n\n");
    printf("Material de Limpeza: R$%.2f\n", contLimpeza);


}


int main()
{
    int escolha = 0;
    int numero;
    int opcao, categoria, opc_exibir_produtos;
    float valor_inicial_caixa = 0;
    setlocale(LC_ALL, "Portuguese");
    system("cls");



    do
    {
        system("cls");
        printf("\n===== MENU MERCADINHO =====\n");
        printf("1. Cadastrar Produto\n2. Exibir Produtos\n3. Abrir ao caixa\n4. Pagamento\n5. Fechar caixa\n6. Sair\n");

        if (!lerNumero(&opcao))
        {

        }


        if (opcao == 1)
        {
            system("cls");
            printf("\nEscolha a categoria:\n");
            printf("1. Material de Limpeza\n");
            printf("2. Alimentos\n");
            printf("3. Padaria\n");
            printf("4. Outros Produtos\n");
            printf("Categoria: ");
            if (!lerNumero(&categoria))
            {
                printf("digite um valor válido");
                sleep(2);
                continue;
            }



            switch (categoria)
            {
            case 1:
                cadastrarProduto(idLimpeza,nomesLimpeza, precosLimpeza, quantidadesLimpeza, &contLimpeza);
                break;
            case 2:
                cadastrarProduto(idAlimentos,nomesAlimentos, precosAlimentos, quantidadesAlimentos, &contAlimentos);
                break;
            case 3:
                cadastrarProduto(idPadaria,nomesPadaria, precosPadaria, quantidadesPadaria, &contPadaria);
                break;
            case 4:
                cadastrarProduto(idOutros,nomesOutros, precosOutros, quantidadesOutros, &contOutros);
                break;
            default:
                printf("Categoria inválida!\n");
                sleep(2);
            }
        }
        else if (opcao == 2)
        {

            system("cls");
            printf("Qual a categoria que você deseja Visualizar?\n");
            printf("1. Produtos de limpeza\n");
            printf("2. Alimentos\n");
            printf("3. Padaria\n");
            printf("4. Outros\n");
            scanf("%d", &opc_exibir_produtos);

            switch(opc_exibir_produtos)
            {
            case 1:
                system("cls");
                exibirProdutos(idLimpeza,nomesLimpeza, precosLimpeza, quantidadesLimpeza, contLimpeza, "Material de Limpeza");
                system("pause");
                break;
            case 2:
                system("cls");
                exibirProdutos(idAlimentos,nomesAlimentos, precosAlimentos, quantidadesAlimentos, contAlimentos, "Alimentos");
                system("pause");
                break;
            case 3:
                system("cls");
                exibirProdutos(idPadaria,nomesPadaria, precosPadaria, quantidadesPadaria, contPadaria, "Padaria");
                system("pause");
                break;
            case 4:
                system("cls");
                exibirProdutos(idOutros,nomesOutros, precosOutros, quantidadesOutros, contOutros, "Outros Produtos");
                system("pause");
                break;

            default:
                printf("Categoria inválida!\n");
                sleep(2);

            }



        }
        else if (opcao == 3)
        {
            abertura_caixa(valor_inicial_caixa);
        }

        else if (opcao == 4)
        {
            system("cls");
            Carrinho();


        }
        else if (opcao == 5)
        {
            system("cls");
            fechar_caixa(valor_inicial_caixa);


        }








        else if (opcao  != 6)
        {


            printf("Opção inválida! Tente novamente.\n");
            sleep(2);

        }





    }
    while (opcao != 6);

    printf("Programa encerrado.\n");
    return 0;


}
