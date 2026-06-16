public class Solution {
    public int SingleNumber(int[] nums) {
        // Loner
        int loner = 0;
        // Iterate over all bits
        for (int shift = 0; shift < 32; shift++) {
            int bitSum = 0;
            // For this bit, iterate over all integers
            foreach (int num in nums) {
                // Compute the bit of num, and add it to bitSum
                bitSum += (num >> shift) & 1;
            }

            // Compute the bit of loner and place it
            int lonerBit = bitSum % 3;
            loner = loner | (lonerBit << shift);
        }

        return loner;
    }
}
