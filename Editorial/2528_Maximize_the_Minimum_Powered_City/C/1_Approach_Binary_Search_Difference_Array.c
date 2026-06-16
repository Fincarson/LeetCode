bool check(long long* cnt, int r, long long k, long long val, int n) {
    long long* diff = (long long*)malloc((n + 1) * sizeof(long long));
    memcpy(diff, cnt, (n + 1) * sizeof(long long));

    long long sum = 0;
    long long remaining = k;

    for (int i = 0; i < n; i++) {
        sum += diff[i];
        if (sum < val) {
            long long add = val - sum;
            if (remaining < add) {
                free(diff);
                return false;
            }
            remaining -= add;
            int end = fmin(n, i + 2 * r + 1);
            diff[end] -= add;
            sum += add;
        }
    }
    free(diff);
    return true;
}

long long maxPower(int* stations, int stationsSize, int r, int k) {
    int n = stationsSize;
    long long* cnt = (long long*)calloc(n + 1, sizeof(long long));

    for (int i = 0; i < n; i++) {
        int left = fmax(0, i - r);
        int right = fmin(n, i + r + 1);
        cnt[left] += stations[i];
        cnt[right] -= stations[i];
    }

    long long minStation = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (stations[i] < minStation) {
            minStation = stations[i];
        }
    }

    long long minVal = LLONG_MAX;
    long long sumTotal = 0;
    for (int i = 0; i < n; i++) {
        if (stations[i] < minVal) {
            minVal = stations[i];
        }
        sumTotal += stations[i];
    }
    long long hi = sumTotal + k;
    long long lo = minVal;
    long long res = 0;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        if (check(cnt, r, k, mid, n)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    free(cnt);
    return res;
}
