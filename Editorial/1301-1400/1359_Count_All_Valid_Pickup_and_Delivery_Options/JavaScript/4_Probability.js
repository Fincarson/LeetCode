var countOrders = function(n) {
    let ans = 1;
    let MOD = 1_000_000_007;

    for (let i = 1; i <= 2 * n; ++i) {
        ans = ans * i;

        // We only need to divide the result by 2 n-times.
        // To prevent decimal results we divide after multiplying an even number.
        if (i % 2 == 0) {
            ans = ans / 2;
        }
        ans %= MOD;
    }
    return ans;
};
