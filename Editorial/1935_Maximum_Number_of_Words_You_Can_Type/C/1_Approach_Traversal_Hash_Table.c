int canBeTypedWords(char* text, char* brokenLetters) {
    bool broken[26] = {false};  // set of broken letter keys
    for (int i = 0; brokenLetters[i]; i++) {
        broken[brokenLetters[i] - 'a'] = true;
    }
    int res = 0;  // the number of words that can be fully inputted
    bool flag =
        true;  // is the current character in the word completely inputtable
    for (int i = 0; text[i]; i++) {
        if (text[i] == ' ') {
            // the current character is a space, check the status of the
            // previous word, update the count and initialize the flag
            if (flag) {
                ++res;
            }
            flag = true;
        } else if (broken[text[i] - 'a']) {
            // the current character cannot be entered, the word it is in cannot
            // be fully entered, update flag
            flag = false;
        }
    }
    // judge the status of the last word and update the count
    if (flag) {
        ++res;
    }
    return res;
}
