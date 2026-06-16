class Solution:
    def distinctNumbers(self, nums: List[int], k: int) -> List[int]:
        len_nums = len(nums)
        answer = [0] * (len_nums - k + 1)

        # Track frequency of numbers in current window
        freq = {}

        # Process first window
        for num in nums[:k]:
            freq[num] = freq.get(num, 0) + 1
        answer[0] = len(freq)

        # Slide window and update counts
        for pos in range(k, len_nums):
            # Remove leftmost element
            left = nums[pos - k]
            freq[left] -= 1
            if freq[left] == 0:
                del freq[left]

            # Add rightmost element
            right = nums[pos]
            freq[right] = freq.get(right, 0) + 1

            answer[pos - k + 1] = len(freq)

        return answer
