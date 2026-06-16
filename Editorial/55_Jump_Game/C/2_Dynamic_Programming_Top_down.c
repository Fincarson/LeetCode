enum Index { GOOD, BAD, UNKNOWN };
int canJumpFromPosition(int position, int* nums, int numsSize,
                        enum Index* memo) {
    if (memo[position] != UNKNOWN) {
        return memo[position] == GOOD ? 1 : 0;
    }
    int furthestJump = (position + nums[position] < numsSize - 1)
                           ? position + nums[position]
                           : numsSize - 1;
    for (int nextPosition = position + 1; nextPosition <= furthestJump;
         nextPosition++) {
        if (canJumpFromPosition(nextPosition, nums, numsSize, memo)) {
            memo[position] = GOOD;
            return 1;
        }
    }
    memo[position] = BAD;
    return 0;
}
int canJump(int* nums, int numsSize) {
    enum Index* memo = (enum Index*)malloc(numsSize * sizeof(enum Index));
    for (int i = 0; i < numsSize; i++) memo[i] = UNKNOWN;
    memo[numsSize - 1] = GOOD;
    return canJumpFromPosition(0, nums, numsSize, memo);
}
