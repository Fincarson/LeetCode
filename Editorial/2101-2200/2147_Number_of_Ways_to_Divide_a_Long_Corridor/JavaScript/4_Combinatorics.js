var numberOfWays = function(corridor) {
    // Store 1000000007 in a variable for convenience
    const MOD = 1e9 + 7;
    
    // Store indices of S in an array
    const indices = [];
    for (let index = 0; index < corridor.length; index++) {
        if (corridor[index] == 'S') {
            indices.push(index);
        }
    }

    // When division is not possible
    if (indices.length == 0 || indices.length % 2 == 1) {
        return 0;
    }

    // Total number of ways
    let count = 1;

    // Take product of non-paired neighbors
    let previousPairLast = 1;
    let currentPairFirst = 2;
    while (currentPairFirst < indices.length) {
        count *= (indices[currentPairFirst] - indices[previousPairLast]);
        count %= MOD;
        previousPairLast += 2;
        currentPairFirst += 2;
    }

    // Return the number of ways
    return count;
};
