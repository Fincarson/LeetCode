class Solution {
public:
    bool canPermutePalindrome(string s) {
        int map[128] = {0};
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            map[int(s[i])]++;
            if (map[int(s[i])] % 2 == 0)
                count--;
            else
                count++;
        }
        return count <= 1;
    }
};
