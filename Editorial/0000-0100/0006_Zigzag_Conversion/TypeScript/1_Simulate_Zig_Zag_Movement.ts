function convert(s: string, numRows: number): string {
    if (numRows === 1) {
        return s;
    }

    let n = s.length;
    let sections = Math.ceil(n / (2 * numRows - 2));
    let numCols = sections * (numRows - 1);

    let matrix = Array.from({ length: numRows }, () =>
        Array(numCols).fill(" "),
    );

    let currRow = 0,
        currCol = 0;
    let currStringIndex = 0;

    // Iterate in zig-zag pattern on matrix and fill it with string characters.
    while (currStringIndex < n) {
        // Move down.
        while (currRow < numRows && currStringIndex < n) {
            matrix[currRow][currCol] = s[currStringIndex];
            currRow++;
            currStringIndex++;
        }

        currRow -= 2;
        currCol++;

        // Move up (with moving right also).
        while (currRow > 0 && currCol < numCols && currStringIndex < n) {
            matrix[currRow][currCol] = s[currStringIndex];
            currRow--;
            currCol++;
            currStringIndex++;
        }
    }

    let answer = matrix.map((row) => row.join(""));
    return answer.join("").split(" ").join("");
}
