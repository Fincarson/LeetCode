public class Solution {
    private List<IList<int>> triangle;
    private Dictionary<string, int> memoTable = new Dictionary<string, int>();

    private int MinPath(int row, int col) {
        string paramsKey = row + ":" + col;
        if (memoTable.ContainsKey(paramsKey)) {
            return memoTable[paramsKey];
        }

        int path = triangle[row][col];
        if (row < triangle.Count - 1) {
            path += Math.Min(MinPath(row + 1, col), MinPath(row + 1, col + 1));
        }

        memoTable[paramsKey] = path;
        return path;
    }

    public int MinimumTotal(IList<IList<int>> triangle) {
        this.triangle = triangle.ToList();
        memoTable.Clear();
        return MinPath(0, 0);
    }
}
