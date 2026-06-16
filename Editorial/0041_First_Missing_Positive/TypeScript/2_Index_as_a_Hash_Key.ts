function firstMissingPositive(nums: number[]): number {
    let contains1 = false;
    let n = nums.length;
    for (let i = 0; i < n; i++) {
        if (nums[i] === 1) {
            contains1 = true;
        }
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = 1;
        }
    }
    if (!contains1) return 1;
    for (let i = 0; i < n; i++) {
        let value = Math.abs(nums[i]);
        if (value === n) {
            nums[0] = -Math.abs(nums[0]);
        } else {
            nums[value] = -Math.abs(nums[value]);
        }
    }
    for (let i = 1; i < n; i++) {
        if (nums[i] > 0) return i;
    }
    if (nums[0] > 0) return n;
    return n + 1;
}
