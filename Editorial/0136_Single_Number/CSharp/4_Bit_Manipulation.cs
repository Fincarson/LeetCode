// C#

public class Solution {
    public int SingleNumber(int[] nums) {
        int a = 0;
        foreach (int i in nums) {
            a ^= i;
        }

        return a;
    }
}
