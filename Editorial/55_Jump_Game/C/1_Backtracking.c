bool canJumpFromPosition(int position, int* nums, int numsSize) {
    if (position == numsSize - 1) {
        return true;
    }
    int furthestJump = position + nums[position] < numsSize - 1
                           ? position + nums[position]
                           : numsSize - 1;
    for (int nextPosition = position + 1; nextPosition <= furthestJump;
         ++nextPosition) {
        if (canJumpFromPosition(nextPosition, nums, numsSize)) {
            return true;
        }
    }
    return false;
}
bool canJump(int* nums, int numsSize) {
    return canJumpFromPosition(0, nums, numsSize);
}
