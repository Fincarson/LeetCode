function evalRPN(tokens: string[]): number {
    const OPERATIONS = {
        "+": (a: number, b: number) => a + b,
        "-": (a: number, b: number) => a - b,
        "/": (a: number, b: number) => Math.trunc(a / b),
        "*": (a: number, b: number) => a * b,
    };
    let currentPosition = 0;
    while (tokens.length > 1) {
        while (!(tokens[currentPosition] in OPERATIONS)) {
            currentPosition += 1;
        }
        const operator = tokens[currentPosition];
        const operation = OPERATIONS[operator];
        const number1 = Number(tokens[currentPosition - 2]);
        const number2 = Number(tokens[currentPosition - 1]);
        tokens[currentPosition] = operation(number1, number2).toString();
        tokens.splice(currentPosition - 2, 2);
        currentPosition -= 1;
    }
    return Number(tokens[0]);
}
