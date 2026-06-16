class Solution {
    
    public int[][] diagonalSort(int[][] mat) {
        // Store the matrix dimensions.
        int m = mat.length;
        int n = mat[0].length;
        
        // Sort each diagonal that starts on a row.
        for (int row = 0; row < m; row++) {
            sortDiagonal(row, 0, mat);       
        } 

        // Sort each diagonal that starts on a col.
        // Note that we've already sorted the one starting
        // at col = 0; this is the same as the one starting
        // at row = 0.
        for (int col = 1; col < n; col++) {
            sortDiagonal(0, col, mat);  
        } 
        
        return mat;
    }

    private void sortDiagonal(int row, int col, int[][] mat) {
        int m = mat.length; 
        int n = mat[0].length;
        Queue<Integer> diagonal = new PriorityQueue<>();
        
        int diagonalLength = Math.min(m - row, n - col);
        // Put values on this diagonal into the heap.
        for (int i = 0; i < diagonalLength; i++) {
            diagonal.add(mat[row + i][col + i]);
        }
        // Put values on heap back into this diagonal
        for (int i = 0; i < diagonalLength; i++) {
            mat[row + i][col + i] = diagonal.remove();
        }
    }
}
