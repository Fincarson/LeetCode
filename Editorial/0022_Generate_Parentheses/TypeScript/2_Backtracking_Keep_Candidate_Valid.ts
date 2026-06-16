function generateParenthesis(n: number): string[] {
    const answer: string[] = [];
    backtracking(answer, "", 0, 0, n);
    return answer;
}
function backtracking(
    answer: string[],
    curString: string,
    leftCount: number,
    rightCount: number,
    n: number,
): void {
    if (curString.length === 2 * n) {
        answer.push(curString);
        return;
    }
    if (leftCount < n) {
        curString += "(";
        backtracking(answer, curString, leftCount + 1, rightCount, n);
        curString = curString.slice(0, -1);
    }
    if (leftCount > rightCount) {
        curString += ")";
        backtracking(answer, curString, leftCount, rightCount + 1, n);
        curString = curString.slice(0, -1);
    }
}
