public class Solution {
    private string s;
    private IList<string> wordDict;
    private int[] memo;

    private bool IsValid(int i) {
        if (i < 0) {
            return true;
        }

        if (memo[i] != -1) {
            return memo[i] == 1;
        }

        foreach (string word in wordDict) {
            // Handle out of bounds case
            if (i - word.Length + 1 < 0) {
                continue;
            }

            if (s.Substring(i - word.Length + 1, word.Length) == word &&
                IsValid(i - word.Length)) {
                memo[i] = 1;
                return true;
            }
        }

        memo[i] = 0;
        return false;
    }

    public bool WordBreak(string s, IList<string> wordDict) {
        this.s = s;
        this.wordDict = wordDict;
        this.memo = new int[s.Length];
        Array.Fill(this.memo, -1);
        return IsValid(s.Length - 1);
    }
}
