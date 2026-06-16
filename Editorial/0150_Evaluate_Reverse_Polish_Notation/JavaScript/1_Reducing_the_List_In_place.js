const OPERATORS = {
    "+": (a, b) => a + b,
    "-": (a, b) => a - b,
    "/": (a, b) => Math.trunc(a / b),
    "*": (a, b) => a * b,
};

var evalRPN = function (tokens) {
    let currentPosition = 0;

    while (tokens.length > 1) {
        // Move the current position pointer to the next operator.
        while (!(tokens[currentPosition] in OPERATORS)) {
            currentPosition += 1;
        }

        const operator = tokens[currentPosition];
        const operation = OPERATORS[operator];
        const number1 = Number(tokens[currentPosition - 2]);
        const number2 = Number(tokens[currentPosition - 1]);

        tokens[currentPosition] = operation(number1, number2);

        // Remove the numbers and move the pointer to the position
        // after the new number we just added.
        tokens.splice(currentPosition - 2, 2);
        currentPosition -= 1;
    }

    return tokens[0];
};
