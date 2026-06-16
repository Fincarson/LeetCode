int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int maxDistinctElements(int* nums, int numsSize, int k) {
    qsort(nums, numsSize, sizeof(int), compare);
    int cnt = 0;
    int prev = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int curr = fmin(fmax(num - k, prev + 1), num + k);
        if (curr > prev) {
            cnt++;
            prev = curr;
        }
    }
    return cnt;
}
