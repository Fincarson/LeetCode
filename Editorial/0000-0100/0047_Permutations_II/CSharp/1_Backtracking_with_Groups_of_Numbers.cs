// C# Solution

public class Solution {
    public IList<IList<int>> PermuteUnique(int[] nums) {
        List<IList<int>> results = new List<IList<int>>();
        Dictionary<int, int> counter = new Dictionary<int, int>();
        foreach (int num in nums) {
            if (!counter.ContainsKey(num))
                counter.Add(num, 0);
            counter[num]++;
        }

        List<int> comb = new List<int>();
        this.Backtrack(comb, nums.Length, counter, results);
        return results;
    }

    private void Backtrack(List<int> comb, int N, Dictionary<int, int> counter,
                           List<IList<int>> results) {
        if (comb.Count == N) {
            results.Add(new List<int>(comb));
            return;
        }

        foreach (var entry in counter.ToList()) {
            int num = entry.Key;
            int count = entry.Value;
            if (count == 0)
                continue;
            comb.Add(num);
            counter[num]--;
            this.Backtrack(comb, N, counter, results);
            comb.RemoveAt(comb.Count - 1);
            counter[num]++;
        }
    }
}
