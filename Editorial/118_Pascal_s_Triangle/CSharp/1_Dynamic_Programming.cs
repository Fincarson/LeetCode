public class Solution {
    public IList<IList<int>> Generate(int numRows) {
        List<IList<int>> triangle = new List<IList<int>>();
        // Base case; first row is always [1].
        triangle.Add(new List<int>());
        triangle[0].Add(1);
        for (int rowNum = 1; rowNum < numRows; rowNum++) {
            List<int> row = new List<int>();
            List<int> prevRow = (List<int>)triangle[rowNum - 1];
            // The first row element is always 1.
            row.Add(1);
            // Each triangle element (other than the first and last of each row)
            // is equal to the sum of the elements above-and-to-the-left and
            // above-and-to-the-right.
            for (int j = 1; j < rowNum; j++) {
                row.Add(prevRow[j - 1] + prevRow[j]);
            }

            // The last row element is always 1.
            row.Add(1);
            triangle.Add(row);
        }

        return triangle;
    }
}
