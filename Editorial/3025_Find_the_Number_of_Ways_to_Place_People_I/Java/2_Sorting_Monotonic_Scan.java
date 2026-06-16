public class Solution {
    public int numberOfPairs(int[][] points) {
        // Sort by x ascending, and y descending
        Arrays.sort(points, (a, b) -> {
            if (a[0] == b[0]) return b[1] - a[1];
            return a[0] - b[0];
        });

        int n = points.length;
        int ans = 0;

        for (int i = 0; i < n - 1; i++) {
            int pi2 = points[i][1];
            int minh = Integer.MIN_VALUE;

            for (int j = i + 1; j < n; j++) {
                if (points[j][1] > minh && points[j][1] <= pi2) {
                    ans++;
                    minh = points[j][1];
                }
            }
        }

        return ans;
    }
}
