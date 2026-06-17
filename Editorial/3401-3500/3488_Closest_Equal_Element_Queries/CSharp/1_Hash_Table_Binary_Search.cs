public class Solution {
    public int[] SolveQueries(int[] nums, int[] queries) {
        int n = nums.Length;
        Dictionary<int, List<int>> numsPos = new Dictionary<int, List<int>>();

        for (int i = 0; i < n; i++) {
            if (!numsPos.ContainsKey(nums[i])) {
                numsPos[nums[i]] = new List<int>();
            }
            numsPos[nums[i]].Add(i);
        }

        foreach (var pos in numsPos.Values.ToList()) {
            int x = pos[0];
            pos.Insert(0, pos[pos.Count - 1] - n);
            pos.Add(x + n);
        }

        for (int i = 0; i < queries.Length; i++) {
            int x = nums[queries[i]];
            List<int> posList = numsPos[x];
            if (posList.Count == 3) {
                queries[i] = -1;
                continue;
            }
            int pos = posList.BinarySearch(queries[i]);
            if (pos < 0) {
                pos = ~pos;
            }
            queries[i] = Math.Min(posList[pos + 1] - posList[pos],
                                  posList[pos] - posList[pos - 1]);
        }

        return queries;
    }
}
