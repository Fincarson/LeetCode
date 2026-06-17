using System;
using System.Collections.Generic;

public class Solution {
    private const int MOD = 1000000007;

    public int SpecialTriplets(int[] nums) {
        Dictionary<int, List<int>> pos = new Dictionary<int, List<int>>();

        for (int i = 0; i < nums.Length; i++) {
            int v = nums[i];
            if (!pos.ContainsKey(v)) {
                pos[v] = new List<int>();
            }
            pos[v].Add(i);
        }

        int ans = 0;
        for (int i = 1; i < nums.Length - 1; i++) {
            int target = nums[i] * 2;
            if (pos.ContainsKey(target) && pos[target].Count > 1 &&
                pos[target][0] < i) {
                var (l, r) = UpperBound(pos[target], i);
                int leftCount = l;
                int rightCount = r;
                if (nums[i] == 0) {
                    leftCount--;
                }
                ans = (int)((ans + (long)leftCount * rightCount) % MOD);
            }
        }
        return ans;
    }

    private (int, int) UpperBound(List<int> arr, int i) {
        int l = 0, r = arr.Count - 1;
        while (l < r) {
            int mid = l + ((r - l + 1) >> 1);
            if (i >= arr[mid]) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return (l + 1, arr.Count - 1 - l);
    }
}
