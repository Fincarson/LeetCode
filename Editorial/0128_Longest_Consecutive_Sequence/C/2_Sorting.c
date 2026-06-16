int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int longestConsecutive(int *nums, int numsSize) {
    if (numsSize == 0) return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int longestStreak = 1;
    int currentStreak = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            if (nums[i] == nums[i - 1] + 1) {
                currentStreak += 1;
            } else {
                longestStreak = longestStreak > currentStreak ? longestStreak
                                                              : currentStreak;
                currentStreak = 1;
            }
        }
    }
    return longestStreak > currentStreak ? longestStreak : currentStreak;
}
