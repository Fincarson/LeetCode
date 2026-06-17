class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        # Sort the numbers using Quick Sort
        self._quick_sort(nums, 0, len(nums) - 1)
        # Concatenate sorted numbers to form the largest number
        largest_num = "".join(map(str, nums))
        # Handle the case where the largest number is zero
        return "0" if largest_num[0] == "0" else largest_num

    def _quick_sort(self, nums: List[int], left: int, right: int) -> None:
        # Base case: if the range has one or no elements, it is already sorted
        if left >= right:
            return

        # Partition the array and get the pivot index
        pivot_index = self._partition(nums, left, right)

        # Recursively sort the sub-arrays
        self._quick_sort(nums, left, pivot_index - 1)
        self._quick_sort(nums, pivot_index + 1, right)

    def _partition(self, nums: List[int], left: int, right: int) -> int:
        pivot = nums[right]
        low_index = left

        # Rearrange elements so that those greater than the pivot are on the left
        for i in range(left, right):
            if self._compare(nums[i], pivot):
                nums[i], nums[low_index] = nums[low_index], nums[i]
                low_index += 1

        # Place the pivot in its correct position
        nums[low_index], nums[right] = nums[right], nums[low_index]
        return low_index

    def _compare(self, first_num: int, second_num: int) -> bool:
        # Compare concatenated strings to decide the order
        return str(first_num) + str(second_num) > str(second_num) + str(
            first_num
        )
