int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
void twoSum(int* nums, int numsSize, int i, int** res, int* returnSize,
            int* returnColumnSizes) {
    int lo = i + 1, hi = numsSize - 1;
    while (lo < hi) {
        int sum = nums[i] + nums[lo] + nums[hi];
        if (sum < 0) {
            ++lo;
        } else if (sum > 0) {
            --hi;
        } else {
            res[*returnSize] = (int*)malloc(sizeof(int) * 3);
            res[*returnSize][0] = nums[i];
            res[*returnSize][1] = nums[lo++];
            res[*returnSize][2] = nums[hi--];
            returnColumnSizes[*returnSize] = 3;
            (*returnSize)++;
            while (lo < hi && nums[lo] == nums[lo - 1]) {
                ++lo;
            }
        }
    }
}
int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * (numsSize * numsSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize * numsSize));
    for (int i = 0; i < numsSize && nums[i] <= 0; i++) {
        if (i == 0 || nums[i - 1] != nums[i]) {
            twoSum(nums, numsSize, i, res, returnSize, *returnColumnSizes);
        }
    }
    return res;
}
