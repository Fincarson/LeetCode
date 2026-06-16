var countOrders = function(n) {
    let ans = 1;
    let MOD = 1_000_000_007;

    for (let i = 1; i <= n; ++i) {
        // Ways to arrange all pickups, 1*2*3*4*5*...*n
        ans = ans * i;
        // Ways to arrange all deliveries, 1*3*5*...*(2n-1)
        ans = ans * (2 * i - 1);
        ans %= MOD;
    }

    return ans;
};
