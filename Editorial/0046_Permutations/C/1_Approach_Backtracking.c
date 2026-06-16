void backtrack(int* nums, int numsSize, int* cur, int curSize, int** ret,
               int* returnSize) {
    if (curSize == numsSize) {
        ret[*returnSize] = malloc(sizeof(int) * numsSize);
        memcpy(ret[*returnSize], cur, numsSize * sizeof(int));
        *returnSize += 1;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        bool exists = false;
        for (int j = 0; j < curSize; j++) {
            if (cur[j] == nums[i]) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            cur[curSize] = nums[i];
            backtrack(nums, numsSize, cur, curSize + 1, ret, returnSize);
        }
    }
}
int** permute(int* nums, int numsSize, int* returnSize,
              int** returnColumnSizes) {
    int** ret = (int**)malloc(sizeof(int*) * 10000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 10000);
    for (int i = 0; i < 10000; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    *returnSize = 0;
    int* cur = (int*)malloc(numsSize * sizeof(int));
    memset(cur, -1, numsSize * sizeof(int));
    backtrack(nums, numsSize, cur, 0, ret, returnSize);
    free(cur);
    return ret;
}
