var generateMatrix = function (n) {
    const result = new Array(n).fill(0).map(() => new Array(n).fill(0));
    const dirs = [
        [0, 1],
        [1, 0],
        [0, -1],
        [-1, 0],
    ];
    let d = 0;
    let row = 0;
    let col = 0;
    let cnt = 1;
    while (cnt <= n * n) {
        result[row][col] = cnt++;
        let newRow = (row + (dirs[d][0] % n) + n) % n;
        let newCol = (col + (dirs[d][1] % n) + n) % n;
        //change direction if next cell is non zero
        if (result[newRow][newCol] != 0) d = (d + 1) % 4;
        row += dirs[d][0];
        col += dirs[d][1];
    }
    return result;
};
