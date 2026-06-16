class Solution {
public:
    vector<vector<int>> permutations(vector<int> nums) {
        vector<vector<int>> ans;
        permute(ans, nums, 0);
        return ans;
    }

    void permute(vector<vector<int>>& ans, vector<int>& nums, int start) {
        if (start >= nums.size()) {
            ans.push_back(nums);
        } else {
            for (int i = start; i < nums.size(); i++) {
                swap(nums[start], nums[i]);
                permute(ans, nums, start + 1);
                swap(nums[start], nums[i]);
            }
        }
    }

    int numUniqueDiffs(vector<int> arr) {
        vector<bool> seen(arr.size());
        int ans = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            int delta = abs(arr[i] - arr[i + 1]);
            if (!seen[delta]) {
                ans++;
                seen[delta] = true;
            }
        }
        return ans;
    }

    vector<int> constructArray(int n, int k) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }
        for (auto& cand : permutations(nums)) {
            if (numUniqueDiffs(cand) == k) {
                return cand;
            }
        }
        return vector<int>();
    }
};
