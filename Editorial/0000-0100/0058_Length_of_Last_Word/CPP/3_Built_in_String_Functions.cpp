class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        int lastIndex = s.size() - 1;
        // Discard the trailing spaces
        while (lastIndex >= 0 && s[lastIndex] == ' ') lastIndex--;
        // Iterate through the last word
        while (lastIndex >= 0 && s[lastIndex] != ' ') {
            count++;
            lastIndex--;
        }
        return count;
    }
};
