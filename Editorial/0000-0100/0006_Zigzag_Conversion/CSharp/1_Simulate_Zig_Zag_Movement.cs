public class Solution {
    public string Convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int n = s.Length;
        int sections = (int)Math.Ceiling(n / (2 * numRows - 2.0));
        int numCols = sections * (numRows - 1);

        char[][] matrix = new char [numRows][];
        for (int i = 0; i < numRows; i++) {
            matrix[i] = new char[numCols];
            matrix[i] = Enumerable.Repeat(' ', numCols).ToArray();
        }

        int currRow = 0, currCol = 0;
        int currStringIndex = 0;

        // Iterate in zig-zag pattern on matrix and fill it with string
        // characters.
        while (currStringIndex < n) {
            // Move down.
            while (currRow < numRows && currStringIndex < n) {
                matrix[currRow][currCol] = s[currStringIndex];
                currRow++;
                currStringIndex++;
            }

            currRow -= 2;
            currCol++;

            // Move up (with moving right also).
            while (currRow > 0 && currCol < numCols && currStringIndex < n) {
                matrix[currRow][currCol] = s[currStringIndex];
                currRow--;
                currCol++;
                currStringIndex++;
            }
        }

        string answer = "";
        foreach (char[] row in matrix) {
            string rowStr = new string(row).Replace(" ", "");
            answer += rowStr;
        }

        return answer;
    }
}
