typedef struct {
    int index;
    int value;
} Pair;

int compareValueDesc(const void* a, const void* b) {
    return ((Pair*)b)->value - ((Pair*)a)->value;
}

int compareIndexAsc(const void* a, const void* b) {
    return ((Pair*)a)->index - ((Pair*)b)->index;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize) {
    Pair* vals = (Pair*)malloc(numsSize * sizeof(Pair));  // auxiliary array
    for (int i = 0; i < numsSize; ++i) {
        vals[i].index = i;
        vals[i].value = nums[i];
    }
    // sort by numerical value in descending order
    qsort(vals, numsSize, sizeof(Pair), compareValueDesc);
    // select the first k elements and sort them in ascending order by index
    qsort(vals, k, sizeof(Pair), compareIndexAsc);
    int* res = (int*)malloc(k * sizeof(int));  // target subsequence
    for (int i = 0; i < k; ++i) {
        res[i] = vals[i].value;
    }
    *returnSize = k;
    free(vals);
    return res;
}
