bool checkRepetition(char* s, int start, int end) {
    bool chars[128] = {0};
    for (int i = start; i <= end; i++) {
        char c = s[i];
        if (chars[c]) {
            return false;
        }
        chars[c] = true;
    }
    return true;
}

int max(int a, int b) { return (a > b) ? a : b; }

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (checkRepetition(s, i, j)) {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}
