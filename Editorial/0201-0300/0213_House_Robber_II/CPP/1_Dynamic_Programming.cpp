class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        if (nums.size() == 1) return nums[0];

        int max1 = rob_simple(nums, 0, nums.size() - 2);
        int max2 = rob_simple(nums, 1, nums.size() - 1);

        return max(max1, max2);
    }

private:
    int rob_simple(vector<int>& nums, int start, int end) {
        int t1 = 0, t2 = 0;
        for (int i = start; i <= end; ++i) {
            int temp = t1;
            t1 = max(nums[i] + t2, t1);
            t2 = temp;
        }

        return t1;
    }
};
