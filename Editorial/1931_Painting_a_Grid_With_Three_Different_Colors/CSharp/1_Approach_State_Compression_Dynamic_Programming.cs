public class Solution {
    private const int mod = 1000000007;

    public int ColorTheGrid(int m, int n) {
        // Hash mapping stores all valid coloration schemes for a single row
        // that meet the requirements
        var valid = new Dictionary<int, List<int>>();
        // Enumerate masks that meet the requirements within the range [0, 3^m)
        int maskEnd = (int)Math.Pow(3, m);
        for (int mask = 0; mask < maskEnd; ++mask) {
            var color = new List<int>();
            int mm = mask;
            for (int i = 0; i < m; ++i) {
                color.Add(mm % 3);
                mm /= 3;
            }
            bool check = true;
            for (int i = 0; i < m - 1; ++i) {
                if (color[i] == color[i + 1]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                valid[mask] = color;
            }
        }

        // Preprocess all (mask1, mask2) binary tuples, satisfying mask1 and
        // mask2 When adjacent rows, the colors of the two cells in the same
        // column are different
        var adjacent = new Dictionary<int, List<int>>();
        foreach (var mask1 in valid.Keys) {
            foreach (var mask2 in valid.Keys) {
                bool check = true;
                for (int i = 0; i < m; ++i) {
                    if (valid[mask1][i] == valid[mask2][i]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    if (!adjacent.ContainsKey(mask1)) {
                        adjacent[mask1] = new List<int>();
                    }
                    adjacent[mask1].Add(mask2);
                }
            }
        }

        var f = new Dictionary<int, int>();
        foreach (var mask in valid.Keys) {
            f[mask] = 1;
        }
        for (int i = 1; i < n; ++i) {
            var g = new Dictionary<int, int>();
            foreach (var mask2 in valid.Keys) {
                if (adjacent.ContainsKey(mask2)) {
                    foreach (var mask1 in adjacent[mask2]) {
                        if (!g.ContainsKey(mask2)) {
                            g[mask2] = 0;
                        }
                        g[mask2] = (g[mask2] + f[mask1]) % mod;
                    }
                }
            }
            f = g;
        }

        int ans = 0;
        foreach (var num in f.Values) {
            ans = (ans + num) % mod;
        }
        return ans;
    }
}
