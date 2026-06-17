function findFinalValue(nums: number[], original: number): number {
    nums.sort((a, b) => a - b);
    for (const num of nums) {
        if (original === num) {
            original *= 2;
        }
    }
    return original;
}
