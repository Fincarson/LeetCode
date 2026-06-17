char* findLexSmallestString(char* s, int a, int b) {
    int n = strlen(s);
    int vis[n];
    memset(vis, 0, sizeof(vis));
    char* res = (char*)calloc(sizeof(char), n + 1);
    strcpy(res, s);
    // double the length of s for convenience in extracting the rotated string t
    char str[2 * n + 1];
    sprintf(str, "%s%s", s, s);
    for (int i = 0; vis[i] == 0; i = (i + b) % n) {
        vis[i] = 1;
        for (int j = 0; j < 10; j++) {
            int k_limit = b % 2 == 0 ? 0 : 9;
            for (int k = 0; k <= k_limit; k++) {
                // before each accumulation, re-truncate t
                char t[n + 1];
                strncpy(t, str + i, n);
                t[n] = '\0';
                for (int p = 1; p < n; p += 2) {
                    t[p] = '0' + (t[p] - '0' + j * a) % 10;
                }
                for (int p = 0; p < n; p += 2) {
                    t[p] = '0' + (t[p] - '0' + k * a) % 10;
                }
                if (strcmp(t, res) < 0) {
                    strcpy(res, t);
                }
            }
        }
    }
    return res;
}
