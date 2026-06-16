public class Solution {
    public int MinimumTotal(IList<IList<int>> triangle) {
        for (int row = triangle.Count - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                int bestBelow = Math.Min(triangle[row + 1][col],
                                         triangle[row + 1][col + 1]);
                triangle[row][col] += bestBelow;
            }
        }

        return triangle[0][0];
    }
}
