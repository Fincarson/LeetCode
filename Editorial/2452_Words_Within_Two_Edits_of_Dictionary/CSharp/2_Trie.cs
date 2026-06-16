public class Solution {
    class TrieNode {
        public TrieNode[] child = new TrieNode[26];
        public bool isEnd = false;
    }

    TrieNode root = new TrieNode();

    void Insert(string word) {
        var node = root;
        foreach (char c in word) {
            int idx = c - 'a';
            if (node.child[idx] == null)
                node.child[idx] = new TrieNode();
            node = node.child[idx];
        }
        node.isEnd = true;
    }

    bool Dfs(string word, int i, TrieNode node, int cnt) {
        if (cnt > 2 || node == null)
            return false;

        if (i == word.Length)
            return node.isEnd;

        int idx = word[i] - 'a';

        // no changes made
        if (node.child[idx] != null) {
            if (Dfs(word, i + 1, node.child[idx], cnt))
                return true;
        }

        // made changes
        if (cnt < 2) {
            for (int c = 0; c < 26; c++) {
                if (c == idx)
                    continue;
                if (node.child[c] != null) {
                    if (Dfs(word, i + 1, node.child[c], cnt + 1))
                        return true;
                }
            }
        }

        return false;
    }

    public IList<string> TwoEditWords(string[] queries, string[] dictionary) {
        foreach (var w in dictionary) Insert(w);

        var res = new List<string>();
        foreach (var q in queries) {
            if (Dfs(q, 0, root, 0)) {
                res.Add(q);
            }
        }
        return res;
    }
}
