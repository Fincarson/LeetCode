var countOrders = function(n) {
    let MOD = 1_000_000_007;
    let dp = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));

    for (let unpicked = 0; unpicked <= n; unpicked++) {
        for (let undelivered = unpicked; undelivered <= n; undelivered++) {
            // If all orders are picked and delivered then,
            // for remaining '0' orders we have only one way.
            if (unpicked == 0 && undelivered == 0) {
                dp[unpicked][undelivered] = 1;
                continue;
            }

            // There are some unpicked elements left. 
            // We have choice to pick any one of those orders.
            if (unpicked > 0) {
                dp[unpicked][undelivered] += unpicked * dp[unpicked - 1][undelivered];
            }
            dp[unpicked][undelivered] %= MOD;

            // Number of deliveries done is less than picked orders.
            // We have choice to deliver any one of (undelivered - unpicked) orders. 
            if (undelivered > unpicked) {
                dp[unpicked][undelivered] += (undelivered - unpicked) * dp[unpicked][undelivered - 1];
            }
            dp[unpicked][undelivered] %= MOD;
        }
    }

    return dp[n][n];
};
