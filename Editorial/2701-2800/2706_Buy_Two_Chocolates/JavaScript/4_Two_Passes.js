var indexMinimum = function(arr) {
    // Assume the First Element to be the Minimum
    let minIndex = 0;

    // Compare the Assumed Minimum with the Remaining Elements
    // and update assumed minimum if necessary
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Return the Index of the Minimum Element
    return minIndex;
};

var buyChoco = function(prices, money) {
    // Find the index of the minimum price
    let minIndex = indexMinimum(prices);

    // Save the minimum price in a variable minCost
    let minCost = prices[minIndex];
    // Assign the minimum price to be a very large integer
    prices[minIndex] = Number.MAX_SAFE_INTEGER;

    // Find the index of the second minimum price
    // which is the minimum of the remaining array
    let secondMinIndex = indexMinimum(prices);

    // Add the second minimum price to minCost
    minCost += prices[secondMinIndex];

    // We can buy chocolates only if we have enough money
    if (minCost <= money) {
        // Return the Amount of Money Left
        return money - minCost;
    }

    // We cannot buy chocolates. Return the initial amount of money
    return money;
};
