var minimumTotal = function (triangle) {
    let prevRow = triangle[0];
    for (let row = 1; row < triangle.length; row++) {
        let currRow = [];
        for (let col = 0; col <= row; col++) {
            let smallestAbove = Number.MAX_VALUE;
            if (col > 0) {
                smallestAbove = prevRow[col - 1];
            }
            if (col < row) {
                smallestAbove = Math.min(smallestAbove, prevRow[col]);
            }
            currRow.push(smallestAbove + triangle[row][col]);
        }
        prevRow = currRow;
    }
    return Math.min(...prevRow);
};
