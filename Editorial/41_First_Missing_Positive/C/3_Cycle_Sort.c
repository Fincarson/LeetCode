int firstMissingPositive(int* nums, int numsSize) {
    int n = numsSize;
    // Use cycle sort to place positive elements smaller than n
    // at the correct index
    int i = 0;
    while (i < n) {
        int correctIdx = nums[i] - 1;
        if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIdx]) {
            int temp = nums[i];
            nums[i] = nums[correctIdx];
            nums[correctIdx] = temp;
        } else {
            i++;
        }
    }
    // Iterate through nums
    // return smallest missing positive integer
    for (i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    // If all elements are at the correct index
    // the smallest missing positive number is n + 1
    return n + 1;
}
