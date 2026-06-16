int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    // Find the index of the pivot element (the smallest element)
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[numsSize - 1]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return shiftedBinarySearch(nums, numsSize, left, target);
}
// Shift elements in a circular manner, with the pivot element at index 0.
// Then perform a regular binary search
int shiftedBinarySearch(int* nums, int numsSize, int pivot, int target) {
    int shift = numsSize - pivot;
    int left = (pivot + shift) % numsSize;
    int right = (pivot - 1 + shift) % numsSize;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[(mid - shift + numsSize) % numsSize] == target) {
            return (mid - shift + numsSize) % numsSize;
        } else if (nums[(mid - shift + numsSize) % numsSize] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}
