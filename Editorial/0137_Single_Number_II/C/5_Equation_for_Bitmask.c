int singleNumber(int* nums, int numsSize) {
    // Initialize seenOnce and seenTwice to 0
    int seenOnce = 0, seenTwice = 0;

    // Iterate through nums
    for (int i = 0; i < numsSize; i++) {
        // Update using derived equations
        seenOnce = (seenOnce ^ nums[i]) & (~seenTwice);
        seenTwice = (seenTwice ^ nums[i]) & (~seenOnce);
    }

    // Return integer which appears exactly once
    return seenOnce;
}
