class Solution {
public:
    bool canPermutePalindrome(string s) {
        int map[128] = {0};
        for (char c : s) {
            map[int(c)]++;
        }
        int count = 0;
        for (int i = 0; i < 128 && count <= 1; i++) {
            count += map[i] % 2;
        }
        return count <= 1;
    }
};
