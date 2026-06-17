function minMirrorPairDistance(nums: number[]): number {
    const reverseNum = (x: number): number => {
        let y = 0;
        while (x > 0) {
            y = y * 10 + (x % 10);
            x = Math.floor(x / 10);
        }
        return y;
    };

    const prev = new Map<number, number>();
    const n = nums.length;
    let ans = n + 1;

    for (let i = 0; i < n; i++) {
        const x = nums[i];
        if (prev.has(x)) {
            ans = Math.min(ans, i - prev.get(x)!);
        }
        prev.set(reverseNum(x), i);
    }

    return ans === n + 1 ? -1 : ans;
}
