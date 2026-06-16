let cache: { [key: string]: number } = {};
function getNum(row: number, col: number): number {
    let rowCol = [row, col].toString();
    if (cache[rowCol]) {
        return cache[rowCol];
    }
    if (row == 0 || col == 0 || row == col) {
        cache[rowCol] = 1;
        return 1;
    }
    cache[rowCol] = getNum(row - 1, col - 1) + getNum(row - 1, col);
    return cache[rowCol];
}
function getRow(rowIndex: number): number[] {
    let ans: number[] = [];
    for (let i = 0; i <= rowIndex; i++) {
        ans.push(getNum(rowIndex, i));
    }
    return ans;
}
