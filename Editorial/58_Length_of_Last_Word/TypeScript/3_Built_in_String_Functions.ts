function lengthOfLastWord(s: string): number {
    s = s.trim(); // trim the trailing spaces in the string
    return s.length - s.lastIndexOf(" ") - 1;
}
