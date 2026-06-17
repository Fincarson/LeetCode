var checkRecord = function (n) {
    let MOD = 1000000007;
    // Initialize the cache to store sub-problem results.
    let memo = new Array(n + 1)
        .fill(null)
        .map(() => new Array(2).fill(null).map(() => new Array(3).fill(-1)));

    // Recursive function to return the count of combinations of length 'n' eligible for the award.
    let eligibleCombinations = (n, totalAbsences, consecutiveLates) => {
        // If the combination has become not eligible for the award,
        // then we will not count any combinations that can be made using it.
        if (totalAbsences >= 2 || consecutiveLates >= 3) {
            return 0;
        }
        // If we have generated a combination of length 'n' we will count it.
        if (n === 0) {
            return 1;
        }
        // If we have already seen this sub-problem earlier, we return the stored result.
        if (memo[n][totalAbsences][consecutiveLates] !== -1) {
            return memo[n][totalAbsences][consecutiveLates];
        }

        let count = 0;
        // We choose 'P' for the current position.
        count = eligibleCombinations(n - 1, totalAbsences, 0);
        // We choose 'A' for the current position.
        count =
            (count + eligibleCombinations(n - 1, totalAbsences + 1, 0)) % MOD;
        // We choose 'L' for the current position.
        count =
            (count +
                eligibleCombinations(
                    n - 1,
                    totalAbsences,
                    consecutiveLates + 1,
                )) %
            MOD;

        // Return and store the current sub-problem result in the cache.
        memo[n][totalAbsences][consecutiveLates] = count;
        return count;
    };

    // Return count of combinations of length 'n' eligible for the award.
    return eligibleCombinations(n, 0, 0);
};
