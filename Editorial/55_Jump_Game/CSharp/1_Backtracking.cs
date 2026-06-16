public class Solution {
    public bool CanJumpFromPosition(int position, int[] nums) {
        if (position == nums.Length - 1) {
            return true;
        }

        int furthestJump = Math.Min(position + nums[position], nums.Length - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump;
             nextPosition++) {
            if (CanJumpFromPosition(nextPosition, nums)) {
                return true;
            }
        }

        return false;
    }

    public bool CanJump(int[] nums) {
        return CanJumpFromPosition(0, nums);
    }
}
