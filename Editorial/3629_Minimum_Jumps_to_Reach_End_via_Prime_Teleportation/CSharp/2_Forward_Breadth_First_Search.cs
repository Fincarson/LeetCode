public class Solution {
    private static readonly int MX = 1000001;
    private static readonly List<int>[] factors = new List<int>[MX];

    static Solution() {
        for (int i = 0; i < MX; i++) factors[i] = new List<int>();
        for (int i = 2; i < MX; i++) {
            if (factors[i].Count == 0) {
                for (int j = i; j < MX; j += i) factors[j].Add(i);
            }
        }
    }

    public int MinJumps(int[] nums) {
        int n = nums.Length;
        var edges = new Dictionary<int, List<int>>();
        for (int i = 0; i < n; i++) {
            foreach (int p in factors[nums[i]]) {
                if (!edges.ContainsKey(p))
                    edges[p] = new List<int>();
                edges[p].Add(i);
            }
        }
        int res = 0;
        bool[] seen = new bool[n];
        seen[0] = true;
        List<int> q = new List<int> { 0 };
        while (true) {
            List<int> q2 = new List<int>();
            foreach (int i in q) {
                if (i == n - 1)
                    return res;
                if (i > 0 && !seen[i - 1]) {
                    seen[i - 1] = true;
                    q2.Add(i - 1);
                }
                if (i < n - 1 && !seen[i + 1]) {
                    seen[i + 1] = true;
                    q2.Add(i + 1);
                }
                if (factors[nums[i]].Count == 1) {
                    int p = nums[i];
                    if (edges.TryGetValue(p, out var list)) {
                        foreach (int j in list) {
                            if (!seen[j]) {
                                seen[j] = true;
                                q2.Add(j);
                            }
                        }
                        list.Clear();
                    }
                }
            }
            q = q2;
            res++;
        }
    }
}
