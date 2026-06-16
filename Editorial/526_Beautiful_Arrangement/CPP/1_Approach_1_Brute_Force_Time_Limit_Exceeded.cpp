class Solution {
public:
    int countArrangement(int N) {
        count = 0;
        vector<int> nums(N);
        for (int i = 1; i <= N; i++) nums[i - 1] = i;
        permute(nums, 0);
        return count;
    }

private:
    int count;

    void permute(vector<int>& nums, int l) {
        if (l == nums.size() - 1) {
            int i;
            for (i = 1; i <= nums.size(); i++) {
                if (nums[i - 1] % i != 0 && i % nums[i - 1] != 0) break;
            }
            if (i == nums.size() + 1) {
                count++;
            }
        }
        for (int i = l; i < nums.size(); i++) {
            swap(nums[i], nums[l]);
            permute(nums, l + 1);
            swap(nums[i], nums[l]);
        }
    }
};
