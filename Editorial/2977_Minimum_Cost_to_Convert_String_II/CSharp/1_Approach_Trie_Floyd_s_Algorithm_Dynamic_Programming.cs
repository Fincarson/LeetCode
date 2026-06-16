public class Trie {
    public Trie[] child = new Trie[26];
    public int id = -1;
}

public class Solution {
    private const int INF = int.MaxValue / 2;

    private int Add(Trie node, string word, ref int index) {
        foreach (char ch in word) {
            int i = ch - 'a';
            if (node.child[i] == null) {
                node.child[i] = new Trie();
            }
            node = node.child[i];
        }
        if (node.id == -1) {
            node.id = ++index;
        }
        return node.id;
    }

    private void Update(ref long x, long y) {
        if (x == -1 || y < x) {
            x = y;
        }
    }

    public long MinimumCost(string source, string target, string[] original,
                            string[] changed, int[] cost) {
        int n = source.Length;
        int m = original.Length;
        Trie root = new Trie();

        int p = -1;
        int[,] G = new int[m * 2, m * 2];

        for (int i = 0; i < m * 2; i++) {
            for (int j = 0; j < m * 2; j++) {
                G[i, j] = INF;
            }
            G[i, i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int x = Add(root, original[i], ref p);
            int y = Add(root, changed[i], ref p);
            G[x, y] = Math.Min(G[x, y], cost[i]);
        }

        int size = p + 1;
        for (int k = 0; k < size; k++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    G[i, j] = Math.Min(G[i, j], G[i, k] + G[k, j]);
                }
            }
        }

        long[] f = new long[n];
        Array.Fill(f, -1);
        for (int j = 0; j < n; j++) {
            if (j > 0 && f[j - 1] == -1) {
                continue;
            }
            long baseVal = (j == 0 ? 0 : f[j - 1]);
            if (source[j] == target[j]) {
                Update(ref f[j], baseVal);
            }

            Trie u = root;
            Trie v = root;
            for (int i = j; i < n; i++) {
                u = u.child[source[i] - 'a'];
                v = v.child[target[i] - 'a'];
                if (u == null || v == null) {
                    break;
                }
                if (u.id != -1 && v.id != -1 && G[u.id, v.id] != INF) {
                    long newVal = baseVal + G[u.id, v.id];
                    Update(ref f[i], newVal);
                }
            }
        }

        return f[n - 1];
    }
}
