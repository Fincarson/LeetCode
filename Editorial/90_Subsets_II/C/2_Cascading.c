int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
int **subsetsWithDup(int *nums, int numsSize, int *returnSize,
                     int **returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    int capacity = 5000;
    int **subsets = malloc(capacity * sizeof(int *));
    int *firstSubset = malloc(0);
    subsets[0] = firstSubset;
    *returnColumnSizes = malloc(capacity * sizeof(int));
    (*returnColumnSizes)[0] = 0;
    *returnSize = 1;
    int subsetSize = 0;
    for (int i = 0; i < numsSize; i++) {
        int startingIndex = (i >= 1 && nums[i] == nums[i - 1]) ? subsetSize : 0;
        // subsetSize refers to the size of the subset in the previous step.
        // This value also indicates the starting index of the subsets generated
        // in this step.
        subsetSize = *returnSize;
        for (int j = startingIndex; j < subsetSize; j++) {
            int *currentSubset =
                malloc(((*returnColumnSizes)[j] + 1) * sizeof(int));
            memcpy(currentSubset, subsets[j],
                   (*returnColumnSizes)[j] * sizeof(int));
            currentSubset[(*returnColumnSizes)[j]] = nums[i];
            if (*returnSize >= capacity) {
                capacity *= 2;
                subsets = realloc(subsets, capacity * sizeof(int *));
                *returnColumnSizes =
                    realloc(*returnColumnSizes, capacity * sizeof(int));
            }
            subsets[*returnSize] = currentSubset;
            (*returnColumnSizes)[*returnSize] = (*returnColumnSizes)[j] + 1;
            (*returnSize)++;
        }
    }
    return subsets;
}
