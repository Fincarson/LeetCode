function getRow(n: number): number[] {
    let row = [1];
    for (let k = 1; k <= n; k++) {
        row.push(Math.floor((row[row.length - 1] * (n - k + 1)) / k));
    }
    return row;
}
