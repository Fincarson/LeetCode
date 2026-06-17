#define MOD 1000000007

int xorAfterQueries(int* nums, int numsSize, int** queries, int queriesSize,
                    int* queriesColSize) {
    for (int idx = 0; idx < queriesSize; idx++) {
        int l = queries[idx][0];
        int r = queries[idx][1];
        int k = queries[idx][2];
        int v = queries[idx][3];

        for (int i = l; i <= r; i += k) {
            nums[i] = (int)((int64_t)nums[i] * v % MOD);
        }
    }

    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res ^= nums[i];
    }
    return res;
}
