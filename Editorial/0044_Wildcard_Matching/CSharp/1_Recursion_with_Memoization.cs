public class Solution {
    Dictionary<string, bool> dp = new Dictionary<string, bool>();
    string s;
    string p;

    string remove_duplicate_stars(string p) {
        var new_string = new StringBuilder();
        foreach (var c in p) {
            if (new_string.Length == 0 || c != '*')
                new_string.Append(c);
            else if (new_string[new_string.Length - 1] != '*')
                new_string.Append(c);
        }

        return new_string.ToString();
    }

    bool helper(int si, int pi) {
        var key = si + "," + pi;
        if (dp.ContainsKey(key))
            return dp[key];
        if (pi == p.Length)
            dp[key] = si == s.Length;
        else if (si == s.Length)
            dp[key] = pi + 1 == p.Length && p[pi] == '*';
        else if (p[pi] == s[si] || p[pi] == '?')
            dp[key] = helper(si + 1, pi + 1);
        else if (p[pi] == '*')
            dp[key] = helper(si, pi + 1) || helper(si + 1, pi);
        else
            dp[key] = false;
        return dp[key];
    }

    public bool IsMatch(string s, string p) {
        dp.Clear();
        this.s = s;
        this.p = remove_duplicate_stars(p);
        return helper(0, 0);
    }
}
