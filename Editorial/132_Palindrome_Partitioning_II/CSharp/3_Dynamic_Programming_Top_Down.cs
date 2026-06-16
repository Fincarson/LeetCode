public class Solution {
    private int?[] memoCuts;
    private bool?[,] memoPalindrome;

    public int MinCut(string s) {
        memoCuts = new int?[s.Length];
        memoPalindrome = new bool?[s.Length, s.Length];
        return FindMinimumCut(s, 0, s.Length - 1, s.Length - 1) ?? 0;
    }

    private int? FindMinimumCut(string s, int start, int end, int minimumCut) {
        // base case
        if (start == end || (IsPalindrome(s, start, end) ?? false)) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start].HasValue) {
            return memoCuts[start].Value;
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            if (IsPalindrome(s, start, currentEndIndex) ?? false) {
                minimumCut = Math.Min(
                    minimumCut, 1 + (FindMinimumCut(s, currentEndIndex + 1, end,
                                                    minimumCut) ??
                                     0));
            }
        }

        return memoCuts[start] = minimumCut;
    }

    private bool? IsPalindrome(string s, int start, int end) {
        if (start >= end) {
            return true;
        }

        // check for results in memoPalindrome
        if (memoPalindrome[start, end].HasValue) {
            return memoPalindrome[start, end].Value;
        }

        return memoPalindrome[start, end] =
                   (s[start] == s[end]) &&
                   (IsPalindrome(s, start + 1, end - 1) ?? false);
    }
}
