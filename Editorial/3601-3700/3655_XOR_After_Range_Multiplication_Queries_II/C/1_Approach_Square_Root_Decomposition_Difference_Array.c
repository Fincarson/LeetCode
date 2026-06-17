#define MOD 1000000007

int pow_mod(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y & 1) {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        y >>= 1;
    }
    return (int)res;
}

int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize,
                    int* queriesColSize) {
    int n = numsSize;
    int T = (int)sqrt(n);
    int*** groups = (int***)malloc(T * sizeof(int**));
    int* groupCounts = (int*)calloc(T, sizeof(int));
    int* groupCapacities = (int*)calloc(T, sizeof(int));

    for (int i = 0; i < T; i++) {
        groupCapacities[i] = 10;
        groups[i] = (int**)malloc(groupCapacities[i] * sizeof(int*));
    }

    for (int idx = 0; idx < queriesSize; idx++) {
        int l = queries[idx][0], r = queries[idx][1];
        int k = queries[idx][2], v = queries[idx][3];

        if (k < T) {
            if (groupCounts[k] >= groupCapacities[k]) {
                groupCapacities[k] *= 2;
                groups[k] = (int**)realloc(groups[k],
                                           groupCapacities[k] * sizeof(int*));
            }
            int* q = (int*)malloc(3 * sizeof(int));
            q[0] = l;
            q[1] = r;
            q[2] = v;
            groups[k][groupCounts[k]++] = q;
        } else {
            for (int i = l; i <= r; i += k) {
                nums[i] = (int)((long long)nums[i] * v % MOD);
            }
        }
    }

    long long* dif = (long long*)calloc(n + T, sizeof(long long));
    for (int k = 1; k < T; k++) {
        if (groupCounts[k] == 0) {
            continue;
        }
        for (int i = 0; i < n + T; i++) {
            dif[i] = 1;
        }
        for (int g = 0; g < groupCounts[k]; g++) {
            int l = groups[k][g][0];
            int r = groups[k][g][1];
            int v = groups[k][g][2];

            dif[l] = dif[l] * v % MOD;
            int R = ((r - l) / k + 1) * k + l;
            dif[R] = dif[R] * pow_mod(v, MOD - 2) % MOD;
        }

        for (int i = k; i < n; i++) {
            dif[i] = dif[i] * dif[i - k] % MOD;
        }
        for (int i = 0; i < n; i++) {
            nums[i] = (int)((long long)nums[i] * dif[i] % MOD);
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        res ^= nums[i];
    }

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < groupCounts[i]; j++) {
            free(groups[i][j]);
        }
        free(groups[i]);
    }
    free(groups);
    free(groupCounts);
    free(groupCapacities);
    free(dif);

    return res;
}
