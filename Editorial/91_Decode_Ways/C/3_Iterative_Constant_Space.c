int numDecodings(char* s) {
    if (s[0] == '0') {
        return 0;
    }
    int n = strlen(s);
    int twoBack = 1;
    int oneBack = 1;
    for (int i = 1; i < n; i++) {
        int current = 0;
        if (s[i] != '0') {
            current = oneBack;
        }
        char twoDigitChar[3] = {s[i - 1], s[i], '\0'};
        int twoDigit = atoi(twoDigitChar);
        if (twoDigit >= 10 && twoDigit <= 26) {
            current += twoBack;
        }
        twoBack = oneBack;
        oneBack = current;
    }
    return oneBack;
}
