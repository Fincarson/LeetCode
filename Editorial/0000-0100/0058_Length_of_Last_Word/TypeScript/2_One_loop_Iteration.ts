function lengthOfLastWord(s: string): number {
    var p = s.length,
        length = 0;
    while (p > 0) {
        p--;
        // we're in the middle of the last word
        if (s[p] !== " ") {
            length++;
        }
        // here is the end of last word
        else if (length > 0) {
            return length;
        }
    }
    return length;
}
