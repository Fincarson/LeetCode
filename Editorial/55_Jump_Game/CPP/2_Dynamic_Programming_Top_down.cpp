enum Index { GOOD, BAD, UNKNOWN };
class Solution {
public:
    vector<Index> memo;
    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (memo[position] != UNKNOWN) {
            return memo[position] == GOOD ? true : false;
        }
        int furthestJump = min(position + nums[position], (int)nums.size() - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump;
             nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                memo[position] = GOOD;
                return true;
            }
        }
        memo[position] = BAD;
        return false;
    }
    bool canJump(vector<int>& nums) {
        memo = vector<Index>(nums.size());
        for (int i = 0; i < memo.size(); i++) {
            memo[i] = UNKNOWN;
        }
        memo[memo.size() - 1] = GOOD;
        return canJumpFromPosition(0, nums);
    }
};
