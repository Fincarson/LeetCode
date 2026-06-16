int lengthOfLastWord(char* s) {
    int count = 0;
    int len = strlen(s) - 1;
    // Discard the trailing spaces
    while (len >= 0 && s[len] == ' ') len--;
    // Iterate through the last word
    while (len >= 0 && s[len] != ' ') {
        count++;
        len--;
    }
    return count;
}
