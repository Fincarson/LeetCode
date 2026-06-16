int minElement(int* nums, int numsSize) {
    int ans = 37;
    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int dig = 0;
        while (num > 0) {
            dig += num % 10;
            num /= 10;
        }
        if (dig < ans) {
            ans = dig;
        }
    }
    return ans;
}
