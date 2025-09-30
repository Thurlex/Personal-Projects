/*
13. Operadores de Comparação

Dado o seguinte código JavaScript:

const a = 10;
const b = "10";
 


Responda no console:

    a é igual a b? (==)
    a é estritamente igual a b? (===)
    a é diferente de b? (!=)
    a é estritamente diferente de b? (!==)



*/

const a = 10;
const b = "10";

console.log("a eh igual a b?")
if(a == b) {
    console.log("Sim, a eh igual a b (==)");
}
else {
    console.log("Nao, a nao eh igual a b (==)");
}

console.log("a eh estritamente igual a b?");
if(a === b) {
    console.log("Sim, a eh estritamente igual a b (===)");
}
else {
    console.log("Nao, a nao eh estritamente igual a b (===)");
}

console.log("a eh diferente de b?");
if(a != b) {
    console.log("Sim, a eh diferente de b (!=)");
}
else {
    console.log("Nao, a nao eh diferente de b (!=)");
}

console.log("a eh estritamente diferente de b?");
if(a !== b) {
    console.log("Sim, a eh estritamente diferente de b (!==)");
}
else {
    console.log("Nao, a nao eh estritamente diferente de b (!==)");
}