class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currentSubset;
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(subsets, currentSubset, nums, 0);
        return subsets;
    }

private:
    void subsetsWithDupHelper(vector<vector<int>>& subsets,
                              vector<int>& currentSubset, vector<int>& nums,
                              int index) {
        // Add the subset formed so far to the subsets list.
        subsets.push_back(currentSubset);

        for (int i = index; i < nums.size(); i++) {
            // If the current element is a duplicate, ignore.
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            currentSubset.push_back(nums[i]);
            subsetsWithDupHelper(subsets, currentSubset, nums, i + 1);
            currentSubset.pop_back();
        }
    }
};
