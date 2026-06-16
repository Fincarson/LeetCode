class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> map;
        for (int i = 0; i < s.length(); i++) {
            +map[s[i]]++;
        }
        int count = 0;
        for (auto& pair : map) {
            count += pair.second % 2;
        }
        return count <= 1;
    }
};
