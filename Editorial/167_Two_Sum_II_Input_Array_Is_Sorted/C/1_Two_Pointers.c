int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int low = 0;
    int high = numbersSize - 1;
    *returnSize = 2;
    while (low < high) {
        int sum = numbers[low] + numbers[high];

        if (sum == target) {
            int* result = malloc((*returnSize) * sizeof(int));
            result[0] = low + 1;
            result[1] = high + 1;
            return result;
        } else if (sum < target) {
            low++;
        } else {
            high--;
        }
    }
    // In case there is no solution, return [-1, -1].
    int* result = malloc((*returnSize) * sizeof(int));
    result[0] = -1;
    result[1] = -1;
    return result;
}
