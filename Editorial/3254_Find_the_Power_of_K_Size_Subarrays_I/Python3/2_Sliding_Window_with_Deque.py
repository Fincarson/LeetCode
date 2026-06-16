class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        length = len(nums)
        result = [-1] * (length - k + 1)
        index_deque = collections.deque()

        for current_index in range(length):
            # Remove elements that are out of the window
            if index_deque and index_deque[0] < current_index - k + 1:
                index_deque.popleft()
            # Check if current element breaks the consecutive and sorted condition
            if (
                index_deque
                and nums[current_index] != nums[current_index - 1] + 1
            ):
                index_deque.clear()  # Invalidate the entire deque if condition breaks

            # Add current element index to the deque
            index_deque.append(current_index)

            # Check if the window is of size k and update result
            if current_index >= k - 1:
                if len(index_deque) == k:  # Valid window of size k
                    result[current_index - k + 1] = nums[index_deque[-1]]
                else:
                    result[current_index - k + 1] = -1  # Not valid, return -1

        return result
