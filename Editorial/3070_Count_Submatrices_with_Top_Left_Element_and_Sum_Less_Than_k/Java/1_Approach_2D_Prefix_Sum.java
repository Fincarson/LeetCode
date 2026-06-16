class Solution {

    public int countSubmatrices(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int[] cols = new int[n];
        int res = 0;

        for (int i = 0; i < m; i++) {
            int rows = 0;
            for (int j = 0; j < n; j++) {
                cols[j] += grid[i][j];
                rows += cols[j];
                if (rows <= k) {
                    res++;
                }
            }
        }

        return res;
    }
}
