int isValid(int* nums, int n, int nonZeros, int start, int direction) {
    int temp[1000];
    memcpy(temp, nums, n * sizeof(int));
    int curr = start;
    while (nonZeros > 0 && curr >= 0 && curr < n) {
        if (temp[curr] > 0) {
            temp[curr]--;
            direction *= -1;
            if (temp[curr] == 0) nonZeros--;
        }
        curr += direction;
    }
    return nonZeros == 0;
}

int countValidSelections(int* nums, int n) {
    int count = 0, nonZeros = 0;
    for (int i = 0; i < n; i++)
        if (nums[i] > 0) nonZeros++;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            if (isValid(nums, n, nonZeros, i, -1)) count++;
            if (isValid(nums, n, nonZeros, i, 1)) count++;
        }
    }
    return count;
}
