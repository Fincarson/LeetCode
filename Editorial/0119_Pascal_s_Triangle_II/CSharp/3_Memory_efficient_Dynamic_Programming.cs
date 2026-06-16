public class Solution {
    public IList<int> GetRow(int rowIndex) {
        IList<int> row = new int[rowIndex + 1];
        for (int i = 0; i <= rowIndex; i++) {
            row[i] = 1;
        }

        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j > 0; j--) {
                row[j] += row[j - 1];
            }
        }

        return row;
    }
}
