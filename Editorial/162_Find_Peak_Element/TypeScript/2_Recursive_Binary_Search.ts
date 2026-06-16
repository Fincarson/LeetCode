function findPeakElement(nums: number[]): number {
    return search(nums, 0, nums.length - 1);
}

function search(nums: number[], l: number, r: number): number {
    if (l == r) return l;
    let mid = Math.floor((l + r) / 2);
    if (nums[mid] > nums[mid + 1]) return search(nums, l, mid);
    return search(nums, mid + 1, r);
}
