int cmp(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

long long maximumTotalDamage(int* power, int powerSize) {
    int* keys = (int*)malloc(sizeof(int) * powerSize);
    int* vals = (int*)malloc(sizeof(int) * powerSize);
    int m = 0;

    qsort(power, powerSize, sizeof(int), cmp);

    for (int i = 0; i < powerSize; i++) {
        if (m == 0 || power[i] != keys[m - 1]) {
            keys[m] = power[i];
            vals[m] = 1;
            m++;
        } else {
            vals[m - 1]++;
        }
    }

    int* vk = (int*)malloc(sizeof(int) * (m + 1));
    int* vv = (int*)malloc(sizeof(int) * (m + 1));
    vk[0] = -1000000000;
    vv[0] = 0;
    for (int i = 0; i < m; i++) {
        vk[i + 1] = keys[i];
        vv[i + 1] = vals[i];
    }
    int n = m + 1;

    long long* f = (long long*)calloc(n, sizeof(long long));
    long long mx = 0, ans = 0;
    int j = 1;
    for (int i = 1; i < n; i++) {
        while (j < i && vk[j] < vk[i] - 2) {
            if (f[j] > mx) {
                mx = f[j];
            }
            j++;
        }
        f[i] = mx + 1LL * vk[i] * vv[i];
        if (f[i] > ans) {
            ans = f[i];
        }
    }

    free(keys);
    free(vals);
    free(vk);
    free(vv);
    free(f);
    return ans;
}
