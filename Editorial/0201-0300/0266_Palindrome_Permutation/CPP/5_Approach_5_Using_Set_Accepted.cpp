class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> char_set;
        for (char c : s) {
            if (char_set.find(c) != char_set.end())
                char_set.erase(c);
            else
                char_set.insert(c);
        }
        return char_set.size() <= 1;
    }
};
