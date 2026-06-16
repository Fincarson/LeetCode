class Solution:
    def subsetsWithDup(self, nums):
        nums.sort()
        subsets = []
        currentSubset = []
        self.subsetsWithDupHelper(subsets, currentSubset, nums, 0)
        return subsets

    def subsetsWithDupHelper(self, subsets, currentSubset, nums, index):
        # Add the subset formed so far to the subsets list.
        subsets.append(list(currentSubset))
        for i in range(index, len(nums)):
            # If the current element is a duplicate, ignore.
            if i != index and nums[i] == nums[i - 1]:
                continue
            currentSubset.append(nums[i])
            self.subsetsWithDupHelper(subsets, currentSubset, nums, i + 1)
            currentSubset.pop()
