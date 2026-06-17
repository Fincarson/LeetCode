int strStr(char* haystack, char* needle) {
    int m = strlen(needle);
    int n = strlen(haystack);

    for (int windowStart = 0; windowStart <= n - m; windowStart++) {
        for (int i = 0; i < m; i++) {
            if (needle[i] != haystack[windowStart + i]) {
                break;
            }
            if (i == m - 1) {
                return windowStart;
            }
        }
    }

    return -1;
}
