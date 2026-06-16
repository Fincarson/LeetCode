class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = max(i - k, 0); j < i; ++j) {
                if (abs((long long)nums[i] - nums[j]) <= t) return true;
            }
        }
        return false;
    }
};
