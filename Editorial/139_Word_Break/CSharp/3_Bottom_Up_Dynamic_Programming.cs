public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        bool[] dp = new bool[s.Length];
        for (int i = 0; i < s.Length; i++) {
            foreach (string word in wordDict) {
                // Handle out of bounds case
                if (i < word.Length - 1) {
                    continue;
                }

                if (i == word.Length - 1 || dp[i - word.Length]) {
                    if (s.Substring(i - word.Length + 1, word.Length) == word) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.Length - 1];
    }
}
