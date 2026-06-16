class Solution:
    def divideArray(self, nums: List[int]) -> bool:
        # Count frequency of each number using Counter
        frequency = Counter(nums)

        # Check if each number appears even number of times
        return all(count % 2 == 0 for count in frequency.values())
