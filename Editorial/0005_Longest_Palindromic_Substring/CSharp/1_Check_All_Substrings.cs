public class Solution {
    public string LongestPalindrome(string s) {
        for (int length = s.Length; length > 0; length--) {
            for (int start = 0; start <= s.Length - length; start++) {
                if (Check(start, start + length, s)) {
                    return s.Substring(start, length);
                }
            }
        }

        return "";
    }

    private bool Check(int i, int j, string s) {
        int left = i;
        int right = j - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
}
