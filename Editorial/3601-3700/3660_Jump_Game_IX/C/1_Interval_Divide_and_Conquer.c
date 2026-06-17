typedef struct {
    int value;
    int index;
} Item;

void process(int* nums, int* ans, Item* prevMax, int r, int rightMin,
             int rightMax) {
    int pMax = prevMax[r].value;
    int pivotIndex = prevMax[r].index;

    int currMax = (pMax <= rightMin) ? pMax : rightMax;

    int nextRightMin = (pMax < rightMin) ? pMax : rightMin;
    for (int i = pivotIndex; i <= r; i++) {
        ans[i] = currMax;
        if (nums[i] < nextRightMin) {
            nextRightMin = nums[i];
        }
    }

    if (pivotIndex == 0) {
        return;
    }

    process(nums, ans, prevMax, pivotIndex - 1, nextRightMin, currMax);
}

int* maxValue(int* nums, int numsSize, int* returnSize) {
    int* ans = (int*)malloc(numsSize * sizeof(int));
    memset(ans, 0, numsSize * sizeof(int));
    Item* prevMax = (Item*)malloc(numsSize * sizeof(Item));

    Item prev = {INT_MIN, -1};
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > prev.value) {
            prev.value = nums[i];
            prev.index = i;
        }
        prevMax[i] = prev;
    }

    process(nums, ans, prevMax, numsSize - 1, INT_MAX, 0);

    free(prevMax);
    *returnSize = numsSize;
    return ans;
}
