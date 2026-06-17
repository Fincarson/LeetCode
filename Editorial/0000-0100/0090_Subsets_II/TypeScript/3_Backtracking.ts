function subsetsWithDup(nums: number[]): number[][] {
    nums.sort((a, b) => a - b);
    const subsets: number[][] = [];
    const currentSubset: number[] = [];
    (function subsetsWithDupHelper(
        subsets: number[][],
        currentSubset: number[],
        nums: number[],
        index: number,
    ) {
        // Add the subset formed so far to the subsets list.
        subsets.push([...currentSubset]);
        for (let i = index; i < nums.length; i++) {
            // If the current element is a duplicate, ignore.
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            currentSubset.push(nums[i]);
            subsetsWithDupHelper(subsets, currentSubset, nums, i + 1);
            currentSubset.pop();
        }
    })(subsets, currentSubset, nums, 0);
    return subsets;
}
