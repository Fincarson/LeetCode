public class Solution {
    public int MinimumTotal(IList<IList<int>> triangle) {
        for (int row = 1; row < triangle.Count; row++) {
            for (int col = 0; col <= row; col++) {
                int smallestAbove = int.MaxValue;
                if (col > 0) {
                    smallestAbove = triangle[row - 1][col - 1];
                }

                if (col < row) {
                    smallestAbove =
                        Math.Min(smallestAbove, triangle[row - 1][col]);
                }

                int path = smallestAbove + triangle[row][col];
                triangle[row][col] = path;
            }
        }

        return triangle[triangle.Count - 1].Min();
    }
}
