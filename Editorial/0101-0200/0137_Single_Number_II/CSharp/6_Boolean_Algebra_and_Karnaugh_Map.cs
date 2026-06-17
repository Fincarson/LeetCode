public class Solution {
    public int SingleNumber(int[] nums) {
        // Count (modulo 3) bits
        int msb = 0, lsb = 0;
        // Process Every Num and update count bits
        foreach (int num in nums) {
            int new_lsb = (~msb & ~lsb & num) | (lsb & ~num);
            int new_msb = (lsb & num) | (msb & ~num);
            lsb = new_lsb;
            msb = new_msb;
        }

        // Return lsb as the answer
        return lsb;
    }
}
