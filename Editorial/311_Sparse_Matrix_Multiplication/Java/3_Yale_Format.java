class Solution {
    class SparseMatrix {
        public int cols = 0, rows = 0;
        public ArrayList<Integer> values = new ArrayList<>(); 
        public ArrayList<Integer> colIndex = new ArrayList<>(); 
        public ArrayList<Integer> rowIndex = new ArrayList<>();

        // Compressed Sparse Row
        public SparseMatrix(int[][] matrix) {
            rows = matrix.length;
            cols = matrix[0].length; 
            rowIndex.add(0);

            for (int row = 0; row < rows; ++row) {
                for (int col = 0; col < cols; ++col) {
                    if (matrix[row][col] != 0) {
                        values.add(matrix[row][col]);
                        colIndex.add(col);
                    }
                }
                rowIndex.add(values.size());
            }
        }

        // Compressed Sparse Column
        public SparseMatrix(int[][] matrix, boolean colWise) {
            rows = matrix.length;
            cols = matrix[0].length;
            colIndex.add(0);

            for (int col = 0; col < cols; ++col) {
                for (int row = 0; row < rows; ++row) {
                    if (matrix[row][col] != 0) {
                        values.add(matrix[row][col]);
                        rowIndex.add(row);
                    }
                }
                colIndex.add(values.size());
            }
        }
    };

    
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        SparseMatrix A = new SparseMatrix(mat1); 
        SparseMatrix B = new SparseMatrix(mat2, true);
        
        int[][] ans = new int[mat1.length][mat2[0].length];
        
        for (int row = 0; row < ans.length; ++row) {
            for (int col = 0; col < ans[0].length; ++col) {
                
                // Row element range indices
                int matrixOneRowStart = A.rowIndex.get(row);
                int matrixOneRowEnd = A.rowIndex.get(row + 1);
                
                // Column element range indices
                int matrixTwoColStart = B.colIndex.get(col);
                int matrixTwoColEnd = B.colIndex.get(col + 1);
                
                // Iterate over both row and column.
                while (matrixOneRowStart < matrixOneRowEnd && matrixTwoColStart < matrixTwoColEnd) {
                    if (A.colIndex.get(matrixOneRowStart) < B.rowIndex.get(matrixTwoColStart)) {
                        matrixOneRowStart++;
                    } else if (A.colIndex.get(matrixOneRowStart) > B.rowIndex.get(matrixTwoColStart)) {
                        matrixTwoColStart++;
                    } else {
                        // Row index and col index are same so we can multiply these elements.
                        ans[row][col] += A.values.get(matrixOneRowStart) * B.values.get(matrixTwoColStart);
                        matrixOneRowStart++;
                        matrixTwoColStart++;
                    }
                }
            }
        }
        
        return ans;
    }
}
