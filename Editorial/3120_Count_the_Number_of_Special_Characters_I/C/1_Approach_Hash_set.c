int numberOfSpecialChars(char* word) {
    int seen[128] = {0};
    for (int i = 0; word[i]; i++) {
        seen[(unsigned char)word[i]] = 1;
    }
    int ans = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        if (seen[(int)c] && seen[(int)(c - 'a' + 'A')]) {
            ans++;
        }
    }
    return ans;
}
