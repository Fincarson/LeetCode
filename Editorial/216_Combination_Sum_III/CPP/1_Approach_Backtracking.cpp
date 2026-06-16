class Solution {
public:
    void backtrack(int remain, int k, vector<int>& comb, int next_start,
                   vector<vector<int>>& results) {
        if (remain == 0 && comb.size() == k) {
            // Note: it's important to make a deep copy here by using push_back,
            // which copies 'comb' to 'results'. This prevents modifications to
            // 'comb' in other branches of backtracking from affecting the
            // stored combinations.
            results.push_back(comb);
            return;
        } else if (remain < 0 || comb.size() == k) {
            // Exceed the scope, no need to explore further.
            return;
        }

        // Iterate through the reduced list of candidates.
        for (int i = next_start; i < 9; ++i) {
            comb.push_back(i + 1);
            this->backtrack(remain - i - 1, k, comb, i + 1, results);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> results;
        vector<int> comb;

        this->backtrack(n, k, comb, 0, results);
        return results;
    }
};
