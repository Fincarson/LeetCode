int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {
    int n = numsSize - 2;
    int y = 0;
    for (int i = 0; i < numsSize; i++) {
        y ^= nums[i];
    }
    for (int i = 0; i < n; i++) {
        y ^= i;
    }
    int lowBit = y & -y;
    int x1 = 0, x2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & lowBit) {
            x1 ^= nums[i];
        } else {
            x2 ^= nums[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (i & lowBit) {
            x1 ^= i;
        } else {
            x2 ^= i;
        }
    }
    int* res = (int*)malloc(2 * sizeof(int));
    res[0] = x1;
    res[1] = x2;
    *returnSize = 2;
    return res;
}
