public class Solution {
    private int getNum(int row, int col) {
        if (row == 0 || col == 0 || row == col) {
            return 1;
        }

        return getNum(row - 1, col - 1) + getNum(row - 1, col);
    }

    public IList<int> GetRow(int rowIndex) {
        IList<int> ans = new List<int>();
        for (int i = 0; i <= rowIndex; i++) {
            ans.Add(getNum(rowIndex, i));
        }

        return ans;
    }
}
