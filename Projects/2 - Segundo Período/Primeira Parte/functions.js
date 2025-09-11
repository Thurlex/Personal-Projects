/**
 * Unlike C, you can simply write "function yourFunction()"
 */

function hello(name) {
    const message = "Hello, " + name + "!";
    return message;
}

let greeting = hello("Alex");
console.log(greeting); // Output: Hello, Alex!


/*
* @param {string} city // Returns a greeting message for the specified city.
* @returns {string[]} // A list with different city names
*/
function listCities(city) {
    const cities = ["New York", "Los Angeles", "Chicago", "Houston", "Phoenix"];
    return cities.map(c => `Hello from ${c}!`);
}