int countOccurences(int* nums, int num, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == num) {
            count++;
        }
    }
    return count;
}

int majorityElement(int* nums, int numsSize) {
    srand(time(0));
    int majorityCount = numsSize / 2;
    while (1) {
        int candidate = nums[rand() % numsSize];
        if (countOccurences(nums, candidate, numsSize) > majorityCount) {
            return candidate;
        }
    }
}
