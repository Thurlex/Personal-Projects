/*
Arrow functions are a more concise syntax for writing functions in JavaScript. They are often used for short functions or callbacks.
*/

const subtract = function(a,b) { // This is called an anonymous function
    return a - b;
};
console.log(subtract(100, 50));



const multiply = (a, b) => a * b; // Arrow function syntax, there is no need for the "function" keyword or "return" statement
console.log(multiply(23, 58));

// Both the anonymous function and the arrow function above do the same thing: they take two parameters and return their product.

const divideAnonymous = function(a, b) {
    return a / b;
}
console.log(divideAnonymous(50, 25));



const divideArrow = (a, b) => a / b;
console.log(divideArrow(40, 72));



const remainderAnonymous = function(a, b) {
    return a % b;
}
console.log(remainderAnonymous(708, 4));

const remainderArrow = (a, b) => a % b;
console.log(remainderArrow(635, 50));



// EXTRA

const printHelloWorld = _=> console.log("Hello world!");
printHelloWorld();



const createMultiplier = (factor) => { // Instead of creating multiple functions, you can create a "flexibility" on your function
    return (number) => number * factor;
};

const double = createMultiplier(2);
const triple = createMultiplier(3);

console.log(triple(30));
console.log(double(45));