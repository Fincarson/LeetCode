var buyChoco = function(prices, money) {
    // Sort the Array in Increasing Order
    prices.sort((a, b) => a - b);

    // Minimum Cost
    let minCost = prices[0] + prices[1];

    // We can buy chocolates only if we have enough money
    if (minCost <= money) {
        // Return the Amount of Money Left
        return money - minCost;
    } else {
        // We cannot buy chocolates. Return the initial amount of money
        return money;
    }
};
