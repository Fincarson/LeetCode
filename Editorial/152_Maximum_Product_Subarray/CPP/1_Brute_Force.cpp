class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int result = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int accu = 1;
            for (int j = i; j < nums.size(); j++) {
                accu *= nums[j];
                result = max(result, accu);
            }
        }

        return result;
    }
};
