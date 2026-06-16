let MOD = 1_000_000_007;
let memo;

let totalWays = (unpicked, undelivered) => {
    if (unpicked == 0 && undelivered == 0) {
        // We have completed all orders.
        return 1;
    }

    if (unpicked < 0 || undelivered < 0 || undelivered < unpicked) {
        // We can't pick or deliver more than N items
        // Number of deliveries can't exceed number of pickups 
        // as we can only deliver after a pickup.
        return 0;
    }

    if (memo[unpicked][undelivered]) {
        // Return cached value, if already present. 
        return memo[unpicked][undelivered];
    }

    let ans = 0;

    // Count all choices of picking up an order.
    ans += unpicked * totalWays(unpicked - 1, undelivered);
    // Handle integer overflow.
    ans %= MOD;

    // Count all choices of delivering a picked order.
    ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1);
    // Handle integer overflow.
    ans %= MOD;

    return memo[unpicked][undelivered] = ans;
}

var countOrders = function(n) {
    memo = new Array(n + 1).fill(0).map(() => new Array(n + 1).fill(0));
    return totalWays(n, n);
};
