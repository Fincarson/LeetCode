var multiply = function(mat1, mat2) {
    // Product matrix.
    let ans = Array(mat1.length).fill(0).map(x => Array(mat2[0].length).fill(0))
    
    mat1.forEach((rowElements, rowIndex) => {
        rowElements.forEach((rowElement, elementIndex) => {
            // If current element of mat1 is non-zero then iterate over all columns of mat2.
            if (rowElement) {
                mat2[elementIndex].forEach((colElement, colIndex) => {
                    ans[rowIndex][colIndex] += rowElement * colElement;
                });
            }
        });
    });

    return ans
};
