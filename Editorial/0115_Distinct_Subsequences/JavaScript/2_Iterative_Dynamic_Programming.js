// JavaScript
var numDistinct = function (s, t) {
    let M = s.length;
    let N = t.length;
    // Dynamic Programming table
    let dp = Array.from({ length: M + 1 }, () =>
        Array.from({ length: N + 1 }, () => 0),
    );
    // Base case initialization
    for (let j = 0; j <= N; ++j) dp[M][j] = 0;
    // Base case initialization
    for (let i = 0; i <= M; ++i) dp[i][N] = 1;
    // Iterate over the strings in reverse so as to
    // satisfy the way we've modeled our recursive solution
    for (let i = M - 1; i >= 0; --i) {
        for (let j = N - 1; j >= 0; --j) {
            // Remember, we always need this result
            dp[i][j] = dp[i + 1][j];
            // If the characters match, we add the
            // result of the next recursion call (in this
            // case, the value of a cell in the dp table)
            if (s[i] === t[j]) dp[i][j] += dp[i + 1][j + 1];
        }
    }
    return dp[0][0];
};
