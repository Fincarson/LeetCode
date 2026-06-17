class Solution:
    def subsetsWithDup(self, nums):
        nums.sort()
        subsets = [[]]
        subsetSize = 0
        for i in range(len(nums)):
            # subsetSize refers to the size of the subset in the previous step.
            # This value also indicates the starting index of the subsets generated in this step.
            startingIndex = (
                subsetSize if i >= 1 and nums[i] == nums[i - 1] else 0
            )
            subsetSize = len(subsets)
            for j in range(startingIndex, subsetSize):
                currentSubset = list(subsets[j])
                currentSubset.append(nums[i])
                subsets.append(currentSubset)
        return subsets
