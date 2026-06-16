function minimumTotal(triangle: number[][]): number {
    for (let row = 1; row < triangle.length; row++) {
        for (let col = 0; col <= row; col++) {
            let smallestAbove = Number.MAX_VALUE;
            if (col > 0) {
                smallestAbove = triangle[row - 1][col - 1];
            }
            if (col < row) {
                smallestAbove = Math.min(smallestAbove, triangle[row - 1][col]);
            }
            triangle[row][col] += smallestAbove;
        }
    }
    return Math.min(...triangle[triangle.length - 1]);
}
