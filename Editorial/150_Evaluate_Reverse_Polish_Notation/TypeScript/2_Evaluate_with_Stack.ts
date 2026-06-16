function evalRPN(tokens: string[]): number {
    const OPERATORS = {
        "+": (a: number, b: number) => a + b,
        "-": (a: number, b: number) => a - b,
        "/": (a: number, b: number) => Math.trunc(a / b),
        "*": (a: number, b: number) => a * b,
    };
    const stack: number[] = [];
    for (const token of tokens) {
        if (token in OPERATORS) {
            const number2 = stack.pop() || 0;
            const number1 = stack.pop() || 0;
            const operation = OPERATORS[token];
            stack.push(operation(number1, number2));
        } else {
            stack.push(Number(token));
        }
    }
    return stack.pop() || 0;
}
