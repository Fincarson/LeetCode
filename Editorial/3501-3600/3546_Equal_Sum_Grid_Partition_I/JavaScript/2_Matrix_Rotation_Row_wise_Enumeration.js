var canPartitionGrid = function (grid) {
    let total = 0;
    let m = grid.length;
    let n = grid[0].length;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }
    for (let k = 0; k < 2; k++) {
        let sum = 0;
        m = grid.length;
        n = grid[0].length;
        for (let i = 0; i < m - 1; i++) {
            for (let j = 0; j < n; j++) {
                sum += grid[i][j];
            }
            if (sum * 2 === total) {
                return true;
            }
        }
        grid = rotation(grid);
    }
    return false;
};

function rotation(grid) {
    const m = grid.length,
        n = grid[0].length;
    const tmp = Array.from({ length: n }, () => Array(m).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            tmp[j][m - 1 - i] = grid[i][j];
        }
    }
    return tmp;
}
