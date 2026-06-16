public class Solution {
    public int MaximalRectangle(char[][] matrix) {
        if (matrix.Length == 0)
            return 0;
        int m = matrix.Length;
        int n = matrix[0].Length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] height = new int[n];
        for (int i = 0; i < n; i++) right[i] = n;
        int maxarea = 0;
        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[j] = Math.Max(left[j], cur_left);
                else {
                    left[j] = 0;
                    cur_left = j + 1;
                }
            }

            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = Math.Min(right[j], cur_right);
                else {
                    right[j] = n;
                    cur_right = j;
                }
            }

            for (int j = 0; j < n; j++) {
                maxarea = Math.Max(maxarea, (right[j] - left[j]) * height[j]);
            }
        }

        return maxarea;
    }
}
