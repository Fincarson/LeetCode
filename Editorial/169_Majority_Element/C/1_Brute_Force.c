int majorityElement(int* nums, int numsSize) {
    int majorityCount = numsSize / 2;

    for (int i = 0; i < numsSize; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }

        if (count > majorityCount) {
            return nums[i];
        }
    }

    return -1;
}
