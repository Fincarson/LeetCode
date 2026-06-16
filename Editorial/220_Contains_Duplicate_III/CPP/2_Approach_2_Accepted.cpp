class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            // Find the successor of current element
            auto s = set.lower_bound(nums[i]);
            if (s != set.end() && *s <= nums[i] + t) return true;

            // Find the predecessor of current element
            if (s != set.begin()) {
                auto g = prev(s);
                if (nums[i] <= *g + t) return true;
            }

            set.insert(nums[i]);
            if (set.size() > k) {
                set.erase(nums[i - k]);
            }
        }
        return false;
    }
};
