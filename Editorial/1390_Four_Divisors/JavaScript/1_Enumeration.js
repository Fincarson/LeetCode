var sumFourDivisors = function (nums) {
    let ans = 0;
    for (const num of nums) {
        // factor_cnt: number of factors
        // factor_sum: sum of factors
        let factor_cnt = 0,
            factor_sum = 0;
        for (let i = 1; i * i <= num; ++i) {
            if (num % i === 0) {
                ++factor_cnt;
                factor_sum += i;
                if (i * i !== num) {
                    // check if i and num/i are equal; if not, consider num/i as a new factor.
                    ++factor_cnt;
                    factor_sum += num / i;
                }
            }
        }
        if (factor_cnt === 4) {
            ans += factor_sum;
        }
    }
    return ans;
};
