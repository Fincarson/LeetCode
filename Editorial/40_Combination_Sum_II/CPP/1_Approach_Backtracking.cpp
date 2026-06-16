class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> tempList;
        sort(candidates.begin(), candidates.end());
        backtrack(result, tempList, candidates, target, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& answer, vector<int>& tempList,
                   vector<int>& candidates, int totalLeft, int index) {
        if (totalLeft < 0)
            return;
        else if (totalLeft == 0) {
            answer.push_back(tempList);
        } else {
            for (int i = index;
                 i < candidates.size() && totalLeft >= candidates[i]; i++) {
                if (i > index && candidates[i] == candidates[i - 1]) continue;
                tempList.push_back(candidates[i]);
                backtrack(answer, tempList, candidates,
                          totalLeft - candidates[i], i + 1);
                tempList.pop_back();
            }
        }
    }
};
