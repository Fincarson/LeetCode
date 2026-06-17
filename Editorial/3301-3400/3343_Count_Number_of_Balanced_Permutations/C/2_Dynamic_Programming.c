#define MOD 1000000007

int countBalancedPermutations(char* num) {
    int tot = 0, n = strlen(num);
    int cnt[10] = {0};
    for (int i = 0; i < n; i++) {
        int d = num[i] - '0';
        cnt[d]++;
        tot += d;
    }
    if (tot % 2 != 0) {
        return 0;
    }

    int target = tot / 2;
    int maxOdd = (n + 1) / 2;
    long long comb[maxOdd + 1][maxOdd + 1];
    long long f[target + 1][maxOdd + 1];
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= maxOdd; i++) {
        comb[i][i] = comb[i][0] = 1;
        for (int j = 1; j < i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }

    f[0][0] = 1;
    int psum = 0, totSum = 0;
    for (int i = 0; i <= 9; i++) {
        /* Sum of the number of the first i digits */
        psum += cnt[i];
        /* Sum of the first i numbers */
        totSum += i * cnt[i];
        for (int oddCnt = fmin(psum, maxOdd);
             oddCnt >= fmax(0, psum - (n - maxOdd)); oddCnt--) {
            /* The number of bits that need to be filled in even numbered
             * positions */
            int evenCnt = psum - oddCnt;
            for (int curr = fmin(totSum, target);
                 curr >= fmax(0, totSum - target); curr--) {
                long long res = 0;
                for (int j = fmax(0, cnt[i] - evenCnt);
                     j <= fmin(cnt[i], oddCnt) && i * j <= curr; j++) {
                    /* The current digit is filled with j positions at odd
                     * positions, and cnt[i] - j positions at even positions */
                    long long ways =
                        comb[oddCnt][j] * comb[evenCnt][cnt[i] - j] % MOD;
                    res =
                        (res + ways * f[curr - i * j][oddCnt - j] % MOD) % MOD;
                }
                f[curr][oddCnt] = res % MOD;
            }
        }
    }

    return f[target][maxOdd];
}
