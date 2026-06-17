public class Solution {
    public long LargestSquareArea(int[][] bottomLeft, int[][] topRight) {
        int n = bottomLeft.Length;
        long maxSide = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = Math.Min(topRight[i][0], topRight[j][0]) -
                        Math.Max(bottomLeft[i][0], bottomLeft[j][0]);
                int h = Math.Min(topRight[i][1], topRight[j][1]) -
                        Math.Max(bottomLeft[i][1], bottomLeft[j][1]);

                maxSide = Math.Max(maxSide, Math.Min(w, h));
            }
        }

        return maxSide * maxSide;
    }
}
