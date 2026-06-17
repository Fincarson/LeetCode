class Solution {
public:
    bool canPermutePalindrome(string s) {
        int count[128] = {0};
        for (int j = 0; j < s.length(); j++) {
            count[s[j]]++;
        }
        int odd = 0;
        for (int i = 0; i < 128 && odd <= 1; i++) {
            odd += count[i] % 2;
        }
        return odd <= 1;
    }
};
