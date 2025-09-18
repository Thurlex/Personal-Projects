

/*
Exercícios de JavaScript: Objetos, JSON e Local Storage

    Crie um objeto JavaScript chamado produto com as seguintes propriedades: id (número), nome (string), preco (número) e disponivel (booleano).
    Crie um array de objetos chamado listaDeProdutos, onde cada objeto representa um produto de mercado com as propriedades do exercício 1.
    Adicione 5 produtos diferentes ao array listaDeProdutos.
    Converta o array listaDeProdutos em uma string JSON.
    Salve a string JSON no Local Storage do navegador com a chave produtos.
    Recupere a string JSON do Local Storage.
    Converta a string JSON de volta para um array de objetos JavaScript.
    Acesse e imprima no console o nome do terceiro produto da lista.
    Altere o preço do primeiro produto da lista para um novo valor.
    Converta o array de produtos modificado de volta para uma string JSON e atualize o valor no Local Storage.
*/


// Produtos de 1 ate 5
// Array com todos os objetos criados
let listaDeProdutos = [
produto001 = {id: 0o1, nome: "Bolo de Baunilha ",preco:  25,disponivel: true},

produto002 = {id: 0o2, nome: "Pão Caseiro", preco: 1, disponivel: true},

produto003 = {id: 0o3, nome: "Pão Francês", preco: 6, disponivel: false},

produto004 = {id: 0o4, nome: "Biscoito Passatempo", preco: 5, disponivel: true},

produto005 = {id: 0o5, nome: "Cachorro Quente", preco: 8, disponivel: true},
];
console.log("Criação do array e produtos completa com sucesso.");

// Utilizando o comando localStorage.setItem, criamos a key Produtos
// ao mesmo tempo, adicionamos a listaDeProdutos à ela utilizando o comando JSON,stringify
localStorage.setItem('Produtos', JSON.stringify(listaDeProdutos));
console.log("listaDeProdutos transformada em string e guardada na chave Produtos com sucesso.");

// "Pega" a lista e transfere para uma variavel let
let recuperaLista = localStorage.getItem('Produtos');
console.log("Variável recuperaLista criada, recebe os valores.");

// Converte a lista de volta para um objeto em JS pelo comando parse
let parsedLista1 = JSON.parse(recuperaLista);
console.log("parsedLista1 criada com sucesso. JSON.parse realizado com sucesso.");

console.log(parsedLista1);
console.log(typeof parsedLista1);

console.log(`O nome do terceiro produto em parsed lista eh "${parsedLista1[2].nome}"`);
console.log("Nome do terceiro produto em parsedLista1 feito com sucesso.");


//Estes comandos entram em conflito com o codigo principal

localStorage.removeItem(Produtos);
console.log("Chave Produtos removida com sucesso.");

localStorage.setItem(Produtos, parsedLista1);
let parsedLista2 = localStorage.getItem(Produtos);

console.log(parsedLista2);
console.log(typeof parsedLista2);
