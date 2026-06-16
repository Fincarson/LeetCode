typedef enum Index { GOOD, BAD, UNKNOWN } Index;
bool canJump(int* nums, int numsSize) {
    Index* memo = (Index*)malloc(numsSize * sizeof(Index));
    for (int i = 0; i < numsSize; i++) {
        memo[i] = UNKNOWN;
    }
    memo[numsSize - 1] = GOOD;
    for (int i = numsSize - 2; i >= 0; i--) {
        int furthestJump =
            (i + nums[i] < numsSize - 1) ? i + nums[i] : numsSize - 1;
        for (int j = i + 1; j <= furthestJump; j++) {
            if (memo[j] == GOOD) {
                memo[i] = GOOD;
                break;
            }
        }
    }
    return memo[0] == GOOD;
}
