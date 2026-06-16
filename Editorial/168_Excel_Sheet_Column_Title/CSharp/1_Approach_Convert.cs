public class Solution {
    public string ConvertToTitle(int columnNumber) {
        var ans = new StringBuilder();

        while (columnNumber > 0) {
            columnNumber--;
            // Get the last character and append it at the end of the string.
            ans.Append((char)((columnNumber % 26) + 'A'));
            columnNumber /= 26;
        }

        // Reverse it, as we appended characters in reverse order.
        char[] arr = ans.ToString().ToCharArray();
        Array.Reverse(arr);
        return new string(arr);
    }
}
