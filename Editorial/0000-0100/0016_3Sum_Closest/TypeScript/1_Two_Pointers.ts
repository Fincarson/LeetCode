function threeSumClosest(nums: number[], target: number): number {
    let diff = Number.MAX_SAFE_INTEGER;
    nums.sort((a, b) => a - b);
    for (let i = 0; i < nums.length && diff != 0; ++i) {
        let lo = i + 1;
        let hi = nums.length - 1;
        while (lo < hi) {
            let sum = nums[i] + nums[lo] + nums[hi];
            if (Math.abs(target - sum) < Math.abs(diff)) {
                diff = target - sum;
            }
            if (sum < target) {
                ++lo;
            } else {
                --hi;
            }
        }
    }
    return target - diff;
}
