function minimumCost(nums: number[]): number {
    let first: number = Number.MAX_SAFE_INTEGER;
    let second: number = Number.MAX_SAFE_INTEGER;

    for (let i = 1; i < nums.length; i++) {
        const x: number = nums[i];
        if (x < first) {
            second = first;
            first = x;
        } else if (x < second) {
            second = x;
        }
    }
    return nums[0] + first + second;
}
