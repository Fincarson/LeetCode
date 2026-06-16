int titleToNumber(char* s) {
    int i, result = 0, n = strlen(s);

    for (i = 0; i < n; i++) {
        result *= 26;
        result += (s[i] - 64);  // Decimal 65 in ASCII corresponds to char 'A',
                                // but we need it to be '1' for A.
    }

    return result;
}
