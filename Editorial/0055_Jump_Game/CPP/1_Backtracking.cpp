class Solution {
public:
    bool canJumpFromPosition(int position, vector<int>& nums) {
        if (position == nums.size() - 1) {
            return true;
        }
        int furthestJump = min(position + nums[position], (int)nums.size() - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump;
             nextPosition++) {
            if (canJumpFromPosition(nextPosition, nums)) {
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) { return canJumpFromPosition(0, nums); }
};
