int singleNumber(int* nums, int numsSize) {
    // Loner
    long loner = 0;
    // Iterate over all bits
    for (int shift = 0; shift < 32; shift++) {
        int bitSum = 0;
        // For this bit, iterate over all integers
        for (int i = 0; i < numsSize; i++) {
            // Compute the bit of num, and add it to bitSum
            bitSum += (nums[i] >> shift) & 1;
        }
        // Compute the bit of loner and place it
        long lonerBit = bitSum % 3;
        loner = loner | (lonerBit << shift);
    }
    return (int)loner;
}
