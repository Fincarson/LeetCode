var maxIceCream = function(costs, coins) {
    let n = costs.length;
    let icecreams = 0;
    let m = Math.max(...costs);

    let costsFrequency = Array(m + 1).fill(0);
    for (let cost of costs) {
        costsFrequency[cost] += 1;
    }

    for (let cost = 1; cost <= m; ++cost) {
        // No ice cream is present costing 'cost'.
        if (!costsFrequency[cost]) {
            continue;
        }
        // We don't have enough 'coins' to even pick one ice cream.
        if (coins < cost) {
            break;
        }
        
        // Count how many icecreams of 'cost' we can pick with our 'coins'.
        // Either we can pick all ice creams of 'cost' or we will be limited by remaining 'coins'.
        let count = Math.min(costsFrequency[cost], Math.floor(coins / cost));
        // We reduce price of picked ice creams from our coins.
        coins -= cost * count;
        icecreams += count;
    }

    return icecreams;
};
