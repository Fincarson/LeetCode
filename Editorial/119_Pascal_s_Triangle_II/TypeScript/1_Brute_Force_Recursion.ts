function getNum(row: number, col: number): number {
    if (row === 0 || col === 0 || row === col) {
        return 1;
    }
    return getNum(row - 1, col - 1) + getNum(row - 1, col);
}
function getRow(rowIndex: number): number[] {
    let ans: number[] = [];
    for (let i = 0; i <= rowIndex; i++) {
        ans.push(getNum(rowIndex, i));
    }
    return ans;
}
