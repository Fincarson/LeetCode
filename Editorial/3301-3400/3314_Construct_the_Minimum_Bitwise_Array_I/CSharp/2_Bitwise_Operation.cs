public class Solution {
    public int[] MinBitwiseArray(IList<int> nums) {
        for (int i = 0; i < nums.Count; i++) {
            int x = nums[i];
            int res = -1;
            int d = 1;
            while ((x & d) != 0) {
                res = x - d;
                d <<= 1;
            }
            nums[i] = res;
        }
        return nums.ToArray();
    }
}
