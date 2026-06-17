public class SegTree {
    int[] maxv, minv;
    int n;

    public SegTree(int[] nums) {
        n = nums.Length;
        maxv = new int[n * 4];
        minv = new int[n * 4];
        Build(1, 0, n - 1, nums);
    }

    void Build(int node, int l, int r, int[] nums) {
        if (l == r) {
            maxv[node] = minv[node] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        Build(node * 2, l, m, nums);
        Build(node * 2 + 1, m + 1, r, nums);
        maxv[node] = Math.Max(maxv[node * 2], maxv[node * 2 + 1]);
        minv[node] = Math.Min(minv[node * 2], minv[node * 2 + 1]);
    }

    public int QueryMax(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return maxv[node];
        }
        int m = (l + r) / 2, res = int.MinValue;
        if (ql <= m) {
            res = Math.Max(res, QueryMax(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = Math.Max(res, QueryMax(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }

    public int QueryMin(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            return minv[node];
        }
        int m = (l + r) / 2, res = int.MaxValue;
        if (ql <= m) {
            res = Math.Min(res, QueryMin(node * 2, l, m, ql, qr));
        }
        if (qr > m) {
            res = Math.Min(res, QueryMin(node * 2 + 1, m + 1, r, ql, qr));
        }
        return res;
    }
}

public class Solution {
    public long MaxTotalValue(int[] nums, int k) {
        int n = nums.Length;
        var seg = new SegTree(nums);
        var pq = new PriorityQueue<(int l, int r), int>();
        for (int l = 0; l < n; l++) {
            int val = seg.QueryMax(1, 0, n - 1, l, n - 1) -
                      seg.QueryMin(1, 0, n - 1, l, n - 1);
            pq.Enqueue((l, n - 1), -val);
        }
        long ans = 0;
        while (k-- > 0) {
            pq.TryDequeue(out var top, out int negVal);
            ans -= negVal;
            int l = top.l, r = top.r;
            if (r > l) {
                int val = seg.QueryMax(1, 0, n - 1, l, r - 1) -
                          seg.QueryMin(1, 0, n - 1, l, r - 1);
                pq.Enqueue((l, r - 1), -val);
            }
        }
        return ans;
    }
}
