int maxSubArray(int* nums, int numsSize) {
    return findBestSubarray(nums, 0, numsSize - 1);
}
int findBestSubarray(int* nums, int left, int right) {
    // Base case - empty array.
    if (left > right) {
        return INT_MIN;
    }
    int mid = (left + right) / 2;
    int curr = 0;
    int bestLeftSum = 0;
    int bestRightSum = 0;
    // Iterate from the middle to the beginning.
    for (int i = mid - 1; i >= left; i--) {
        curr += nums[i];
        bestLeftSum = fmax(bestLeftSum, curr);
    }
    // Reset curr and iterate from the middle to the end.
    curr = 0;
    for (int i = mid + 1; i <= right; i++) {
        curr += nums[i];
        bestRightSum = fmax(bestRightSum, curr);
    }
    // The bestCombinedSum uses the middle element and the best
    // possible sum from each half.
    int bestCombinedSum = nums[mid] + bestLeftSum + bestRightSum;
    // Find the best subarray possible from both halves.
    int leftHalf = findBestSubarray(nums, left, mid - 1);
    int rightHalf = findBestSubarray(nums, mid + 1, right);
    // The largest of the 3 is the answer for any given input array.
    return fmax(bestCombinedSum, fmax(leftHalf, rightHalf));
}
