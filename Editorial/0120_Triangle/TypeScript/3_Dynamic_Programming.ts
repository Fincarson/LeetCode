function minimumTotal(triangle: number[][]): number {
    for (let row = triangle.length - 2; row >= 0; row--) {
        for (let col = 0; col <= row; col++) {
            let bestBelow = Math.min(
                triangle[row + 1][col],
                triangle[row + 1][col + 1],
            );
            triangle[row][col] += bestBelow;
        }
    }
    return triangle[0][0];
}
