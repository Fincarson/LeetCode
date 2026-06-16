var setZeroes = function (matrix) {
    const rows = new Set();
    const cols = new Set();
    // Essentially, we mark the rows and columns that are to be made zero
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (matrix[i][j] == 0) {
                rows.add(i);
                cols.add(j);
            }
        }
    }
    // Iterate over the array once again and using the rows and cols sets, update the elements
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (rows.has(i) || cols.has(j)) {
                matrix[i][j] = 0;
            }
        }
    }
};
