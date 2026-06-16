class Solution {
    public ArrayList<ArrayList<Pair<Integer, Integer>>> compressMatrix(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        
        ArrayList<ArrayList<Pair<Integer, Integer>>> compressedMatrix = new ArrayList<>();
        
        for (int row = 0; row < rows; ++row) {
            ArrayList<Pair<Integer, Integer>> currRow = new ArrayList<>();
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] != 0) {
                    currRow.add(new Pair(matrix[row][col], col)); 
                }
            }
            compressedMatrix.add(currRow);
        }
        return compressedMatrix;
    }
    
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        int m = mat1.length;
        int k = mat1[0].length;
        int n = mat2[0].length;
        
        // Store the non-zero values of each matrix.
        ArrayList<ArrayList<Pair<Integer, Integer>>> A = compressMatrix(mat1);
        ArrayList<ArrayList<Pair<Integer, Integer>>> B = compressMatrix(mat2);
        
        int[][] ans = new int[m][n];
        
        for (int mat1Row = 0; mat1Row < m; ++mat1Row) {
            // Iterate on all current 'row' non-zero elements of mat1.
            for (Pair mat1Element : A.get(mat1Row)) {
                int element1 = (int)mat1Element.getKey();
                int mat1Col = (int)mat1Element.getValue();

                // Multiply and add all non-zero elements of mat2
                // where the row is equal to col of current element of mat1.
                for (Pair mat2Element : B.get(mat1Col)) {
                    int element2 = (int)mat2Element.getKey();
                    int mat2Col = (int)mat2Element.getValue();                 
                    ans[mat1Row][mat2Col] += element1 * element2;
                }
            }
        }
        
        return ans;
    }
}
