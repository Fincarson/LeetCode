public class Solution {
    public int TitleToNumber(string s) {
        int result = 0;
        int n = s.Length;
        for (int i = 0; i < n; i++) {
            result = result * 26;
            // In C#, subtracting characters is subtracting ASCII values of characters
            result += (s[i] - 'A' + 1);
        }

        return result;
    }
}
