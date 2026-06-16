function numDistinct(s: string, t: string): number {
    let memo = new Map<string, number>();
    function helper(i: number, j: number): number {
        if (i === s.length || j === t.length || s.length - i < t.length - j)
            return j === t.length ? 1 : 0;
        let key = i + "," + j;
        if (memo.has(key)) return memo.get(key) as number;
        let ans = helper(i + 1, j);
        if (s[i] === t[j]) ans += helper(i + 1, j + 1);
        memo.set(key, ans);
        return ans;
    }
    return helper(0, 0);
}
