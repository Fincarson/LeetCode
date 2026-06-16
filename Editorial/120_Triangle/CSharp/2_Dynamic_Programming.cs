public class Solution {
    public int MinimumTotal(IList<IList<int>> triangle) {
        List<int> prevRow = triangle[0].ToList();
        for (int row = 1; row < triangle.Count; row++) {
            List<int> currRow = new List<int>();
            for (int col = 0; col <= row; col++) {
                int smallestAbove = int.MaxValue;
                if (col > 0) {
                    smallestAbove = prevRow[col - 1];
                }

                if (col < row) {
                    smallestAbove = Math.Min(smallestAbove, prevRow[col]);
                }

                currRow.Add(smallestAbove + triangle[row][col]);
            }

            prevRow = currRow;
        }

        return prevRow.Min();
    }
}
