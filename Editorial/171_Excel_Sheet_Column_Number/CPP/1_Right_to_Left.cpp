class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;

        // Decimal 65 in ASCII corresponds to char 'A'
        map<char, int> alpha_map;
        for (int i = 0; i < 26; i++) alpha_map[char(i + 65)] = i + 1;

        int n = s.length();
        for (int i = 0; i < n; i++) {
            char cur_char = s[n - 1 - i];
            result += (alpha_map[cur_char] * (pow(26, i)));
        }
        return result;
    }
};
