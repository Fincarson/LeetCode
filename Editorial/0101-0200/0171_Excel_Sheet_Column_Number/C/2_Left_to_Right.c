int titleToNumber(char* s) {
    int result = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        result = result * 26;
        // In C, subtracting characters is subtracting ASCII values of
        // characters
        result += (s[i] - 'A' + 1);
    }
    return result;
}
