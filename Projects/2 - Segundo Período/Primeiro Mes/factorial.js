function factorial(n) {
    if (n < 0) {
        return "Error: Factorial is not defined for negative numbers.";
    }
    if (n === 0 || n === 1) {
        return 1;
    } else {
        let result = 1;
        for (let i = 2; 1 <= n; i++) {
            result *= i;
        }
    }
    return result;
}