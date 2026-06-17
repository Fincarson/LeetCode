class Solution {
private:
    unordered_map<string, int> memo;

public:
    int numDistinct(string s, string t) {
        if (s.size() < t.size()) return 0;
        if (s == t || t.empty()) return 1;
        string key = to_string(s.size()) + "," + to_string(t.size());
        if (memo.find(key) != memo.end()) return memo[key];
        int N = s.size(), M = t.size();
        int ans = numDistinct(s.substr(0, N - 1), t);
        if (s[N - 1] == t[M - 1])
            ans += numDistinct(s.substr(0, N - 1), t.substr(0, M - 1));
        memo[key] = ans;
        return ans;
    }
};
