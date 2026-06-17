var numberOfWays = function(corridor) {
    // Store 1000000007 in a variable for convenience
    const MOD = 1e9 + 7;
    
    // Cache the result of each sub-problem
    const cache = new Map();

    // Count the number of ways to divide from "index" to the last index
    // with "seats" number of "S" in the current section
    const count = (index, seats) => {
        // If we have reached the end of the corridor, then
        // the current section is valid only if "seats" is 2
        if (index == corridor.length) {
            return seats == 2 ? 1 : 0;
        }

        // If we have already computed the result of this sub-problem,
        // then return the cached result
        if (cache.has(`${index}-${seats}`)) {
            return cache.get(`${index}-${seats}`);
        }

        // Result of the sub-problem
        let result = 0;

        // If the current section has exactly 2 "S"
        if (seats == 2) {
            // If the current element is "S", then we have to close the
            // section and start a new section from this index. Next index
            // will have one "S" in the current section
            if (corridor[index] == 'S') {
                result = count(index + 1, 1);
            } else {
                // If the current element is "P", then we have two options
                // 1. Close the section and start a new section from this index
                // 2. Keep growing the section
                result = (count(index + 1, 0) + count(index + 1, 2)) % MOD;  
            }
        } else {
            // Keep growing the section. Increment "seats" if present
            // element is "S"
            if (corridor[index] == 'S') {
                result = count(index + 1, seats + 1);
            } else {
                result = count(index + 1, seats);
            }
        }

        // Memoize the result, and return it
        cache.set(`${index}-${seats}`, result);
        return result;
    }

    // Call the count function
    return count(0, 0);
};
