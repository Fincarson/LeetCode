function majorityElement(nums: number[], lo = 0, hi = null): number {
    let majorityElementRec = (lo: number, hi: number) => {
        if (lo == hi) {
            return nums[lo];
        }

        let mid = Math.floor((hi - lo) / 2) + lo;
        let left = majorityElementRec(lo, mid);
        let right = majorityElementRec(mid + 1, hi);

        if (left == right) {
            return left;
        }

        let leftCount = 0;
        let rightCount = 0;
        for (let i = lo; i <= hi; i++) {
            if (nums[i] == left) {
                leftCount++;
            }
            if (nums[i] == right) {
                rightCount++;
            }
        }

        return leftCount > rightCount ? left : right;
    };

    return majorityElementRec(0, nums.length - 1);
}
