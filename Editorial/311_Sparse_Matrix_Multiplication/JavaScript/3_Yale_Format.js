class SparseMatrix {
    constructor(matrix, colWise) {
        [this.values, this.rowIndex, this.colIndex] = this.compressMatrix(matrix, colWise);
    }
    
    compressMatrix(matrix, colWise) {
        return (colWise ? this.compressColWise(matrix) : this.compressRowWise(matrix)); 
    }
    
    // Compressed Sparse Row
    compressRowWise(matrix) {
        let values = []
        let rowIndex = [0]
        let colIndex = []
        
        for (let row = 0; row < matrix.length; ++row) {
            for (let col = 0; col < matrix[0].length; ++col) {
                if (matrix[row][col]) {
                    values.push(matrix[row][col]);
                    colIndex.push(col);
                }
            }
            rowIndex.push(values.length);
        }
        
        return [values, rowIndex, colIndex];
    }
    
    // Compressed Sparse Col
    compressColWise(matrix) {
        let values = []
        let rowIndex = []
        let colIndex = [0]
        
        for (let col = 0; col < matrix[0].length; ++col) {
            for (let row = 0; row < matrix.length; ++row) {
                if (matrix[row][col]) {
                    values.push(matrix[row][col]);
                    rowIndex.push(row);
                }
            }
            colIndex.push(values.length);
        }
        
        return [values, rowIndex, colIndex];
    }
};

let multiply = function(mat1, mat2) {
    let A = new SparseMatrix(mat1, false)
    let B = new SparseMatrix(mat2, true)
    
    let ans = Array(mat1.length).fill(0).map(x => Array(mat2[0].length).fill(0));
    
    ans.forEach((_, row) => {
        ans[row].forEach((_, col) => {
            // Row element range indices
            let matrixOneRowStart = A.rowIndex[row];
            let matrixOneRowEnd = A.rowIndex[row + 1];

            // Column element range indices
            let matrixTwoColStart = B.colIndex[col];
            let matrixTwoColEnd = B.colIndex[col + 1];

            // Iterate over both row and column.
            while (matrixOneRowStart < matrixOneRowEnd && matrixTwoColStart < matrixTwoColEnd) {
                if (A.colIndex[matrixOneRowStart] < B.rowIndex[matrixTwoColStart]) {
                    matrixOneRowStart++;
                } else if (A.colIndex[matrixOneRowStart] > B.rowIndex[matrixTwoColStart]) {
                    matrixTwoColStart++;
                } else {
                    // Row index and col index are same so we can multiply these elements.
                    ans[row][col] += A.values[matrixOneRowStart] * B.values[matrixTwoColStart];
                    matrixOneRowStart++;
                    matrixTwoColStart++;
                }
            }
        });
    });
    
    return ans;
};
