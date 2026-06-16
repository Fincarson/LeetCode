public class Solution {
    public bool IsPalindrome(string s) {
        int i = 0;
        int j = s.Length - 1;
        while (i < j) {
            while (i < j && !Char.IsLetterOrDigit(s[i])) {
                i++;
            }

            while (i < j && !Char.IsLetterOrDigit(s[j])) {
                j--;
            }

            if (char.ToLower(s[i]) != char.ToLower(s[j]))
                return false;
            i++;
            j--;
        }

        return true;
    }
}
