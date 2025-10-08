/*
Cenário: Temos uma função que converte uma string para letras maiúsculas. 
No entanto, ela só funciona se o valor de entrada for realmente uma string. 
Se recebermos um número ou outro tipo de dado, a função toUpperCase() dará erro.
## Enunciado do Exercício: Conversor Seguro

Desafio: Você receberá uma lista com vários tipos de dados. 
Sua tarefa é percorrer essa lista e tentar converter cada item para letras maiúsculas.

Use um bloco try...catch.
Dentro do try, tente converter o item para maiúsculas (item.toUpperCase()) e exiba 
o resultado no console.
Se ocorrer um erro (porque o item não é uma string), o bloco catch deve ser executado, 
e você deve exibir a mensagem: "Opa! O valor '[valor do item]' não é uma string."
*/


// Lista de dados para processar
const listaDeDados = ["maçã", "banana", 123, "laranja", null, "uva"];
 
// Percorra a lista e realize as tentativas
 
console.log("Início do processamento da lista...");
for (let item of listaDeDados) {
    try {
        // Tente converter o item para maiúsculas
        const resultado = item.toUpperCase();
        console.log(`Resultado: ${resultado}`);
    } catch (error) {
        // Se ocorrer um erro, capture-o e exiba a mensagem personalizada
        console.log(`Opa! O valor '${item}' não é uma string.`);
    }
}
console.log("Processamento da lista concluído.");