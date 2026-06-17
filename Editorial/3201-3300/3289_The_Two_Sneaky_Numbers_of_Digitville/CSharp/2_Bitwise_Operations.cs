public class Solution {
    public int[] GetSneakyNumbers(int[] nums) {
        int n = nums.Length - 2;
        int y = 0;
        foreach (int x in nums) {
            y ^= x;
        }
        for (int i = 0; i < n; i++) {
            y ^= i;
        }
        int lowBit = y & -y;
        int x1 = 0, x2 = 0;
        foreach (int x in nums) {
            if ((x & lowBit) != 0) {
                x1 ^= x;
            } else {
                x2 ^= x;
            }
        }
        for (int i = 0; i < n; i++) {
            if ((i & lowBit) != 0) {
                x1 ^= i;
            } else {
                x2 ^= i;
            }
        }
        return new int[] { x1, x2 };
    }
}
