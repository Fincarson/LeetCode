// Here a recursive depth-first-search is used along with memoization to avoid repetetive work as much as possible. JavaScript is used in an expressive and clear way in this problem, which makes it easy for a developer to quickly understand the code logic.
var isInterleave = function (s1, s2, s3) {
    function is_Interleave(i, j, k, memo) {
        if (i == s1.length) {
            return s2.substring(j) == s3.substring(k);
        }
        if (j == s2.length) {
            return s1.substring(i) == s3.substring(k);
        }
        if (memo[i][j] >= 0) {
            return memo[i][j] == 1;
        }
        var ans = false;
        if (
            (s3.charAt(k) == s1.charAt(i) &&
                is_Interleave(i + 1, j, k + 1, memo)) ||
            (s3.charAt(k) == s2.charAt(j) &&
                is_Interleave(i, j + 1, k + 1, memo))
        ) {
            ans = true;
        }
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }
    if (s1.length + s2.length != s3.length) {
        return false;
    }
    var memo = Array(s1.length)
        .fill(0)
        .map((x) => Array(s2.length).fill(-1));
    return is_Interleave(0, 0, 0, memo);
};
