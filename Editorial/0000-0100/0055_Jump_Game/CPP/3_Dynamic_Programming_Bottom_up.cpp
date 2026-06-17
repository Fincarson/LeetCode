enum Index { GOOD, BAD, UNKNOWN };
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<Index> memo(nums.size(), UNKNOWN);
        memo[memo.size() - 1] = GOOD;
        for (int i = nums.size() - 2; i >= 0; i--) {
            int furthestJump = min(i + nums[i], (int)nums.size() - 1);
            for (int j = i + 1; j <= furthestJump; j++) {
                if (memo[j] == GOOD) {
                    memo[i] = GOOD;
                    break;
                }
            }
        }
        return memo[0] == GOOD;
    }
};
