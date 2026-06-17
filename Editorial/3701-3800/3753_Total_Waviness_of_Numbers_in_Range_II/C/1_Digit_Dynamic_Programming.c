typedef struct {
    long long cnt;
    long long sum;
} Result;

Result dfs(const char* s, int n, long long memo_cnt[20][10][10],
           long long memo_sum[20][10][10], int pos, int prev, int curr,
           int isLimit, int isLeading) {
    // end position
    if (pos == n) {
        return (Result){1, 0};
    }
    // use memoization only when not bounded by an upper limit and without
    // leading zeros
    if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
        if (memo_cnt[pos][prev][curr] != -1) {
            return (Result){memo_cnt[pos][prev][curr],
                            memo_sum[pos][prev][curr]};
        }
    }

    // calculate the number of schemes and fluctuation value under the current
    // conditions
    long long cnt = 0, sum = 0;
    int up = isLimit ? (s[pos] - '0') : 9;
    for (int digit = 0; digit <= up; ++digit) {
        int newLeading = isLeading && (digit == 0);
        // the previous number is updated to curr
        int newPrev = curr;
        // the current number is updated to digit
        int newCurr = newLeading ? -1 : digit;
        Result sub = dfs(s, n, memo_cnt, memo_sum, pos + 1, newPrev, newCurr,
                         isLimit && (digit == up), newLeading);
        // only calculate the fluctuation value when there are no leading zeros
        if (!newLeading && prev >= 0 && curr >= 0) {
            // when the digit is a peak or a valley, update the current
            // fluctuation value
            if ((prev < curr && curr > digit) ||
                (prev > curr && curr < digit)) {
                sum += sub.cnt;
            }
        }

        cnt += sub.cnt;
        sum += sub.sum;
    }

    if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
        // update the memoization array
        memo_cnt[pos][prev][curr] = cnt;
        memo_sum[pos][prev][curr] = sum;
    }

    return (Result){cnt, sum};
}

// calculate the sum of the volatility values of all numbers in [0, num]
long long solve(long long num) {
    // if the fluctuation value of numbers less than 3 is 0
    if (num < 100) {
        return 0;
    }

    char s[20];
    sprintf(s, "%lld", num);
    int n = strlen(s);

    // memoized search uses two independent arrays
    // memo_cnt[pos][x][y]: the number of valid filling schemes where the
    // current digit is at position pos, and the previous two digits are x and y
    long long memo_cnt[20][10][10];
    // memo_sum[pos][x][y]: the fluctuation value when the current position is
    // pos, and the two left digits are x and y
    long long memo_sum[20][10][10];
    // initialize the memoization array
    memset(memo_cnt, -1, sizeof(memo_cnt));
    memset(memo_sum, -1, sizeof(memo_sum));

    Result result = dfs(s, n, memo_cnt, memo_sum, 0, -1, -1, 1, 1);
    return result.sum;
}

long long totalWaviness(long long num1, long long num2) {
    return solve(num2) - solve(num1 - 1);
}
