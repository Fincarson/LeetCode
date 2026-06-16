typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} HashMapItem;
int compare(const void* a, const void* b) { return *(int*)a - *(int*)b; }
int** threeSum(int* nums, int numsSize, int* returnSize,
               int** returnColumnSizes) {
    HashMapItem* map = NULL;
    qsort(nums, numsSize, sizeof(int), compare);
    int** result = (int**)malloc(numsSize * numsSize * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(numsSize * numsSize * sizeof(int));
    for (int i = 0; i < numsSize - 2; ++i) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int start = i + 1, end = numsSize - 1;
        HashMapItem* s;
        while (start < end) {
            int sum = nums[i] + nums[start] + nums[end];
            if (sum < 0) {
                ++start;
            } else if (sum > 0) {
                --end;
            } else {
                int* triplet = (int*)malloc(3 * sizeof(int));
                triplet[0] = nums[i];
                triplet[1] = nums[start];
                triplet[2] = nums[end];
                result[*returnSize] = triplet;
                (*returnColumnSizes)[*returnSize] = 3;
                ++(*returnSize);
                while (start < end && nums[start] == nums[start + 1]) ++start;
                while (start < end && nums[end] == nums[end - 1]) --end;
                ++start;
                --end;
            }
        }
    }
    return result;
}
