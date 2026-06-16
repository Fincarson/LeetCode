var checkRecord = function (n) {
    const MOD = 1000000007;
    // Cache to store current sub-problem results.
    let dpCurrState = Array.from({ length: 2 }, () => Array(3).fill(0));
    // Cache to store next sub-problem results.
    let dpNextState = Array.from({ length: 2 }, () => Array(3).fill(0));

    // Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
    dpCurrState[0][0] = 1;

    // Iterate on smaller sub-problems and use the current smaller sub-problem
    // to generate results for bigger sub-problems.
    for (let len = 0; len < n; ++len) {
        for (let totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
            for (
                let consecutiveLates = 0;
                consecutiveLates <= 2;
                ++consecutiveLates
            ) {
                // Store the count when 'P' is chosen.
                dpNextState[totalAbsences][0] =
                    (dpNextState[totalAbsences][0] +
                        dpCurrState[totalAbsences][consecutiveLates]) %
                    MOD;
                // Store the count when 'A' is chosen.
                if (totalAbsences < 1) {
                    dpNextState[totalAbsences + 1][0] =
                        (dpNextState[totalAbsences + 1][0] +
                            dpCurrState[totalAbsences][consecutiveLates]) %
                        MOD;
                }
                // Store the count when 'L' is chosen.
                if (consecutiveLates < 2) {
                    dpNextState[totalAbsences][consecutiveLates + 1] =
                        (dpNextState[totalAbsences][consecutiveLates + 1] +
                            dpCurrState[totalAbsences][consecutiveLates]) %
                        MOD;
                }
            }
        }

        // Next state sub-problems will become current state sub-problems in the next iteration.
        dpCurrState = dpNextState.map((row) => row.slice());
        // Next state sub-problem results will reset to zero.
        dpNextState = Array.from({ length: 2 }, () => Array(3).fill(0));
    }

    // Sum up the counts for all combinations of length 'n' with different absent and late counts.
    let count = dpCurrState.flat().reduce((acc, val) => (acc + val) % MOD, 0);
    return count;
};
