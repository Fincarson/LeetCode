public class TrieNode {
    public bool isWord;
    public Dictionary<char, TrieNode> children;

    public TrieNode() {
        this.children = new Dictionary<char, TrieNode>();
    }
}

public class Solution {
    public bool WordBreak(string s, IList<string> wordDict) {
        TrieNode root = new TrieNode();
        foreach (string word in wordDict) {
            TrieNode curr = root;
            foreach (char c in word) {
                if (!curr.children.ContainsKey(c)) {
                    curr.children[c] = new TrieNode();
                }

                curr = curr.children[c];
            }

            curr.isWord = true;
        }

        bool[] dp = new bool[s.Length];
        for (int i = 0; i < s.Length; i++) {
            if (i == 0 || dp[i - 1]) {
                TrieNode curr = root;
                for (int j = i; j < s.Length; j++) {
                    char c = s[j];
                    if (!curr.children.ContainsKey(c)) {
                        // No words exist
                        break;
                    }

                    curr = curr.children[c];
                    if (curr.isWord) {
                        dp[j] = true;
                    }
                }
            }
        }

        return dp[s.Length - 1];
    }
}
