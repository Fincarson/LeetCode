function minimumCost(nums: number[]): number {
    nums = [nums[0], ...nums.slice(1).sort((a, b) => a - b)];
    return nums.slice(0, 3).reduce((sum, num) => sum + num, 0);
}
