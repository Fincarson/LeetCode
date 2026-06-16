struct Range {
    int start, end;
};

struct Range** findMissingRanges(int* nums, int numsSize, int lower, int upper,
                                 int* returnSize, int** returnColumnSizes) {
    int n = numsSize;

    struct Range** missingRanges = malloc((n + 2) * sizeof(struct Range*));
    *returnColumnSizes = malloc((n + 2) * sizeof(int));
    *returnSize = 0;

    if (n == 0) {
        missingRanges[*returnSize] = malloc(2 * sizeof(int));
        missingRanges[*returnSize]->start = lower;
        missingRanges[*returnSize]->end = upper;
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
        return missingRanges;
    }

    if (lower < nums[0]) {
        missingRanges[*returnSize] = malloc(2 * sizeof(int));
        missingRanges[*returnSize]->start = lower;
        missingRanges[*returnSize]->end = nums[0] - 1;
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    for (int i = 0; i < n - 1; i++) {
        if (nums[i + 1] - nums[i] <= 1) {
            continue;
        }
        missingRanges[*returnSize] = malloc(2 * sizeof(int));
        missingRanges[*returnSize]->start = nums[i] + 1;
        missingRanges[*returnSize]->end = nums[i + 1] - 1;
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    if (upper > nums[n - 1]) {
        missingRanges[*returnSize] = malloc(2 * sizeof(int));
        missingRanges[*returnSize]->start = nums[n - 1] + 1;
        missingRanges[*returnSize]->end = upper;
        (*returnColumnSizes)[*returnSize] = 2;
        (*returnSize)++;
    }

    return missingRanges;
}
