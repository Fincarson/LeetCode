class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;  // set of broken letter keys
        for (char ch : brokenLetters) {
            broken.insert(ch);
        }
        int res = 0;  // the number of words that can be fully inputted
        bool flag =
            true;  // is the current character in the word completely inputtable
        for (char ch : text) {
            if (ch == ' ') {
                // the current character is a space, check the status of the
                // previous word, update the count and initialize the flag
                if (flag) {
                    ++res;
                }
                flag = true;
            } else if (broken.count(ch)) {
                // the current character cannot be entered, the word it is in
                // cannot be fully entered, update flag
                flag = false;
            }
        }
        // judge the status of the last word and update the count
        if (flag) {
            ++res;
        }
        return res;
    }
};
