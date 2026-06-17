function countGood(nums: number[], k: number): number {
    const n = nums.length;
    let same = 0,
        right = -1;
    const cnt = new Map<number, number>();
    let ans = 0;
    for (let left = 0; left < n; ++left) {
        while (same < k && right + 1 < n) {
            ++right;
            same += cnt.get(nums[right]) || 0;
            cnt.set(nums[right], (cnt.get(nums[right]) || 0) + 1);
        }
        if (same >= k) {
            ans += n - right;
        }
        cnt.set(nums[left], (cnt.get(nums[left]) || 0) - 1);
        same -= cnt.get(nums[left]) || 0;
    }
    return ans;
}
