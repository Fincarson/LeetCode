int getDistance(int p, int q) {
    int x1 = p / 6, y1 = p % 6;
    int x2 = q / 6, y2 = q % 6;
    return abs(x1 - x2) + abs(y1 - y2);
}

int minimumDistance(char* word) {
    int n = strlen(word);
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dp[i] = (int*)malloc(26 * sizeof(int));
        for (int j = 0; j < 26; j++) {
            dp[i][j] = INT_MAX / 2;
        }
    }
    for (int j = 0; j < 26; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i < n; i++) {
        int cur = word[i] - 'A';
        int prev = word[i - 1] - 'A';
        int d = getDistance(prev, cur);

        for (int j = 0; j < 26; j++) {
            dp[i][j] = fmin(dp[i][j], dp[i - 1][j] + d);
            if (prev == j) {
                for (int k = 0; k < 26; k++) {
                    int d0 = getDistance(k, cur);
                    dp[i][j] = fmin(dp[i][j], dp[i - 1][k] + d0);
                }
            }
        }
    }

    int ans = INT_MAX / 2;
    for (int j = 0; j < 26; j++) {
        if (ans > dp[n - 1][j]) {
            ans = dp[n - 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        free(dp[i]);
    }
    free(dp);

    return ans;
}
