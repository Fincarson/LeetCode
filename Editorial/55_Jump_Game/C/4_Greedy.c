bool canJump(int* nums, int numsSize) {
    int lastPos = numsSize - 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        if (i + nums[i] >= lastPos) {
            lastPos = i;
        }
    }
    return lastPos == 0;
}
