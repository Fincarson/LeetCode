enum Index {
    GOOD,
    BAD,
    UNKNOWN,
}
function canJump(nums: number[]): boolean {
    let memo: Index[] = Array(nums.length).fill(Index.UNKNOWN);
    memo[memo.length - 1] = Index.GOOD;
    for (let i = nums.length - 2; i >= 0; i--) {
        let furthestJump: number = Math.min(i + nums[i], nums.length - 1);
        for (let j = i + 1; j <= furthestJump; j++) {
            if (memo[j] == Index.GOOD) {
                memo[i] = Index.GOOD;
                break;
            }
        }
    }
    return memo[0] == Index.GOOD;
}
