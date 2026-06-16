class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        # Step 1: Sort the array
        arr.sort()

        for i in range(len(arr)):
            # Step 2: Calculate the target (double of current number)
            target = 2 * arr[i]
            # Step 3: Custom binary search for the target
            index = self._custom_binary_search(arr, target)
            # If the target exists and is not the same index
            if index >= 0 and index != i:
                return True
        # No valid pair found
        return False

    def _custom_binary_search(self, arr: List[int], target: int) -> int:
        left, right = 0, len(arr) - 1

        while left <= right:
            # Avoid potential overflow
            mid = left + (right - left) // 2

            if arr[mid] == target:
                return mid
            elif arr[mid] < target:
                left = mid + 1
            else:
                right = mid - 1

        return -1  # Target not found
