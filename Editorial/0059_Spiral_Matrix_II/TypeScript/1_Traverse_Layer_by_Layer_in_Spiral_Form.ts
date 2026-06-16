function generateMatrix(n: number): number[][] {
    let result = Array.from({ length: n }, () => Array(n).fill(0));
    let cnt = 1;
    for (let layer = 0; layer < Math.floor((n + 1) / 2); layer++) {
        // direction 1 - traverse from left to right
        for (let ptr = layer; ptr < n - layer; ptr++) {
            result[layer][ptr] = cnt++;
        }
        // direction 2 - traverse from top to bottom
        for (let ptr = layer + 1; ptr < n - layer; ptr++) {
            result[ptr][n - layer - 1] = cnt++;
        }
        // direction 3 - traverse from right to left
        for (let ptr = n - layer - 2; ptr >= layer; ptr--) {
            result[n - layer - 1][ptr] = cnt++;
        }
        // direction 4 - traverse from bottom to top
        for (let ptr = n - layer - 2; ptr > layer; ptr--) {
            result[ptr][layer] = cnt++;
        }
    }
    return result;
}
