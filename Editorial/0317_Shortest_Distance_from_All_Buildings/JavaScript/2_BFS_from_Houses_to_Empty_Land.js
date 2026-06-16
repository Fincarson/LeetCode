let dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

let bfs = function (grid, distances, row, col) {
    let rows = grid.length;
    let cols = grid[0].length;

    // Use a queue to do a BFS, starting from cell at (row, col).
    let queue = [[ row, col ]];

    // Keep track of visited cells
    let vis = new Array(rows).fill(false).map(() => new Array(cols).fill(false));
    vis[row][col] = true;

    let steps = 0;

    while (queue.length) {
        // Record the cells that we will explore in the next level
        let next_queue = [];

        for (let i = 0; i < queue.length; i++) {
            let curr = queue[i];

            row = curr[0];
            col = curr[1];

            // If we reached an empty cell, then add the distance
            // and increment the count of houses reached at this cell.
            if (grid[row][col] == 0) {
                distances[row][col][0] += steps;
                distances[row][col][1]++;
            }

            // Traverse the next cells which is not a blockage.
            dirs.forEach((dir) => {
                let nextRow = row + dir[0];
                let nextCol = col + dir[1];

                if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                    if (!vis[nextRow][nextCol] && grid[nextRow][nextCol] == 0) {
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
};

let shortestDistance = function (grid) {
    let minDistance = Number.MAX_VALUE;
    let rows = grid.length;
    let cols = grid[0].length;
    let totalHouses = 0;

    // Store { total_dist, houses_count } for each cell.
    let distances = new Array(rows).fill(0).map(() => new Array(cols).fill(0).map(() => new Array(2).fill(0)));

    // Count houses and start BFS from each house.
    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            if (grid[row][col] == 1) {
                totalHouses++;
                bfs(grid, distances, row, col);
            }
        }
    }

    // Check all empty lands with houses count equal to total houses and find the min ans.
    for (let row = 0; row < rows; ++row) {
        for (let col = 0; col < cols; ++col) {
            if (distances[row][col][1] == totalHouses) {
                minDistance = Math.min(minDistance, distances[row][col][0]);
            }
        }
    }

    // If we haven't found a valid cell return -1.
    if (minDistance == Number.MAX_VALUE) {
        return -1;
    }
    return minDistance;
};
