int maxIncreasingSubarrays(int* nums, int numsSize) {
    int cnt = 1, precnt = 0, ans = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] > nums[i - 1]) {
            ++cnt;
        } else {
            precnt = cnt;
            cnt = 1;
        }
        int min_val = precnt < cnt ? precnt : cnt;
        ans = ans > min_val ? ans : min_val;
        ans = ans > cnt / 2 ? ans : cnt / 2;
    }
    return ans;
}
