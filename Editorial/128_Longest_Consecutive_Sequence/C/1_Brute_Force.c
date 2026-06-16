bool arrayContains(int* arr, int num, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}
int longestConsecutive(int* nums, int numsSize) {
    int longestStreak = 0;
    for (int i = 0; i < numsSize; i++) {
        int currentNum = nums[i];
        int currentStreak = 1;
        while (arrayContains(nums, currentNum + 1, numsSize)) {
            currentNum += 1;
            currentStreak += 1;
        }
        longestStreak =
            longestStreak > currentStreak ? longestStreak : currentStreak;
    }
    return longestStreak;
}
