int getDistance(int p, int q) {
    int x1 = p / 6, y1 = p % 6;
    int x2 = q / 6, y2 = q % 6;
    return abs(x1 - x2) + abs(y1 - y2);
}

int minimumDistance(char* word) {
    int n = strlen(word);
    int*** dp = (int***)malloc(n * sizeof(int**));
    for (int i = 0; i < n; ++i) {
        dp[i] = (int**)malloc(26 * sizeof(int*));
        for (int j = 0; j < 26; ++j) {
            dp[i][j] = (int*)malloc(26 * sizeof(int));
            for (int k = 0; k < 26; ++k) {
                dp[i][j][k] = INT_MAX / 2;
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        dp[0][i][word[0] - 'A'] = 0;
        dp[0][word[0] - 'A'][i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int cur = word[i] - 'A';
        int prev = word[i - 1] - 'A';
        int d = getDistance(prev, cur);

        for (int j = 0; j < 26; ++j) {
            dp[i][cur][j] = fmin(dp[i][cur][j], dp[i - 1][prev][j] + d);
            dp[i][j][cur] = fmin(dp[i][j][cur], dp[i - 1][j][prev] + d);

            if (prev == j) {
                for (int k = 0; k < 26; ++k) {
                    int d0 = getDistance(k, cur);
                    dp[i][cur][j] = fmin(dp[i][cur][j], dp[i - 1][k][j] + d0);
                    dp[i][j][cur] = fmin(dp[i][j][cur], dp[i - 1][j][k] + d0);
                }
            }
        }
    }

    int ans = INT_MAX / 2;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (ans > dp[n - 1][i][j]) {
                ans = dp[n - 1][i][j];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            free(dp[i][j]);
        }
        free(dp[i]);
    }
    free(dp);

    return ans;
}
