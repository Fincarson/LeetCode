let triangle;
let memoTable = new Map();
function minPath(row, col) {
    let params = row + ":" + col;
    if (memoTable.has(params)) {
        return memoTable.get(params);
    }
    let path = triangle[row][col];
    if (row < triangle.length - 1) {
        path += Math.min(minPath(row + 1, col), minPath(row + 1, col + 1));
    }
    memoTable.set(params, path);
    return path;
}
var minimumTotal = function (triangleInput) {
    triangle = triangleInput;
    memoTable.clear();
    return minPath(0, 0);
};
