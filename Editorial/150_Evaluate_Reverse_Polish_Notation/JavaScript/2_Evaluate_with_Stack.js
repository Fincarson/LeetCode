const OPERATORS = {
    "+": (a, b) => a + b,
    "-": (a, b) => a - b,
    "/": (a, b) => Math.trunc(a / b),
    "*": (a, b) => a * b,
};

var evalRPN = function (tokens) {
    const stack = [];

    for (const token of tokens) {
        if (token in OPERATORS) {
            const number2 = stack.pop();
            const number1 = stack.pop();
            const operation = OPERATORS[token];
            stack.push(operation(number1, number2));
        } else {
            stack.push(Number(token));
        }
    }

    return stack.pop();
};
