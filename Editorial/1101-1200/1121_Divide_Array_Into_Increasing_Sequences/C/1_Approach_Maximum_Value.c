bool canDivideIntoSubsequences(int* nums, int numsSize, int k) {
    int pre = nums[0], cnt = 0;
    for (int i = 0; i < numsSize; i++) {
        int n = nums[i];
        if (n == pre) {
            cnt++;
        } else {
            pre = n;
            cnt = 1;
        }
        if (cnt * k > numsSize) {
            return 0;
        }
    }
    return 1;
}
