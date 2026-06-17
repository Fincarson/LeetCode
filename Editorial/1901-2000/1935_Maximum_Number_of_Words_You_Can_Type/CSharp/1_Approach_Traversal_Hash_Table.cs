public class Solution {
    public int CanBeTypedWords(string text, string brokenLetters) {
        HashSet<char> broken =
            new HashSet<char>();  // set of broken letter keys
        foreach (char ch in brokenLetters) {
            broken.Add(ch);
        }
        int res = 0;  // the number of words that can be fully inputted
        bool flag =
            true;  // is the current character in the word completely inputtable
        foreach (char ch in text) {
            if (ch == ' ') {
                // the current character is a space, check the status of the
                // previous word, update the count and initialize the flag
                if (flag) {
                    ++res;
                }
                flag = true;
            } else if (broken.Contains(ch)) {
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
}
