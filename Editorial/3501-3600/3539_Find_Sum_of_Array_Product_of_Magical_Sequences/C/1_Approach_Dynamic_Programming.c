long long quickmul(long long x, long long y, long long mod) {
    long long res = 1, cur = x % mod;
    while (y) {
        if (y & 1) {
            res = res * cur % mod;
        }
        y >>= 1;
        cur = cur * cur % mod;
    }
    return res;
}

int magicalSum(int m, int k, int* nums, int numsSize) {
    const long long mod = 1000000007;
    long long* fac = (long long*)malloc((m + 1) * sizeof(long long));
    long long* ifac = (long long*)malloc((m + 1) * sizeof(long long));
    fac[0] = 1;
    for (int i = 1; i <= m; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    ifac[0] = 1;
    ifac[1] = 1;
    for (int i = 2; i <= m; i++) {
        ifac[i] = quickmul(i, mod - 2, mod);
    }
    for (int i = 2; i <= m; i++) {
        ifac[i] = ifac[i - 1] * ifac[i] % mod;
    }

    long long** numsPower = (long long**)malloc(numsSize * sizeof(long long*));
    for (int i = 0; i < numsSize; i++) {
        numsPower[i] = (long long*)malloc((m + 1) * sizeof(long long));
        numsPower[i][0] = 1;
        for (int j = 1; j <= m; j++) {
            numsPower[i][j] = numsPower[i][j - 1] * nums[i] % mod;
        }
    }

    long long**** f = (long long****)malloc(numsSize * sizeof(long long***));
    for (int i = 0; i < numsSize; i++) {
        f[i] = (long long***)malloc((m + 1) * sizeof(long long**));
        for (int j = 0; j <= m; j++) {
            f[i][j] = (long long**)malloc((m * 2 + 1) * sizeof(long long*));
            for (int p = 0; p <= m * 2; p++) {
                f[i][j][p] = (long long*)calloc((k + 1), sizeof(long long));
            }
        }
    }

    for (int j = 0; j <= m; j++) {
        f[0][j][j][0] = numsPower[0][j] * ifac[j] % mod;
    }
    for (int i = 0; i + 1 < numsSize; i++) {
        for (int j = 0; j <= m; j++) {
            for (int p = 0; p <= m * 2; p++) {
                for (int q = 0; q <= k; q++) {
                    int q2 = p % 2 + q;
                    if (q2 > k) {
                        break;
                    }
                    for (int r = 0; r + j <= m; r++) {
                        int p2 = p / 2 + r;
                        f[i + 1][j + r][p2][q2] += f[i][j][p][q] *
                                                   numsPower[i + 1][r] % mod *
                                                   ifac[r] % mod;
                        f[i + 1][j + r][p2][q2] %= mod;
                    }
                }
            }
        }
    }

    long long res = 0;
    for (int p = 0; p <= m * 2; p++) {
        for (int q = 0; q <= k; q++) {
            int bitcount = __builtin_popcount(p);
            if (bitcount + q == k) {
                res = (res + f[numsSize - 1][m][p][q] * fac[m] % mod) % mod;
            }
        }
    }
    return (int)res;
}
