var isMatch = function (s, p) {
    var dp = {};
    var remove_duplicate_stars = function (p) {
        var new_string = "";
        for (var c of p) {
            if (new_string.length == 0 || c != "*") new_string += c;
            else if (new_string[new_string.length - 1] != "*") new_string += c;
        }
        return new_string;
    };
    var helper = function (si, pi) {
        var key = si + "," + pi;
        if (key in dp) return dp[key];
        if (pi == p.length) dp[key] = si == s.length;
        else if (si == s.length) dp[key] = pi + 1 == p.length && p[pi] == "*";
        else if (p[pi] == s[si] || p[pi] == "?")
            dp[key] = helper(si + 1, pi + 1);
        else if (p[pi] == "*")
            dp[key] = helper(si, pi + 1) || helper(si + 1, pi);
        else dp[key] = false;
        return dp[key];
    };
    p = remove_duplicate_stars(p);
    return helper(0, 0);
};
