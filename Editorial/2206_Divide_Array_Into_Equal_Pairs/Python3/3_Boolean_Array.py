class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        # Find maximum value in array
        max_num = max(nums)

        # Toggle pair status for each number
        needs_pair = [False] * (max_num + 1)
        for num in nums:
            needs_pair[num] = not needs_pair[num]

        # Check if any number remains unpaired
        return not any(needs_pair[num] for num in nums)
