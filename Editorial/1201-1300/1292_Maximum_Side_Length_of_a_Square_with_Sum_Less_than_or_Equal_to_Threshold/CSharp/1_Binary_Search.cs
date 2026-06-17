public class Solution {
    public int MaxSideLength(int[][] mat, int threshold) {
        int m = mat.Length, n = mat[0].Length;
        int[,] P = new int[m + 1, n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                P[i, j] = P[i - 1, j] + P[i, j - 1] - P[i - 1, j - 1] +
                          mat[i - 1][j - 1];
            }
        }

        int l = 1, r = Math.Min(m, n), ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool find = false;
            for (int i = 1; i <= m - mid + 1; i++) {
                for (int j = 1; j <= n - mid + 1; j++) {
                    int sum = P[i + mid - 1, j + mid - 1] -
                              P[i - 1, j + mid - 1] - P[i + mid - 1, j - 1] +
                              P[i - 1, j - 1];
                    if (sum <= threshold) {
                        find = true;
                        break;
                    }
                }
                if (find)
                    break;
            }
            if (find) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
}
