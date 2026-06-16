let triangle: number[][];
let memoTable = new Map<string, number>();
function minPath(row: number, col: number): number {
    let params = row + ":" + col;
    if (memoTable.has(params)) {
        return memoTable.get(params)!;
    }
    let path = triangle[row][col];
    if (row < triangle.length - 1) {
        path += Math.min(minPath(row + 1, col), minPath(row + 1, col + 1));
    }
    memoTable.set(params, path);
    return path;
}
function minimumTotal(triangleInput: number[][]): number {
    triangle = triangleInput;
    memoTable.clear();
    return minPath(0, 0);
}
