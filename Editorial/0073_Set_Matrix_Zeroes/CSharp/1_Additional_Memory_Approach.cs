public class Solution {
    public void SetZeroes(int[][] matrix) {
        int R = matrix.Length;
        int C = matrix[0].Length;
        HashSet<int> rows = new HashSet<int>();
        HashSet<int> cols = new HashSet<int>();
        // Essentially, we mark the rows and columns that are to be made zero
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (matrix[i][j] == 0) {
                    rows.Add(i);
                    cols.Add(j);
                }
            }
        }

        // Iterate over the array once again and using the rows and cols sets,
        // update the elements.
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (rows.Contains(i) || cols.Contains(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}
