public class Solution {
    private int?[][] memoCuts;
    private bool?[][] memoPalindrome;

    public int MinCut(string s) {
        memoCuts = new int ?[s.Length][];
        memoPalindrome = new bool ?[s.Length][];
        for (int i = 0; i < s.Length; i++) {
            memoCuts[i] = new int?[s.Length];
            memoPalindrome[i] = new bool?[s.Length];
        }

        return FindMinimumCut(s, 0, s.Length - 1, s.Length - 1).Value;
    }

    private int? FindMinimumCut(string s, int start, int end, int minimumCut) {
        // base case
        if (start == end || IsPalindrome(s, start, end).Value) {
            return 0;
        }

        // check for results in memoCuts
        if (memoCuts[start][end].HasValue) {
            return memoCuts[start][end].Value;
        }

        for (int currentEndIndex = start; currentEndIndex <= end;
             currentEndIndex++) {
            if (IsPalindrome(s, start, currentEndIndex).Value) {
                minimumCut = Math.Min(
                    minimumCut,
                    1 + FindMinimumCut(s, currentEndIndex + 1, end, minimumCut)
                            .Value);
            }
        }

        return memoCuts[start][end] = minimumCut;
    }

    private bool? IsPalindrome(string s, int start, int end) {
        if (start >= end) {
            return true;
        }

        // check for results in memoPalindrome
        if (memoPalindrome[start][end] != null) {
            return memoPalindrome[start][end].Value;
        }

        return memoPalindrome[start][end] =
                   (s[start] == s[end]) &&
                   IsPalindrome(s, start + 1, end - 1).Value;
    }
}
