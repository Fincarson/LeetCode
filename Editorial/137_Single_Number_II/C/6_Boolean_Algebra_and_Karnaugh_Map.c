int singleNumber(int* nums, int numsSize) {
    // Count (modulo 3) bits
    int msb = 0, lsb = 0;
    // Process Every Num and update count bits
    for (int i = 0; i < numsSize; i++) {
        int new_lsb = (~msb & ~lsb & nums[i]) | (lsb & ~nums[i]);
        int new_msb = (lsb & nums[i]) | (msb & ~nums[i]);
        lsb = new_lsb;
        msb = new_msb;
    }
    // Return lsb as the answer
    return lsb;
}
