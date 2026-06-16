class Solution:
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        # Find the maximum value in nums
        max_value = max(nums)

        # Create a frequency array based on the maximum value
        freq = [0] * (max_value + 1)
        distinct = 0
        answer = []

        for pos in range(len(nums)):
            # Add new number
            freq[nums[pos]] += 1
            if freq[nums[pos]] == 1:
                distinct += 1

            # Remove old number
            if pos >= k:
                freq[nums[pos - k]] -= 1
                if freq[nums[pos - k]] == 0:
                    distinct -= 1

            # Store result for complete window
            if pos + 1 >= k:
                answer.append(distinct)

        return answer
