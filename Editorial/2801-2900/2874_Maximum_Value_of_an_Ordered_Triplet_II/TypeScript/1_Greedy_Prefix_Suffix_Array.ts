function maximumTripletValue(nums: number[]): number {
    const n = nums.length;
    const leftMax: number[] = new Array(n).fill(0);
    const rightMax: number[] = new Array(n).fill(0);
    for (let i = 1; i < n; i++) {
        leftMax[i] = Math.max(leftMax[i - 1], nums[i - 1]);
        rightMax[n - 1 - i] = Math.max(rightMax[n - i], nums[n - i]);
    }
    let res = 0;
    for (let j = 1; j < n - 1; j++) {
        res = Math.max(res, (leftMax[j] - nums[j]) * rightMax[j]);
    }
    return res;
}
