class Solution {
    public int singleNumber(int[] nums) {
        // Count (modulo 3) bits
        int msb = 0, lsb = 0;

        // Process Every Num and update count bits
        for (int num : nums) {
            int new_lsb = (~msb & ~lsb & num) | (lsb & ~num);
            int new_msb = (lsb & num) | (msb & ~num);
            lsb = new_lsb;
            msb = new_msb;
        }

        // Return lsb as answer
        return lsb;
    }
}
