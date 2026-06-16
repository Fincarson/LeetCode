public class Solution {
    private Dictionary<(int, int), int> cache =
        new Dictionary<(int, int), int>();

    private int GetNum(int row, int col) {
        if (cache.ContainsKey((row, col))) {
            return cache[(row, col)];
        }

        int computedVal = (row == 0 || col == 0 || row == col)
                              ? 1
                              : GetNum(row - 1, col - 1) + GetNum(row - 1, col);
        cache[(row, col)] = computedVal;
        return computedVal;
    }

    public IList<int> GetRow(int rowIndex) {
        List<int> ans = new List<int>();
        for (int i = 0; i <= rowIndex; i++) {
            ans.Add(GetNum(rowIndex, i));
        }

        return ans;
    }
}
