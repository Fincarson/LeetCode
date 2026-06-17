int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

bool isGood(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int n = numsSize - 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            return false;
        }
    }
    return nums[n] == n;
}
