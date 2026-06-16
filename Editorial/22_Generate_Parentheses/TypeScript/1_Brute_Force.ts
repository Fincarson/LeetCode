function generateParenthesis(n: number): string[] {
    let res: string[] = [];
    generate("", n, n, res);
    return res;
}
function generate(
    str: string,
    left: number,
    right: number,
    res: string[],
): void {
    if (!left && !right && str.length) {
        res.push(str);
        return;
    }
    if (left) generate(str + "(", left - 1, right, res);
    if (right > left) generate(str + ")", left, right - 1, res);
}
