class Solution {
public:
    bool isAnagram(string s, string t) {
        int check[128] = {0}, i = 0;
        for(i = 0; i < s.length(); i++) check[s[i]] += 1;
        for(i = 0; i < t.length(); i++) check[t[i]] -= 1;
        for(i = 0; i <= 127; i++) if(check[i] != 0) return false;
        return true;
    }
};