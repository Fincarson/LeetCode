int sumFourDivisors(int* nums, int numsSize) {
    int ans = 0;
    for (int idx = 0; idx < numsSize; idx++) {
        int num = nums[idx];
        // factor_cnt: number of factors
        // factor_sum: sum of factors
        int factor_cnt = 0, factor_sum = 0;
        for (int i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                ++factor_cnt;
                factor_sum += i;
                if (i * i != num) {  // check if i and num/i are equal; if not,
                                     // consider num/i as a new factor.
                    ++factor_cnt;
                    factor_sum += num / i;
                }
            }
        }
        if (factor_cnt == 4) {
            ans += factor_sum;
        }
    }
    return ans;
}
