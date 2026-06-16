var maxIceCream = function(costs, coins) {
    // Store ice cream costs in increasing order.
    costs.sort((num1, num2) => num1 - num2);

    let n = costs.length;
    let icecream = 0;

    // Pick ice creams till we can.
    while (icecream < n && costs[icecream] <= coins) {
        // We can buy this icecream, reduce the cost from the coins. 
        coins -= costs[icecream];
        icecream += 1;
    }

    return icecream;
};
