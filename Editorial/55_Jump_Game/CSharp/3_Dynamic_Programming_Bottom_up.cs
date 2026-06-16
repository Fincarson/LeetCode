public enum Index { GOOD, BAD, UNKNOWN }

public class Solution {
    public bool CanJump(int[] nums) {
        Index[] memo = new Index[nums.Length];
        for (int i = 0; i < memo.Length; i++) {
            memo[i] = Index.UNKNOWN;
        }

        memo[memo.Length - 1] = Index.GOOD;
        for (int i = nums.Length - 2; i >= 0; i--) {
            int furthestJump = Math.Min(i + nums[i], nums.Length - 1);
            for (int j = i + 1; j <= furthestJump; j++) {
                if (memo[j] == Index.GOOD) {
                    memo[i] = Index.GOOD;
                    break;
                }
            }
        }

        return memo[0] == Index.GOOD;
    }
}
