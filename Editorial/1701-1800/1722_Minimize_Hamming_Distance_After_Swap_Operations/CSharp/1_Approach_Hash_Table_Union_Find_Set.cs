public class Solution {
    private int[] fa;
    private int[] rank;

    private int Find(int x) {
        if (fa[x] != x) {
            fa[x] = Find(fa[x]);
        }
        return fa[x];
    }

    private void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x == y)
            return;
        if (rank[x] < rank[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        fa[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }

    public int MinimumHammingDistance(int[] source, int[] target,
                                      int[][] allowedSwaps) {
        int n = source.Length;
        fa = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }

        foreach (int[] pair in allowedSwaps) {
            Union(pair[0], pair[1]);
        }

        Dictionary<int, Dictionary<int, int>> sets =
            new Dictionary<int, Dictionary<int, int>>();
        for (int i = 0; i < n; i++) {
            int f = Find(i);
            if (!sets.ContainsKey(f)) {
                sets[f] = new Dictionary<int, int>();
            }
            if (!sets[f].ContainsKey(source[i])) {
                sets[f][source[i]] = 0;
            }
            sets[f][source[i]]++;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int f = Find(i);
            if (sets[f].ContainsKey(target[i]) && sets[f][target[i]] > 0) {
                sets[f][target[i]]--;
            } else {
                ans++;
            }
        }
        return ans;
    }
}
