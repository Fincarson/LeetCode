// Structure for hash table to store previously seen sets
struct seen_set {
    char *hashcode;
    UT_hash_handle hh;
};
// The qsort comparator function
int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }
void generate_hashcode(char *hashcode, int *currentSubset,
                       int currentSubsetSize) {
    for (int i = 0; i < currentSubsetSize; i++) {
        char buffer[50];
        sprintf(buffer, "%d,", currentSubset[i]);
        strcat(hashcode, buffer);
    }
}
int **subsetsWithDup(int *nums, int numsSize, int *returnSize,
                     int **returnColumnSizes) {
    // Sort the input array
    qsort(nums, numsSize, sizeof(int), compare);
    struct seen_set *seen = NULL;
    int **subsets = (int **)malloc(sizeof(int *) * pow(2, numsSize));
    int maxNumberOfSubsets = pow(2, numsSize);
    *returnSize = 0;
    int *currentSubsetSizes = (int *)malloc(sizeof(int) * pow(2, numsSize));
    for (int subsetIndex = 0; subsetIndex < maxNumberOfSubsets; subsetIndex++) {
        int *currentSubset = (int *)calloc(numsSize, sizeof(int));
        int currentSubsetSize = 0;
        char *hashcode = (char *)calloc(numsSize * 50, sizeof(char));
        for (int j = 0; j < numsSize; j++) {
            int isSet = (1 << j) & subsetIndex;
            if (isSet != 0) {
                currentSubset[currentSubsetSize++] = nums[j];
            }
        }
        generate_hashcode(hashcode, currentSubset, currentSubsetSize);
        // Search if the hashcode exists in the hash table
        struct seen_set *s;
        HASH_FIND_STR(seen, hashcode, s);
        if (s == NULL) {
            // If not found, add this subset in the result and also in the hash
            // map
            subsets[*returnSize] = currentSubset;
            currentSubsetSizes[*returnSize] = currentSubsetSize;
            struct seen_set *newSet =
                (struct seen_set *)malloc(sizeof(struct seen_set));
            newSet->hashcode = hashcode;
            HASH_ADD_KEYPTR(hh, seen, newSet->hashcode,
                            strlen(newSet->hashcode), newSet);
            (*returnSize)++;
        } else {
            // If the subset is found in hash map, we've seen this set before,
            // free the memory
            free(currentSubset);
            free(hashcode);
        }
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = currentSubsetSizes[i];
    }
    free(currentSubsetSizes);
    return subsets;
}
