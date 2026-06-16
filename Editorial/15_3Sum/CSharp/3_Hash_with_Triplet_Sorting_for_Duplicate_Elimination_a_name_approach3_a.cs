public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        var res = new HashSet<(int, int, int)>();
        var dups = new HashSet<int>();
        var seen = new Dictionary<int, int>();

        for (int i = 0; i < nums.Length; i++) {
            int val1 = nums[i];
            if (!dups.Contains(val1)) {
                dups.Add(val1);
                seen.Clear();  // Reset seen for each unique val1
                for (int j = i + 1; j < nums.Length; j++) {
                    int val2 = nums[j];
                    int complement = -val1 - val2;
                    if (seen.ContainsKey(complement) && seen[complement] == i) {
                        // Sort the triplet before adding to the set
                        var triplet = new List<int> { val1, val2, complement };
                        triplet.Sort();
                        res.Add((triplet[0], triplet[1], triplet[2]));
                    }
                    seen[val2] = i;
                }
            }
        }

        var result = new List<IList<int>>();
        foreach (var (a, b, c) in res) {
            result.Add(new List<int> { a, b, c });
        }

        return result;
    }
}
