class Solution {

    public int checkRecord(int n) {
        int MOD = 1000000007;
        // Cache to store current sub-problem results.
        int[][] dpCurrState = new int[2][3];
        // Cache to store next sub-problem results.
        int[][] dpNextState = new int[2][3];

        // Base case: there is 1 string of length 0 with zero 'A' and zero 'L'.
        dpCurrState[0][0] = 1;

        // Iterate on smaller sub-problems and use the current smaller sub-problem
        // to generate results for bigger sub-problems.
        for (int len = 0; len < n; ++len) {
            for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
                for (
                    int consecutiveLates = 0;
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
            System.arraycopy(
                dpNextState,
                0,
                dpCurrState,
                0,
                dpCurrState.length
            );
            // Next state sub-problem results will reset to zero.
            dpNextState = new int[2][3];
        }

        // Sum up the counts for all combinations of length 'n' with different absent and late counts.
        int count = 0;
        for (int totalAbsences = 0; totalAbsences <= 1; ++totalAbsences) {
            for (
                int consecutiveLates = 0;
                consecutiveLates <= 2;
                ++consecutiveLates
            ) {
                count = (count + dpCurrState[totalAbsences][consecutiveLates]) %
                MOD;
            }
        }
        return count;
    }
}
