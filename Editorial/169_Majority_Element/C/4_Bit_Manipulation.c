int majorityElement(int* nums, int numsSize) {
    int majority_element = 0;

    for (int i = 0; i < 32; i++) {
        unsigned int bit = 1u << i;

        // Count how many numbers have this bit set.
        int bit_count = 0;
        for (int j = 0; j < numsSize; j++) {
            if ((nums[j] & bit) != 0) {
                bit_count++;
            }
        }

        // If this bit is present in more than n / 2 elements
        // then it must be set in the majority element.
        if (bit_count > numsSize / 2) {
            majority_element |= bit;
        }
    }

    return majority_element;
}
