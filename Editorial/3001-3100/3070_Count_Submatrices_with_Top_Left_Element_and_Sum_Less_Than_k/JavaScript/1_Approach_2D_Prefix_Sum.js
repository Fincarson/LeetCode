var countSubmatrices = function (grid, k) {
    const m = grid.length;
    const n = grid[0].length;
    const cols = new Array(n).fill(0);
    let res = 0;

    for (let i = 0; i < m; i++) {
        let rows = 0;
        for (let j = 0; j < n; j++) {
            cols[j] += grid[i][j];
            rows += cols[j];
            if (rows <= k) {
                res++;
            }
        }
    }

    return res;
};
