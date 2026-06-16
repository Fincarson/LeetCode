public class Solution {
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        List<IList<int>> results = new List<IList<int>>();
        this.backtrack(target, new List<int>(), candidates, 0, results);
        return results;
    }

    private void backtrack(int remain, List<int> comb, int[] candidates,
                           int start, List<IList<int>> results) {
        if (remain == 0) {
            results.Add(new List<int>(comb));
            return;
        } else if (remain < 0) {
            return;
        }

        for (int i = start; i < candidates.Length; ++i) {
            comb.Add(candidates[i]);
            this.backtrack(remain - candidates[i], comb, candidates, i,
                           results);
            comb.RemoveAt(comb.Count - 1);
        }
    }
}
