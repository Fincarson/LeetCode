public class Solution {
    public int[] MaxSubsequence(int[] nums, int k) {
        int n = nums.Length;
        int[,] vals =
            new int[n, 2];  // two-dimensional array stores index and value
        for (int i = 0; i < n; ++i) {
            vals[i, 0] = i;        // store index
            vals[i, 1] = nums[i];  // store value
        }
        // sort by numerical value in descending order
        var sortedVals =
            Enumerable.Range(0, n)
                .Select(i => new { Index = vals[i, 0], Value = vals[i, 1] })
                .OrderByDescending(x => x.Value)
                .ToArray();
        // select the first k elements and sort them in ascending order by index
        var topK = sortedVals.Take(k).OrderBy(x => x.Index).ToArray();
        int[] res = new int[k];  // target subsequence
        for (int i = 0; i < k; ++i) {
            res[i] = topK[i].Value;
        }
        return res;
    }
}
