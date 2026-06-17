var buyChoco = function(prices, money) {
    // Assume minimum and second minimum
    let minimum = Math.min(prices[0], prices[1]);
    let secondMinimum = Math.max(prices[0], prices[1]);

    // Iterate over the remaining elements
    for (let i = 2; i < prices.length; i++) {
        if (prices[i] < minimum) {
            secondMinimum = minimum;
            minimum = prices[i];
        } else if (prices[i] < secondMinimum) {
            secondMinimum = prices[i];
        }
    }

    // Minimum Cost
    let minCost = minimum + secondMinimum;

    // We can buy chocolates only if we have enough money
    if (minCost <= money) {
        // Return the Amount of Money Left
        return money - minCost;
    }

    // We cannot buy chocolates. Return the initial amount of money
    return money;
};
