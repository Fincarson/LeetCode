public class Solution {
    public int[] SolveQueries(int[] nums, int[] queries) {
        int n = nums.Length;
        int[] left = new int[n];
        int[] right = new int[n];
        Dictionary<int, int> pos = new Dictionary<int, int>();

        for (int i = -n; i < n; i++) {
            if (i >= 0) {
                left[i] = pos.ContainsKey(nums[i]) ? pos[nums[i]] : -n;
            }
            pos[nums[(i + n) % n]] = i;
        }

        pos.Clear();
        for (int i = 2 * n - 1; i >= 0; i--) {
            if (i < n) {
                right[i] = pos.ContainsKey(nums[i]) ? pos[nums[i]] : 2 * n;
            }
            pos[nums[i % n]] = i;
        }

        for (int i = 0; i < queries.Length; i++) {
            int x = queries[i];
            if (x - left[x] == n) {
                queries[i] = -1;
            } else {
                queries[i] = Math.Min(x - left[x], right[x] - x);
            }
        }

        return queries;
    }
}
