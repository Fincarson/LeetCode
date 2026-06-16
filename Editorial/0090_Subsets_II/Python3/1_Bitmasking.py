class Solution:
    def subsetsWithDup(self, nums):
        n = len(nums)
        # Sort the generated subset. This will help to identify duplicates.
        nums.sort()
        maxNumberOfSubsets = 2**n
        # To store the previously seen sets.
        seen = set()
        subsets = []
        for subsetIndex in range(maxNumberOfSubsets):
            # Append subset corresponding to that bitmask.
            currentSubset = []
            hashcode = ""
            for j in range(n):
                # Generate the bitmask
                mask = 2**j
                isSet = mask & subsetIndex
                if isSet != 0:
                    currentSubset.append(nums[j])
                    # Generate the hashcode by creating a comma separated string of numbers in the currentSubset.
                    hashcode += str(nums[j]) + ","
            if hashcode not in seen:
                subsets.append(currentSubset)
                seen.add(hashcode)
        return subsets
