class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'i' || c == 'e' || c == 'o' || c == 'u';
    }

    string removeVowels(string s) {
        string ans;

        for (char c : s) {
            if (!isVowel(c)) {
                ans += c;
            }
        }
        
        return ans;
    }
};
