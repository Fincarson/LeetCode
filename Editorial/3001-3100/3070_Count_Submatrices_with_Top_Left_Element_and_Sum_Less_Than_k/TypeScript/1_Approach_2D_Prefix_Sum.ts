function countSubmatrices(grid: number[][], k: number): number {
    const m: number = grid.length;
    const n: number = grid[0].length;
    const cols: number[] = new Array(n).fill(0);
    let res: number = 0;

    for (let i = 0; i < m; i++) {
        let rows: number = 0;
        for (let j = 0; j < n; j++) {
            cols[j] += grid[i][j];
            rows += cols[j];
            if (rows <= k) {
                res++;
            }
        }
    }

    return res;
}
