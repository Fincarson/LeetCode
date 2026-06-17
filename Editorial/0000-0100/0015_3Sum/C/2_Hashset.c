#include <stdio.h>
#include <stdlib.h>

// To sort array
void sort(int *nums, int numsSize) {
    int i, key, j;
    for (i = 1; i < numsSize; i++) {
        key = nums[i];
        j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j = j - 1;
        }
        nums[j + 1] = key;
    }
}

// This function adds a record to the result set for each unique triple
int **threeSum(int *nums, int size, int *returnSize, int **returnColumnSizes) {
    sort(nums, size);
    int **results = (int **)malloc(size * size * sizeof(int *));
    *returnSize = 0;
    for (int i = 0; i < size - 2; ++i) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1;
        int k = size - 1;
        while (j < k) {
            if (j != i + 1 && nums[j] == nums[j - 1]) {
                ++j;
                continue;
            }
            if (nums[i] + nums[j] + nums[k] > 0)
                --k;
            else if (nums[i] + nums[j] + nums[k] < 0)
                ++j;
            else {
                int *triplet = (int *)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[j];
                triplet[2] = nums[k];
                results[*returnSize] = triplet;
                ++*returnSize;
                ++j;
            }
        }
    }
    *returnColumnSizes = (int *)malloc(*returnSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) (*returnColumnSizes)[i] = 3;
    return results;
}
