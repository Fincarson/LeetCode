int findSmallestInteger(int* nums, int numsSize, int value) {
    int mp[value];
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < numsSize; i++) {
        int x = nums[i];
        int v = (x % value + value) % value;
        mp[v]++;
    }
    int mex = 0;
    while (mp[mex % value] > 0) {
        mp[mex % value]--;
        mex++;
    }
    return mex;
}
