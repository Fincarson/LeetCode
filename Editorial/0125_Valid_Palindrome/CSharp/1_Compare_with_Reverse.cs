public class Solution {
    public bool IsPalindrome(string s) {
        string filteredString = String.Empty;
        foreach (char ch in s) {
            if (Char.IsLetterOrDigit(ch)) {
                filteredString += Char.ToLower(ch);
            }
        }

        char[] reversedChars = filteredString.ToCharArray();
        Array.Reverse(reversedChars);
        string reversedString = new string(reversedChars);
        return filteredString == reversedString;
    }
}
