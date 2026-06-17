class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int positiveSum = 0, negativeSum = 0, ans = 0;
        for (int num : nums) {
            positiveSum = max(0, positiveSum + num);
            negativeSum = min(0, negativeSum + num);
            ans = max({ans, positiveSum, abs(negativeSum)});
        }
        return ans;
    }
};
