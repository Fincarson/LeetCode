var numberOfWays = function(corridor) {
    // Store 1000000007 in a variable for convenience
    const MOD = 1e9 + 7;
    
    // Initial values of three variables
    let zero = 0;
    let one = 0;
    let two = 1;

    // Compute using derived equations
    for (thing of corridor) {
        if (thing == 'S') {
            zero = one;
            [one, two] = [two, one];
        } else {
            two = (two + zero) % MOD;
        }
    }

    // Return the result
    return zero;
};
