var generate = function (numRows) {
    // Return type is an array of arrays.
    const triangle = [];
    // Base case; first row is always [1].
    triangle.push([]);
    triangle[0].push(1);
    for (let rowNum = 1; rowNum < numRows; rowNum++) {
        const row = [];
        const prevRow = triangle[rowNum - 1];
        // The first row element is always 1.
        row.push(1);
        // Each triangle element (other than the first and last of each row)
        // is equal to the sum of the elements above-and-to-the-left and
        // above-and-to-the-right.
        for (let j = 1; j < rowNum; j++) {
            row.push(prevRow[j - 1] + prevRow[j]);
        }
        // The last row element is always 1.
        row.push(1);
        triangle.push(row);
    }
    return triangle;
};
