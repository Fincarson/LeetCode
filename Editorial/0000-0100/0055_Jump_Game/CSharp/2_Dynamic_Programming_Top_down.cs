public enum Index { GOOD, BAD, UNKNOWN }

public class Solution {
    Index[] memo;

    public bool CanJumpFromPosition(int position, int[] nums) {
        if (memo[position] != Index.UNKNOWN) {
            return memo[position] == Index.GOOD ? true : false;
        }

        int furthestJump = Math.Min(position + nums[position], nums.Length - 1);
        for (int nextPosition = position + 1; nextPosition <= furthestJump;
             nextPosition++) {
            if (CanJumpFromPosition(nextPosition, nums)) {
                memo[position] = Index.GOOD;
                return true;
            }
        }

        memo[position] = Index.BAD;
        return false;
    }

    public bool CanJump(int[] nums) {
        memo = new Index[nums.Length];
        for (int i = 0; i < memo.Length; i++) {
            memo[i] = Index.UNKNOWN;
        }

        memo[memo.Length - 1] = Index.GOOD;
        return CanJumpFromPosition(0, nums);
    }
}
