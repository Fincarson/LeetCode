int valid(char *s, int start, int length) {
    if (length == 1) return 1;
    if (s[start] == '0') return 0;
    if (length > 2) {
        char substr[4];
        strncpy(substr, s + start, length);
        substr[length] = '\0';
        if (atoi(substr) > 255) return 0;
    }
    return 1;
}
char **restoreIpAddresses(char *s, int *returnSize) {
    char **ans = malloc(0);
    *returnSize = 0;
    int length = strlen(s);
    for (int len1 = length - 9 > 1 ? length - 9 : 1;
         len1 <= 3 && len1 <= length - 3; ++len1) {
        if (!valid(s, 0, len1)) continue;
        for (int len2 = length - len1 - 6 > 1 ? length - len1 - 6 : 1;
             len2 <= 3 && len2 <= length - len1 - 2; ++len2) {
            if (!valid(s, len1, len2)) continue;
            for (int len3 = length - len1 - len2 - 3 > 1
                                ? length - len1 - len2 - 3
                                : 1;
                 len3 <= 3 && len3 <= length - len1 - len2 - 1; ++len3) {
                if (valid(s, len1 + len2, len3) &&
                    valid(s, len1 + len2 + len3, length - len1 - len2 - len3)) {
                    char *ip = malloc(16);
                    sprintf(ip, "%.*s.%.*s.%.*s.%.*s", len1, s, len2, s + len1,
                            len3, s + len1 + len2, length - len1 - len2 - len3,
                            s + len1 + len2 + len3);
                    ans = realloc(ans, (*returnSize + 1) * sizeof(char *));
                    ans[(*returnSize)++] = ip;
                }
            }
        }
    }
    return ans;
}
