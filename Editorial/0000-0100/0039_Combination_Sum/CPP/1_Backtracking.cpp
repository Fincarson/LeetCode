class Solution {
public:
    void backtrack(int remain, vector<int>& comb, int start,
                   const vector<int>& candidates,
                   vector<vector<int>>& results) {
        if (remain == 0) {
            // make a deep copy of the current combination
            results.push_back(comb);
            return;
        } else if (remain < 0) {
            // exceed the scope, stop exploration.
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // add the number into the combination
            comb.push_back(candidates[i]);
            backtrack(remain - candidates[i], comb,
                      i,  // not i + 1 because we can reuse same elements
                      candidates, results);
            // backtrack, remove the number from the combination
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> comb;

        backtrack(target, comb, 0, candidates, results);
        return results;
    }
};
