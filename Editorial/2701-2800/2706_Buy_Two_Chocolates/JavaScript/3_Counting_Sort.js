var buyChoco = function(prices, money) {
    // Array to store frequency of prices
    let freq = new Array(101).fill(0);
    for (let p of prices) {
        freq[p]++;
    }

    // Assume minimum and second minimum to be zero.
    // Since prices[i] cannot be 0, the 0 value implies
    //They haven't been computed yet.
    let minimum = 0;
    let secondMinimum = 0;
    for (let price = 1; price <= 100; price++) {
        if (freq[price] > 1) {
            minimum = price;
            secondMinimum = price;
            break;
        } else if (freq[price] == 1) {
            minimum = price;
            break;
        }
    }

    // If the second minimum is not found, then find it
    if (secondMinimum == 0) {
        for (let price = minimum + 1; price <= 100; price++) {
            if (freq[price] > 0) {
                secondMinimum = price;
                break;
            }
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
