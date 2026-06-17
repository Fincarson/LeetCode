function solveQueries(nums: number[], queries: number[]): number[] {
    const n = nums.length;
    const left = new Array(n);
    const right = new Array(n);
    const pos = new Map<number, number>();

    for (let i = -n; i < n; i++) {
        if (i >= 0) {
            left[i] = pos.has(nums[i]) ? pos.get(nums[i])! : -n;
        }
        pos.set(nums[(i + n) % n], i);
    }

    pos.clear();
    for (let i = 2 * n - 1; i >= 0; i--) {
        if (i < n) {
            right[i] = pos.has(nums[i]) ? pos.get(nums[i])! : 2 * n;
        }
        pos.set(nums[i % n], i);
    }

    for (let i = 0; i < queries.length; i++) {
        const x = queries[i];
        if (x - left[x] === n) {
            queries[i] = -1;
        } else {
            queries[i] = Math.min(x - left[x], right[x] - x);
        }
    }

    return queries;
}
