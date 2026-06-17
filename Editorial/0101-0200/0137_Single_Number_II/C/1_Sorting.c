int cmp(const void* a, const void* b) {
    if (*(int*)a > *(int*)b) return 1;
    if (*(int*)a < *(int*)b) return -1;
    return 0;
}
int singleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i += 3) {
        if (nums[i] == nums[i + 1]) {
            continue;
        } else {
            return nums[i];
        }
    }
    return nums[numsSize - 1];
}
