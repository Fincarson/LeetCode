var numDistinct = function (s, t) {
    let memo = new Map();
    function dp(i, j) {
        if (i === s.length || j === t.length || s.length - i < t.length - j)
            return j === t.length ? 1 : 0;
        let key = [i, j].toString();
        if (memo.has(key)) return memo.get(key);
        let ans = dp(i + 1, j);
        if (s[i] === t[j]) ans += dp(i + 1, j + 1);
        memo.set(key, ans);
        return ans;
    }
    return dp(0, 0);
};
