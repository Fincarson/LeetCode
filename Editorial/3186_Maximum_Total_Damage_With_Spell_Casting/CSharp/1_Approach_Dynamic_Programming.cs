public class Solution {
    public long MaximumTotalDamage(int[] power) {
        var count = new SortedDictionary<int, int>();
        foreach (var p in power) {
            if (!count.ContainsKey(p)) {
                count[p] = 0;
            }
            count[p]++;
        }
        var vec = new List<(int, int)>();
        vec.Add((-1000000000, 0));
        foreach (var kv in count) {
            vec.Add((kv.Key, kv.Value));
        }
        int n = vec.Count;
        long[] f = new long[n];
        long mx = 0, ans = 0;
        int j = 1;
        for (int i = 1; i < n; i++) {
            while (j < i && vec[j].Item1 < vec[i].Item1 - 2) {
                mx = Math.Max(mx, f[j]);
                j++;
            }
            f[i] = mx + (long)vec[i].Item1 * vec[i].Item2;
            ans = Math.Max(ans, f[i]);
        }
        return ans;
    }
}
