let multiply = function(mat1, mat2) {
    let compressMatrix = (matrix) => {
        let rows = matrix.length;
        let cols = matrix[0].length;
        let compressedMatrix = [];

        matrix.forEach((rowElements, row) => {
            let currRow = [];
            rowElements.forEach((element, col) => {
                if (element) {          
                    currRow.push([element, col]);
                }
            });
            compressedMatrix.push(currRow);
        });
        return compressedMatrix;
    }
    
    let m = mat1.length;
    let k = mat1[0].length;
    let n = mat2[0].length;
    
    // Store the non-zero values of each matrix.
    let A = compressMatrix(mat1);
    let B = compressMatrix(mat2);
    
    let ans = Array(m).fill(0).map(x => Array(n).fill(0));
    
    for (let mat1Row = 0; mat1Row < m; ++mat1Row) {
            // Iterate on all current 'row' non-zero elements of mat1.
            for (let mat1Element of A[mat1Row]) {
                let [element1, mat1Col] = mat1Element;
                
                // Multiply and add all non-zero elements of mat2
                // where the row is equal to col of current element of mat1.
                for (let mat2Element of B[mat1Col]) {
                    let [element2, mat2Col] = mat2Element;
                    ans[mat1Row][mat2Col] += element1 * element2;
                }
            }
        }

    return ans;
};
