public class Solution {
    public IList<int> GetRow(int rowIndex) {
        List<int> row = new List<int>() { 1 };
        for (int k = 1; k <= rowIndex; k++) {
            row.Add((int)((row[row.Count - 1] * (long)(rowIndex - k + 1)) / k));
        }

        return row;
    }
}
