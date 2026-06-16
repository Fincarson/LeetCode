public class Solution {
    public int MinCut(string s) {
        return findMinimumCut(s, 0, s.Length - 1, s.Length - 1);
    }

    private int findMinimumCut(string s, int start, int end, int minimumCut) {
        // base condition, no cut needed for an empty substring or palindrome
        // substring.
        if (start == end || isPalindrome(s, start, end)) {
            return 0;
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            // find result for substring (start, currentEndIndex) if it is
            // palindrome
            if (isPalindrome(s, start, currentEndIndex)) {
                minimumCut = Math.Min(
                    minimumCut, 1 + findMinimumCut(s, currentEndIndex + 1, end,
                                                   minimumCut));
            }
        }

        return minimumCut;
    }

    private bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }

        return true;
    }
}
