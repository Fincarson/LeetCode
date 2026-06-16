function isMatch(s: string, p: string): boolean {
    let dp: { [key: string]: boolean } = {};
    function remove_duplicate_stars(p: string): string {
        let new_string = "";
        for (let c of p) {
            if (new_string.length == 0 || c != "*") new_string += c;
            else if (new_string[new_string.length - 1] != "*") new_string += c;
        }
        return new_string;
    }
    function helper(si: number, pi: number): boolean {
        let key = si + "," + pi;
        if (key in dp) return dp[key];
        if (pi == p.length) dp[key] = si == s.length;
        else if (si == s.length) dp[key] = pi + 1 == p.length && p[pi] == "*";
        else if (p[pi] == s[si] || p[pi] == "?")
            dp[key] = helper(si + 1, pi + 1);
        else if (p[pi] == "*")
            dp[key] = helper(si, pi + 1) || helper(si + 1, pi);
        else dp[key] = false;
        return dp[key];
    }
    p = remove_duplicate_stars(p);
    return helper(0, 0);
}
