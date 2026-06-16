// Next four directions.
let dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

// BFS function to do bfs starting from (row, col).
let bfs = (grid, row, col, totalHouses) => {
    let rows = grid.length;
    let cols = grid[0].length;
    let distanceSum = 0;
    let housesReached = 0;
    
    // Use a queue to do a bfs, starting from cell located at (row, col).
    let queue = [[ row, col ]];
    
    // Keep track of visited cells.
    let vis = new Array(rows).fill(false).map(() => new Array(cols).fill(false));
    vis[row][col] = true;
    
    let steps = 0;
    
    while (queue.length && housesReached != totalHouses) {
        // Record the cells that we will explore in the next level
        let next_queue = [];
        for (let i = 0; i < queue.length; i++) {
            let curr = queue[i];
            row = curr[0];
            col = curr[1];
            
            // If this cell is a house, then add the distance from source to this cell
            // and we go past from this cell.
            if (grid[row][col] == 1) {
                distanceSum += steps;
                housesReached++;
                continue;
            }
            
            // This cell was empty cell, hence traverse the next cells which is not a blockage.
            dirs.forEach((dir) => {
                let nextRow = row + dir[0];
                let nextCol = col + dir[1];
                if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                    if (!vis[nextRow][nextCol] && grid[nextRow][nextCol] != 2) {
                        vis[nextRow][nextCol] = true;
                        next_queue.push([nextRow, nextCol]);
                    }
                }
            });
        }
        
        // Set the queue equal to the next level queue.
        queue = next_queue;
        // After traversing one level cells, increment the steps by 1 to reach to next level.
        steps++;
    }
    
    // If we did not reach all houses, then any cell visited also cannot reach all houses.
    // Set all cells visted to 2 so we do not check them again and return MAX_VALUE.
    if (housesReached != totalHouses) {
        for (let row = 0; row < rows; row++) {
            for (let col = 0; col < cols; col++) {
                if (grid[row][col] == 0 && vis[row][col]) {
                    grid[row][col] = 2;
                }
            }
        }
        return Number.MAX_VALUE;
    }
    
    // If we have reached all houses then return the total distance calculated.
    return distanceSum;
};

let shortestDistance = function (grid) {
    let minDistance = Number.MAX_VALUE;
    let rows = grid.length;
    let cols = grid[0].length;
    let totalHouses = 0;
    
    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            if (grid[row][col] == 1) {
                totalHouses++;
            }
        }
    }
    
    // Find the min distance sum for each empty cell.
    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            if (grid[row][col] == 0) {
                minDistance = Math.min(minDistance, bfs(grid, row, col, totalHouses));
            }
        }
    }
    
    // If it is impossible to reach all houses from any empty cell, then return -1.
    if (minDistance == Number.MAX_VALUE) {
        return -1;
    }
    return minDistance;
};
