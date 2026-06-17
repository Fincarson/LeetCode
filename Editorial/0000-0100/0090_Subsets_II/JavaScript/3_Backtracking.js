var subsetsWithDup = function (nums) {
    nums.sort((a, b) => a - b);
    const subsets = [];
    const currentSubset = [];
    (function subsetsWithDupHelper(subsets, currentSubset, nums, index) {
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
};
