int I(char ch, int x) { return (ch - '0') == x ? 1 : 0; }

int minFlips(char* s) {
    int n = strlen(s);
    int** pre = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        pre[i] = (int*)malloc(2 * sizeof(int));
    }
    // If n is an odd number, it is also necessary to calculate suf
    int** suf = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        suf[i] = (int*)malloc(2 * sizeof(int));
    }

    // Note the boundary case when i=0
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            pre[i][0] = I(s[i], 1);
            pre[i][1] = I(s[i], 0);
        } else {
            pre[i][0] = pre[i - 1][1] + I(s[i], 1);
            pre[i][1] = pre[i - 1][0] + I(s[i], 0);
        }
    }

    int ans = fmin(pre[n - 1][0], pre[n - 1][1]);
    if (n % 2 == 1) {
        // Note the boundary case when i = n - 1
        for (int i = n - 1; i >= 0; --i) {
            if (i == n - 1) {
                suf[i][0] = I(s[i], 1);
                suf[i][1] = I(s[i], 0);
            } else {
                suf[i][0] = suf[i + 1][1] + I(s[i], 1);
                suf[i][1] = suf[i + 1][0] + I(s[i], 0);
            }
        }
        for (int i = 0; i + 1 < n; ++i) {
            ans = fmin(ans, pre[i][0] + suf[i + 1][0]);
            ans = fmin(ans, pre[i][1] + suf[i + 1][1]);
        }
    }

    // Release suf memory, release pre memory
    for (int i = 0; i < n; i++) {
        free(suf[i]);
        free(pre[i]);
    }
    free(suf);
    free(pre);

    return ans;
}
