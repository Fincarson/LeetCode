int findBound(int* nums, int numsSize, int target, int isFirst) {
    int begin = 0, end = numsSize - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (nums[mid] == target) {
            if (isFirst) {
                if (mid == begin || nums[mid - 1] != target) {
                    return mid;
                }
                end = mid - 1;
            } else {
                if (mid == end || nums[mid + 1] != target) {
                    return mid;
                }
                begin = mid + 1;
            }
        } else if (nums[mid] > target) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(sizeof(int) * 2);
    int firstOccurrence = findBound(nums, numsSize, target, 1);
    if (firstOccurrence == -1) {
        result[0] = -1;
        result[1] = -1;
        *returnSize = 2;
        return result;
    }
    int lastOccurrence = findBound(nums, numsSize, target, 0);
    result[0] = firstOccurrence;
    result[1] = lastOccurrence;
    *returnSize = 2;
    return result;
}
