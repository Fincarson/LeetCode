class Solution {

    public int minCostII(int[][] costs) {

        if (costs.length == 0) return 0;
        int k = costs[0].length;
        int n = costs.length;

        int[] previousRow = costs[0];

        for (int house = 1; house < n; house++) {
            int[] currentRow = new int[k];
            for (int color = 0; color < k; color++) {
                int min = Integer.MAX_VALUE;
                for (int previousColor = 0; previousColor < k; previousColor++) {
                    if (color == previousColor) continue;
                    min = Math.min(min, previousRow[previousColor]);
                }
                currentRow[color] += costs[house][color] += min;
            }
            previousRow = currentRow;
        }

        // Find the minimum in the last row.
        int min = Integer.MAX_VALUE;
        for (int c : previousRow) {
            min = Math.min(min, c);
        }
        return min;
    }
}
