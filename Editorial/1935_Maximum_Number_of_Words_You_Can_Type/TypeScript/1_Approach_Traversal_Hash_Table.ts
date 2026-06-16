function canBeTypedWords(text: string, brokenLetters: string): number {
    const broken = new Set<string>(); // set of broken letter keys
    for (const ch of brokenLetters) {
        broken.add(ch);
    }
    let res = 0; // the number of words that can be fully inputted
    let flag = true; // is the current character in the word completely inputtable
    for (const ch of text) {
        if (ch === " ") {
            // the current character is a space, check the status of the previous word, update the count and initialize the flag
            if (flag) {
                ++res;
            }
            flag = true;
        } else if (broken.has(ch)) {
            // the current character cannot be entered, the word it is in cannot be fully entered, update flag
            flag = false;
        }
    }
    // judge the status of the last word and update the count
    if (flag) {
        ++res;
    }
    return res;
}
