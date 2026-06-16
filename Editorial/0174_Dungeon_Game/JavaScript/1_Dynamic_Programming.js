var calculateMinimumHP = function (dungeon) {
    let rows = dungeon.length,
        cols = dungeon[0].length;
    let dp = Array(rows)
        .fill()
        .map(() => Array(cols).fill(Number.MAX_SAFE_INTEGER));

    const get_min_health = (currCell, nextRow, nextCol) => {
        if (nextRow >= rows || nextCol >= cols) {
            return Number.MAX_SAFE_INTEGER;
        }
        let nextCell = dp[nextRow][nextCol];
        // hero needs at least 1 point to survive
        return Math.max(1, nextCell - currCell);
    };

    for (let row = rows - 1; row >= 0; --row) {
        for (let col = cols - 1; col >= 0; --col) {
            let currCell = dungeon[row][col];

            let right_health = get_min_health(currCell, row, col + 1);
            let down_health = get_min_health(currCell, row + 1, col);
            let next_health = Math.min(right_health, down_health);

            let min_health;
            if (next_health !== Number.MAX_SAFE_INTEGER) {
                min_health = next_health;
            } else {
                min_health = currCell >= 0 ? 1 : 1 - currCell;
            }

            dp[row][col] = min_health;
        }
    }

    return dp[0][0];
};
