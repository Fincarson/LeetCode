int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int threeSumClosest(int* nums, int numsSize, int target) {
    int diff = INT_MAX, sz = numsSize;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < sz && diff != 0; ++i) {
        for (int j = i + 1; j < sz - 1; ++j) {
            int complement = target - nums[i] - nums[j];
            int lo = j + 1, hi = sz;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (nums[mid] <= complement)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            int hi_idx = lo, lo_idx = lo - 1;
            if (hi_idx < sz && abs(complement - nums[hi_idx]) < abs(diff))
                diff = complement - nums[hi_idx];
            if (lo_idx > j && abs(complement - nums[lo_idx]) < abs(diff))
                diff = complement - nums[lo_idx];
        }
    }
    return target - diff;
}
