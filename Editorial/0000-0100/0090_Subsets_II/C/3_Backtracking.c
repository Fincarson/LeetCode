typedef struct {
    int* nums;
    int count;
} Vector;
void vector_init(Vector* vector) {
    vector->nums = NULL;
    vector->count = 0;
}
void vector_append(Vector* vector, int num) {
    vector->nums = realloc(vector->nums, sizeof(int) * (vector->count + 1));
    vector->nums[vector->count] = num;
    vector->count++;
}
void vector_remove_last(Vector* vector) {
    vector->count--;
    vector->nums = realloc(vector->nums, sizeof(int) * vector->count);
}
typedef struct {
    Vector* vectors;
    int count;
} Vectors;
void vectors_init(Vectors* vectors) {
    vectors->vectors = NULL;
    vectors->count = 0;
}
void vectors_append(Vectors* vectors, Vector* vector) {
    vectors->vectors =
        realloc(vectors->vectors, sizeof(Vector) * (vectors->count + 1));
    vectors->vectors[vectors->count] = *vector;
    vectors->vectors[vectors->count].nums =
        (vector->count > 0) ? malloc(vector->count * sizeof(int)) : NULL;
    if (vector->count > 0) {
        memcpy(vectors->vectors[vectors->count].nums, vector->nums,
               vector->count * sizeof(int));
    }
    vectors->count++;
}
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
void subsetsWithDupHelper(Vectors* subsets, Vector* currentSubset, int* nums,
                          int numsSize, int index) {
    vectors_append(subsets, currentSubset);
    for (int i = index; i < numsSize; i++) {
        if (i != index && nums[i] == nums[i - 1]) {
            continue;
        }
        vector_append(currentSubset, nums[i]);
        subsetsWithDupHelper(subsets, currentSubset, nums, numsSize, i + 1);
        vector_remove_last(currentSubset);
    }
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize,
                     int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);
    Vectors subsets;
    vectors_init(&subsets);
    Vector currentSubset;
    vector_init(&currentSubset);
    subsetsWithDupHelper(&subsets, &currentSubset, nums, numsSize, 0);
    free(currentSubset.nums);
    *returnSize = subsets.count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * subsets.count);
    int** result = (int**)malloc(sizeof(int*) * subsets.count);
    for (int i = 0; i < subsets.count; i++) {
        (*returnColumnSizes)[i] = subsets.vectors[i].count;
        result[i] = (subsets.vectors[i].count > 0)
                        ? (int*)malloc(sizeof(int) * subsets.vectors[i].count)
                        : NULL;
        for (int j = 0; j < subsets.vectors[i].count; j++) {
            result[i][j] = subsets.vectors[i].nums[j];
        }
        free(subsets.vectors[i].nums);
    }
    free(subsets.vectors);
    return result;
}
