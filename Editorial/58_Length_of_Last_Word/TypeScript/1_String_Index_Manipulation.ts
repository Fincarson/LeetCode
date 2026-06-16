function lengthOfLastWord(s: string): number {
    // trim the trailing spaces
    let p = s.length - 1;
    while (p >= 0 && s[p] === " ") {
        p--;
    }
    // compute the length of last word
    let length = 0;
    while (p >= 0 && s[p] !== " ") {
        p--;
        length++;
    }
    return length;
}
