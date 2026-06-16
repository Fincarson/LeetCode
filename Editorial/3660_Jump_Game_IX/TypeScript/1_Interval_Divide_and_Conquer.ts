type Item = [number, number]; // [value, index]

function maxValue(nums: number[]): number[] {
    const n = nums.length;
    const ans = new Array<number>(n).fill(0);

    const prevMax: Item[] = new Array(n);

    nums.reduce(
        (prev, value, index) => {
            if (value > prev[0]) {
                prev = [value, index];
            }
            return (prevMax[index] = [...prev]);
        },
        [-Infinity, -1] as Item,
    );

    const process = (r: number, rightMin: number, rightMax: number) => {
        const [pMax, pivotIndex] = prevMax[r];
        const currMax = pMax <= rightMin ? pMax : rightMax;

        let nextRightMin = Math.min(pMax, rightMin);
        for (let i = pivotIndex; i <= r; i++) {
            ans[i] = currMax;
            nextRightMin = Math.min(nextRightMin, nums[i]);
        }

        if (pivotIndex === 0) {
            return;
        }

        process(pivotIndex - 1, nextRightMin, currMax);
    };

    process(n - 1, Infinity, 0);

    return ans;
}
