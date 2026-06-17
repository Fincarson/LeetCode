int maxOperations(char* s) {
    int countOne = 0;
    int ans = 0;
    int i = 0;
    int len = strlen(s);

    while (i < len) {
        if (s[i] == '0') {
            while (i + 1 < len && s[i + 1] == '0') {
                i++;
            }
            ans += countOne;
        } else {
            countOne++;
        }
        i++;
    }
    return ans;
}
