int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int threeSumClosest(int* nums, int numsSize, int target) {
    int diff = INT_MAX;
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize && diff != 0; ++i) {
        int lo = i + 1;
        int hi = numsSize - 1;
        while (lo < hi) {
            int sum = nums[i] + nums[lo] + nums[hi];
            if (abs(target - sum) < abs(diff)) {
                diff = target - sum;
            }
            if (sum < target) {
                ++lo;
            } else {
                --hi;
            }
        }
    }
    return target - diff;
}
