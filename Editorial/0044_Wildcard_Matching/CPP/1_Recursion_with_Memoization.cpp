class Solution {
public:
    unordered_map<string, bool> dp;
    string p;
    string s;
    string remove_duplicate_stars(string p) {
        string new_string = "";
        for (auto &c : p) {
            if (new_string.empty() || c != '*')
                new_string += c;
            else if (new_string.back() != '*')
                new_string += c;
        }
        return new_string;
    }
    bool helper(int si, int pi) {
        string key = to_string(si) + "," + to_string(pi);
        if (dp.count(key)) return dp[key];
        if (pi == p.size())
            dp[key] = (si == s.size());
        else if (si == s.size())
            dp[key] = (pi + 1 == p.size() && p[pi] == '*');
        else if (p[pi] == s[si] || p[pi] == '?')
            dp[key] = helper(si + 1, pi + 1);
        else if (p[pi] == '*')
            dp[key] = helper(si, pi + 1) || helper(si + 1, pi);
        else
            dp[key] = false;
        return dp[key];
    }
    bool isMatch(string s, string p) {
        dp.clear();
        this->s = s;
        this->p = remove_duplicate_stars(p);
        return helper(0, 0);
    }
};
