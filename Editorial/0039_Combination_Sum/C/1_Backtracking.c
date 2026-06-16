void backtrack(int remain, int *comb, int combSize, int start, int *candidates,
               int candidatesSize, int ***results, int *returnSize,
               int **returnColumnSizes) {
    if (remain == 0) {
        // Make a deep copy of the current combination to add to results
        int *newComb = (int *)malloc(combSize * sizeof(int));
        for (int i = 0; i < combSize; i++) {
            newComb[i] = comb[i];
        }
        (*returnColumnSizes)[*returnSize] = combSize;
        (*results)[*returnSize] = newComb;
        (*returnSize)++;
        return;
    } else if (remain < 0) {
        // Exceed the scope, stop exploration.
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        // Add the number into the combination
        comb[combSize] = candidates[i];
        backtrack(remain - candidates[i], comb, combSize + 1, i, candidates,
                  candidatesSize, results, returnSize, returnColumnSizes);
    }
}

int **combinationSum(int *candidates, int candidatesSize, int target,
                     int *returnSize, int **returnColumnSizes) {
    int maxResults = 1000;  // Maximum number of combinations
    int **results = (int **)malloc(maxResults * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxResults * sizeof(int));
    *returnSize = 0;

    int *comb = (int *)malloc(
        target * sizeof(int));  // Large enough to hold any combination

    backtrack(target, comb, 0, 0, candidates, candidatesSize, &results,
              returnSize, returnColumnSizes);

    free(comb);
    return results;
}
